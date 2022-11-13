#include "GlobalDefines.hpp"
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "CommonTypes.hpp"
#include "VE.Direct.hpp"
#include "Screens.hpp"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

String inputString = "";     // a String to hold incoming data
bool blockComplete = false;  // whether the block of data is complete

static DataField *dataFieldPointers [22];
static VictronParameterMenuItem *victronSubMenuItems [22];
static VictronProduct *victronProduct;
static UIStringUInt8Id *productGroup;
static IBaseScreen* currentScreen = nullptr;

static uint16_t currentAnalogButtonValue = 65535;
static Button currentButton = notPressed;
static unsigned long lastDebounceTime = 0;
static unsigned long debounceDelay = 100; // ms

/* Function definitions */
byte calcChecksum(String input);
void parseBlock(String input);
bool updateVictronProductInfo();
void processButtons();

/* IMPLEMENTATION */

void onScreenChange(IBaseScreen* nextScreen) {
  currentScreen = nextScreen;
  currentScreen->setNeedRender();
}

Button getButton(uint16_t adcValue) {
  if (adcValue < 60) {
    return right;
  } else if (adcValue < 200) {
    return up;
  } else if (adcValue < 400){
    return down;
  } else if (adcValue < 600){
    return left;
  } else if (adcValue < 800){
    return select;
  }

  return notPressed;
}

