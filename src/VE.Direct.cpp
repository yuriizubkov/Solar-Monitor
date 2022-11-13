#include "VE.Direct.hpp"

/// @brief Find index of the PID
/// @param byPID 
/// @return Integer index from the index table
int getProductIndex(uint16_t byPID) {
  int productIndex = -1;
  for(unsigned int c = 0; c < (sizeof(pidIndex) / sizeof(pidIndex[0])); c++) {
    if(pidIndex[c] == byPID) {
      productIndex = c;
      break;
    }
  }

  #ifdef DEBUG
  if (productIndex == -1) {
    Serial.print(F("[!]PID not found: "));
    Serial.println(byPID);
  }
  #endif

  return productIndex;
}

/// @brief Load VictronProduct from the PROGMEM
/// @param atIndex 
/// @return Pointer to the new created struct
VictronProduct *getProduct(int atIndex) {
  VictronProduct *victronProduct = new struct VictronProduct;
  memcpy_P(victronProduct, &victronProducts[atIndex], sizeof(VictronProduct));
  return victronProduct;
}

/// @brief Find index of the UIStringUInt8Id - Group label
/// @param byGroupId 
/// @return Integer index from the index table
int getProductGroupIndex(int byGroupId) {
  int groupIndex = -1;
  for(unsigned int m = 0; m < (sizeof(productGroupsIndex) / sizeof(productGroupsIndex[0])); m++) {
    if(byGroupId == productGroupsIndex[m]) {
      groupIndex = m;
      break;
    }
  }

  #ifdef DEBUG
  if (groupIndex == -1) {
    Serial.print(F("[!]Group index not found: "));
    Serial.println(groupIndex);
  }
  #endif

  return groupIndex;
}

/// @brief Load UIStringUInt8Id Product Group from the PROGMEM
/// @param atIndex 
/// @return Pointer to the new created struct
UIStringUInt8Id *getProductGroup(int atIndex) {
  UIStringUInt8Id *productGroup = new struct UIStringUInt8Id;
  memcpy_P(productGroup, &productGroupsLabels[atIndex], sizeof(UIStringUInt8Id));
  return productGroup;
}

/// @brief Find index of data field label
/// @param fieldLabel 
/// @return Integer index from the index table
int getDataFieldIndex(char *fieldLabel) {
  int dataFieldIndex = -1;
  for(unsigned int c = 0; c < (sizeof(dataFieldsIndex) / sizeof(dataFieldsIndex[0])); c++) {
    if(strcmp(dataFieldsIndex[c], fieldLabel) == 0) {
      dataFieldIndex = c;
      break;
    }
  }

  #ifdef DEBUG
  if(dataFieldIndex == -1) { 
    Serial.print(F("[!]Field Index not found: "));
    Serial.println(fieldLabel);
  }
  #endif

  return dataFieldIndex;
}

/// @brief Load DataField from the PROGMEM
/// @param atIndex 
/// @return Pointer to the new created struct
DataField *getDataField(int atIndex) {
  DataField *dataField = new struct DataField;
  memcpy_P(dataField, &dataFields[atIndex], sizeof(DataField));
  return dataField;
}

/// @brief Find index of the state of operation (CS) label
/// @param byID 
/// @return Integer index from the index table
int getStateOfOperationIndex(uint8_t byID) {
  int csIndex = -1;
  for(unsigned int c = 0; c < (sizeof(stateOfOperationIndex) / sizeof(stateOfOperationIndex[0])); c++) {
    if(stateOfOperationIndex[c] == byID) {
      csIndex = c;
      break;
    }
  }

  #ifdef DEBUG
  if(csIndex == -1) { 
    Serial.print(F("[!]CS Index not found: "));
    Serial.println(byID);
  }
  #endif

  return csIndex;
}

/// @brief Load UIStringUInt8Id - State of operation from the PROGMEM
/// @param atIndex 
/// @return Pointer to the new created struct
UIStringUInt8Id *getStateOfOperation(int atIndex) {
  UIStringUInt8Id *cs = new struct UIStringUInt8Id;
  memcpy_P(cs, &stateOfOperationLabels[atIndex], sizeof(UIStringUInt8Id));
  return cs;
}

/// @brief Find index of the MPPT state label
/// @param byID 
/// @return Integer index from the index table
int getMPPTStateIndex(uint8_t byID) {
  int mpptIndex = -1;
  for(unsigned int c = 0; c < (sizeof(mpptStatesIndex) / sizeof(mpptStatesIndex[0])); c++) {
    if(mpptStatesIndex[c] == byID) {
      mpptIndex = c;
      break;
    }
  }

  #ifdef DEBUG
  if(mpptIndex == -1) { 
    Serial.print(F("[!]MPPT Index not found: "));
    Serial.println(byID);
  }
  #endif

  return mpptIndex;
}

/// @brief Load UIStringUInt8Id - MPPT State from the PROGMEM
/// @param atIndex 
/// @return Pointer to the new created struct
UIStringUInt8Id *getMPPTState(int atIndex) {
  UIStringUInt8Id *mpptState = new struct UIStringUInt8Id;
  memcpy_P(mpptState, &mpptStatesLabels[atIndex], sizeof(UIStringUInt8Id));
  return mpptState;
}

/// @brief Find index of the error label
/// @param byID 
/// @return Integer index from the index table
int getErrorIndex(uint8_t byID) {
  int errorIndex = -1;
  for(unsigned int c = 0; c < (sizeof(errorCodesIndex) / sizeof(errorCodesIndex[0])); c++) {
    if(errorCodesIndex[c] == byID) {
      errorIndex = c;
      break;
    }
  }

  #ifdef DEBUG
  if(errorIndex == -1) { 
    Serial.print(F("[!]Error Index not found: "));
    Serial.println(byID);
  }
  #endif

  return errorIndex;
}

/// @brief Load UIStringUInt8Id - Error label from the PROGMEM
/// @param atIndex 
/// @return Pointer to the new created struct
UIStringUInt8Id *getError(int atIndex) {
  UIStringUInt8Id *error = new struct UIStringUInt8Id;
  memcpy_P(error, &errorCodesLabels[atIndex], sizeof(UIStringUInt8Id));
  return error;
}

/// @brief Load UIStringUInt32Id - Off reason label from the PROGMEM
/// @param atIndex 
/// @return Pointer to the new created struct
UIStringUInt32Id *getOffReason(int atIndex) {
  UIStringUInt32Id *reason = new struct UIStringUInt32Id;
  memcpy_P(reason, &offReasonsLabels[atIndex], sizeof(UIStringUInt32Id));
  return reason;
}