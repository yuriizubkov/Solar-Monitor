#ifndef _VICTRON_DEVICE_MENU_ITEM_HPP_
#define _VICTRON_DEVICE_MENU_ITEM_HPP_

#include "IBaseScreen.hpp"

class VictronDeviceMenuItem: public IBaseScreen {
  private:
  public:
    VictronDeviceMenuItem(LiquidCrystal* display): IBaseScreen(display) {};
    void render() override;
    void processInput(Button buttonPressed) override;
    VictronProduct *victronProduct = nullptr;
    UIStringUInt8Id *productGroup = nullptr;
};

#endif