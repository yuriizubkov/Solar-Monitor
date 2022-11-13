#include "VictronParameterMenuItem.hpp"

void VictronParameterMenuItem::processInput(Button buttonPressed) {
  switch(buttonPressed) {
    case up:
      if(this->previousScreen != nullptr && this->onScreenChange != nullptr) { this->onScreenChange(this->previousScreen); }
      break;
    case down:
      if(this->nextScreen != nullptr && this->onScreenChange != nullptr) { this->onScreenChange(this->nextScreen); }
      break;
    case right:
      break;
    case left: 
      break;
    case select:
      if(this->selectedScreen != nullptr && this->onScreenChange != nullptr) { this->onScreenChange(this->selectedScreen); }
      break;
    default:
      break;
  }
}

bool VictronParameterMenuItem::parseSpecialCases(char *dataFieldLabel, int32_t value, char* parsedString, int parsedStringLength) {
  if(strcmp(dataFieldLabel, dataFieldsIndex[46]) == 0) { // CS - State of operation
    int csLabelIndex = getStateOfOperationIndex((uint8_t)value);
    if(csLabelIndex == -1) { return false; } // better show numerical value if label not found

    UIStringUInt8Id *csLabel = getStateOfOperation(csLabelIndex);
    strncpy(parsedString, csLabel->uiLabel, parsedStringLength);
    delete csLabel; // we don't need this struct in memory anymore

    return true;
  } else if (strcmp(dataFieldLabel, dataFieldsIndex[58]) == 0) { // MPPT state
    int mpptLabelIndex = getMPPTStateIndex((uint8_t)value);
    if(mpptLabelIndex == -1) { return false; } // better show numerical value if label not found

    UIStringUInt8Id *mpptLabel = getStateOfOperation(mpptLabelIndex);
    strncpy(parsedString, mpptLabel->uiLabel, parsedStringLength);
    delete mpptLabel; // we don't need this struct in memory anymore

    return true;
  } else if(strcmp(dataFieldLabel, dataFieldsIndex[45]) == 0) { // Error code
    int errorIndex = getErrorIndex((uint8_t)value);
    if(errorIndex == -1) { return false; } // better show numerical value if label not found

    UIStringUInt8Id *errorLabel = getError(errorIndex);
    strncpy(parsedString, errorLabel->uiLabel, parsedStringLength);
    delete errorLabel; // we don't need this struct in memory anymore

    return true;
  } else if(strcmp(dataFieldLabel, dataFieldsIndex[21]) == 0) { // OR - Off reasons
    // Could be more than one rteason - bitmap
    // Store current displayed OR
    // On the next refresh - display next OR and store its index
    unsigned long sizeOfArray = sizeof(offReasonsIndex)/sizeof(offReasonsIndex[0]);
    unsigned long numberOfIterations = sizeOfArray;

    while(numberOfIterations > 0) {
      if(nextIndexToShow >= sizeOfArray) { nextIndexToShow = 0; }

      if ((offReasonsIndex[nextIndexToShow] & (uint32_t)value) == offReasonsIndex[nextIndexToShow]) { // if value bitmap contains reason id
        UIStringUInt32Id *offReason = getOffReason(nextIndexToShow);
        strncpy(parsedString, offReason->uiLabel, parsedStringLength);
        delete offReason;
        nextIndexToShow++;
        
        return true;
      } else {
        numberOfIterations--;
        nextIndexToShow++;
      }      
    }
    
    return false;
  }

  return false;
}

void VictronParameterMenuItem::valueToString(DataField *dataField, char *parsedString, int parsedStringLength) {
  switch(dataField->valueParser) {
    case decU8bit: {
        uint8_t value = (uint8_t)strtol(dataField->originalValue, nullptr, 0);
        if(!parseSpecialCases(dataField->label, value, parsedString, parsedStringLength)) {
          float fValue = value * dataField->valueMultiplier;        
          dtostrf(fValue, 1, dataField->valuePrecision, parsedString);
        }
      }
      break;
    case decU16bit: {
        uint16_t value = (uint16_t)strtol(dataField->originalValue, nullptr, 0);
        if(!parseSpecialCases(dataField->label, value, parsedString, parsedStringLength)) {
          float fValue = value * dataField->valueMultiplier;        
          dtostrf(fValue, 1, dataField->valuePrecision, parsedString);
        }
      }
      break;
    case hex32bit: {
        uint32_t value = (uint32_t)strtol(dataField->originalValue, nullptr, 16);
        if(!parseSpecialCases(dataField->label, value, parsedString, parsedStringLength)) {
          strncpy(parsedString, dataField->originalValue, parsedStringLength);
        }
      }
      break;
    default: // Text, TextOnOf
      strncpy(parsedString, dataField->originalValue, parsedStringLength); // no more than 16 chars
      break; 
  }

  // Replacing all \0 with 0x20. Do you know better sollution? Please create an issue.
  for(int i = 0; i < parsedStringLength - 1; i++) {
    if(parsedString[i] == 0) {
      parsedString[i] = 0x20;
    }
  }

  // Last char \0
  parsedString[parsedStringLength - 1] = 0;

  // Adding units to the end of the string
  int unitStrLen = strlen(dataField->uiUnits); // number of chars to the first null-byte  
  int startIndex = (parsedStringLength - unitStrLen) - 1;
  if(unitStrLen != 0) {
    memcpy(parsedString + startIndex, dataField->uiUnits, unitStrLen);
  }
}

void VictronParameterMenuItem::render() {
  this->_display->clear();
  if(this->dataField != nullptr) {
    // Field Label
    this->_display->setCursor(0, 0);
    this->_display->print(this->dataField->uiLabel);

    // Value Parsing
    char parsedValue[17] = {0x20}; // all spaces
    this->valueToString(this->dataField, parsedValue, 17);

    // Field Value
    this->_display->setCursor(0, 1);
    this->_display->print(parsedValue);
  }

  this->_isRendered = true;
}