/* ====================== SETUP ===================== */
void setup() {
  // LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Energy Monitor"));
  lcd.setCursor(0, 1);
  lcd.print("v1.0.0");

  // Buttons pin
  pinMode(A0, INPUT); 

  #ifdef DEBUG
  Serial.begin(115200); // debug over USB serial
  #endif

  // Creating menu hierarchy
  victronDeviceMenuItem = new VictronDeviceMenuItem(&lcd);
  pylontechBatteryMenuItem = new PylontechBatteryMenuItem(&lcd);

  victronDeviceMenuItem->onScreenChange = onScreenChange;
  pylontechBatteryMenuItem->onScreenChange = onScreenChange;

  victronDeviceMenuItem->nextScreen = pylontechBatteryMenuItem;
  victronDeviceMenuItem->previousScreen = pylontechBatteryMenuItem;
  pylontechBatteryMenuItem->nextScreen = victronDeviceMenuItem;
  pylontechBatteryMenuItem->previousScreen = victronDeviceMenuItem;

  // Set current screen 
  currentScreen = victronDeviceMenuItem;

  // Serial connection to Victron device
  Serial1.begin(19200);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

/* ====================== LOOP ===================== */
void loop() {
  // Process block from Victron Device
  if (blockComplete) {
    byte checksum = calcChecksum(inputString);
    
    #ifdef DEBUG
    //Serial.println(inputString);
    Serial.print(F("Block "));
    Serial.println(checksum ? F("Corrupted"): F("Ok"));
    #endif
    
    // parse block:
    if (checksum == 0) {
      parseBlock(inputString);
    }

    // clear the string:
    inputString = "";
    blockComplete = false;

    // update product info data structures
    if(updateVictronProductInfo()){
      if(currentScreen == victronDeviceMenuItem) {
        victronDeviceMenuItem->victronProduct = victronProduct;
        victronDeviceMenuItem->productGroup = productGroup;
        victronDeviceMenuItem->setNeedRender();
      }
    }

    // If current displayed screen is Victron parameter screen - refresh it
    if (currentScreen != nullptr) {
      if(currentScreen->selectedScreen == victronDeviceMenuItem) {
        currentScreen->setNeedRender();
      }
    }
  }

  // Update UI
  // Process buttons
  processButtons();

  // Page Renderer
  if(currentScreen != nullptr) {
    if(!currentScreen->isRendered()){
      currentScreen->render();
    }
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent1() {
  while (Serial1.available()) {
    // get the new byte:
    char inChar = (char)Serial1.read();
    // add it to the inputString:
    inputString += inChar;

    int checksumIndex = inputString.lastIndexOf(F("Checksum"));
    if(checksumIndex != -1 && (inputString.length() - 9 - 2 == (unsigned int)checksumIndex)) {
      blockComplete = true;
    }
  }
}

// Checksum should be 0
byte calcChecksum(String input) {
  uint8_t checksum = 0;
  for (unsigned int i = 0; i < input.length(); i++) {
    checksum += input.charAt(i);
  }
  
  return (checksum);
}

// Parsing of the data block, received from the Victron device
void parseBlock(String input) {
  int fromIndex = 0;

  while(true) {
    int startIndex = input.indexOf(0x0A, fromIndex); // line feed
    if(startIndex == -1) { 
      #ifdef DEBUG
      Serial.println(F("[!]Start Index not found"));
      #endif
      return; 
    }
    
    int endIndex = input.indexOf(0x0D, startIndex); // carriage return '\n'
    if(endIndex == -1) { 
      #ifdef DEBUG
      Serial.println(F("[!]End Index not found"));
      #endif
      return; 
    }
    
    fromIndex = endIndex;
    
    String field = input.substring(startIndex, endIndex);
    int tabIndex = field.indexOf(0x09); // tab
    if(tabIndex == -1) { 
      #ifdef DEBUG
      Serial.println(F("[!]Tab Index not found"));
      #endif
      return; 
    }
    
    String fieldLabel = field.substring(1, tabIndex);
    if(fieldLabel == F("Checksum")) {
      return;  
    }

    String fieldValue = field.substring(tabIndex + 1, field.length());
    char fielLabelCharArr[9];
    fieldLabel.toCharArray(fielLabelCharArr, 9);    
    char fieldValueCharArray[33];
    fieldValue.toCharArray(fieldValueCharArray, 33);

    int firstIndexWithNull = -1;
    bool shouldContinue = false;

    for (int i = 0; i < 22; i++) {
      if(dataFieldPointers[i]) {  
        if(strcmp(dataFieldPointers[i]->label, fielLabelCharArr) == 0) {
          // update value
          strcpy(dataFieldPointers[i]->originalValue, fieldValueCharArray);
          shouldContinue = true;
          break;
        }
      } else {
        firstIndexWithNull = i;
        break;  
      }
    }

    if (shouldContinue) { 
      continue; // continue while from here
    }  

    if(firstIndexWithNull == -1) {
      #ifdef DEBUG
      Serial.println(F("[!]Free slot not found"));
      #endif
      return;  
    }

    // Find index of the data field label
    int dataFieldIndex = getDataFieldIndex(fielLabelCharArr);
    if(dataFieldIndex == -1) { return; }

    // Creating new data field
    DataField *newDataField = getDataField(dataFieldIndex);
    strcpy(newDataField->originalValue, fieldValueCharArray);
    dataFieldPointers[firstIndexWithNull] = newDataField;

    // Creating Victron sub-menu item for this parameter
    VictronParameterMenuItem *subMenuItem = new VictronParameterMenuItem(&lcd);
    subMenuItem->dataField = newDataField;

    if(firstIndexWithNull == 0) {
      victronDeviceMenuItem->selectedScreen = subMenuItem;
    } else {
      subMenuItem->previousScreen = victronSubMenuItems[firstIndexWithNull - 1];
      victronSubMenuItems[firstIndexWithNull - 1]->nextScreen = subMenuItem;
    }
    
    subMenuItem->selectedScreen = victronDeviceMenuItem;
    subMenuItem->onScreenChange = onScreenChange;
    victronSubMenuItems[firstIndexWithNull] = subMenuItem;

    #ifdef DEBUG
    Serial.print(F("New Field: "));
    Serial.print(newDataField->label);
    Serial.print(F(" at: "));
    Serial.println(firstIndexWithNull);
    #endif
  }
}

// Load Victron product info
bool updateVictronProductInfo() {
  if(victronProduct && productGroup) { return false; }
  
  for (int i = 0; i < 22; i++) {
    if(dataFieldPointers[i]) {  
      if(strcmp(dataFieldPointers[i]->label, dataFieldsIndex[50]) == 0) { // Searching for PID data field
        uint16_t intPID;
        sscanf(dataFieldPointers[i]->originalValue, "%x", &intPID); // hex string to uint16_t

        #ifdef DEBUG
        Serial.print(F("Found PID: "));
        Serial.println(intPID);
        #endif

        // Product
        int productIndex = getProductIndex(intPID);
        if(productIndex == -1) { return false; }

        victronProduct = getProduct(productIndex);

        #ifdef DEBUG
        Serial.print(F("Product: "));
        Serial.println(victronProduct->uiLabel);
        #endif

        // Product group
        int groupIndex = getProductGroupIndex(victronProduct->group);
        if(groupIndex == -1) { return false; }

        productGroup = getProductGroup(groupIndex);

        #ifdef DEBUG
        Serial.print(F("Group: "));
        Serial.println(productGroup->uiLabel);
        #endif
        
        return true;
      }
    }
  }

  return false;
}

// Process Buttons
void processButtons() {
  if ((millis() - lastDebounceTime) > debounceDelay) {
    uint16_t buttonAnalogValue = analogRead(A0);    
    Button pressedButton = getButton(buttonAnalogValue);
    // if the button state has changed:
    if (pressedButton != currentButton) {
      currentButton = pressedButton;

      #ifdef DEBUG
      Serial.print(F("Button: "));
      Serial.println(currentButton);
      #endif  

      if(currentScreen != nullptr) {
        currentScreen->processInput(currentButton);
      }
    }

    lastDebounceTime = millis();
    currentAnalogButtonValue = buttonAnalogValue;
  }
}
