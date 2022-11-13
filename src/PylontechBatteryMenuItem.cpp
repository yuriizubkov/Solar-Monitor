#include "PylontechBatteryMenuItem.hpp"

void PylontechBatteryMenuItem::processInput(Button buttonPressed) {
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
      break;
    default:
      break;
  }
}

void PylontechBatteryMenuItem::render() {
  this->_display->clear();
  this->_display->setCursor(0, 0);
  this->_display->print(F("Battery"));
  this->_display->setCursor(0, 1);
  this->_display->print(F("Not Inplemented"));

  this->_isRendered = true;
}