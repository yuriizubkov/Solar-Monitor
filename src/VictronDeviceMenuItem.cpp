#include "VictronDeviceMenuItem.hpp"

void VictronDeviceMenuItem::processInput(Button buttonPressed) {
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

void VictronDeviceMenuItem::render() {
  this->_display->clear();
  if(this->victronProduct != nullptr && this->productGroup != nullptr) {
    this->_display->setCursor(0, 0);
    this->_display->print(this->productGroup->uiLabel);
    this->_display->setCursor(0, 1);
    this->_display->print(this->victronProduct->uiLabel);
  } else {
    this->_display->setCursor(0, 0);
    this->_display->print(F("Victron Device"));
    this->_display->setCursor(0, 1);
    this->_display->print(F("Waiting For Data"));
  }

  this->_isRendered = true;
}