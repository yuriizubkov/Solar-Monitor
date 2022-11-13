#include "IBaseScreen.hpp"

IBaseScreen::IBaseScreen(LiquidCrystal* display) {
  this->_display = display;
}

bool IBaseScreen::isRendered() {
  return this->_isRendered;
}

void IBaseScreen::setNeedRender() {
  this->_isRendered = false;
}