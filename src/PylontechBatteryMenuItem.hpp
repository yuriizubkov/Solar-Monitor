#ifndef _PYLONTECH_BATTERY_MENU_ITEM_HPP_
#define _PYLONTECH_BATTERY_MENU_ITEM_HPP_

#include "IBaseScreen.hpp"

class PylontechBatteryMenuItem: public IBaseScreen {
  private:
  public:
    PylontechBatteryMenuItem(LiquidCrystal* display): IBaseScreen(display) {};
    void render() override;
    void processInput(Button buttonPressed) override;
};

#endif