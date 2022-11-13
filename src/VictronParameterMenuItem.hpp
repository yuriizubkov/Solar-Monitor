#ifndef _VICTRON_PARAMETER_MENU_ITEM_HPP_
#define _VICTRON_PARAMETER_MENU_ITEM_HPP_

#include "IBaseScreen.hpp"

class VictronParameterMenuItem: public IBaseScreen {
  private:
    unsigned int nextIndexToShow = 0;
    bool parseSpecialCases(char *dataFieldLabel, int32_t value, char* parsedString, int parsedStringLength); // enum - like text values
    void valueToString(DataField *dataField, char *parsedString, int parsedStringLength); // other numerical values
  public:
    VictronParameterMenuItem(LiquidCrystal* display): IBaseScreen(display) {};
    void render() override;
    void processInput(Button buttonPressed) override;
    DataField *dataField = nullptr;
};

#endif