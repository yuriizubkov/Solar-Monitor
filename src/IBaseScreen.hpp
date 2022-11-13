#ifndef _IBASESCREEN_HPP_
#define _IBASESCREEN_HPP_

#include "GlobalDefines.hpp"
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "CommonTypes.hpp"
#include "VE.Direct.hpp"

class IBaseScreen {
  protected: 
    bool _isRendered = false;
    LiquidCrystal* _display;
  public:
    IBaseScreen(LiquidCrystal* display);
    virtual ~IBaseScreen() {}
    void (*onScreenChange)(IBaseScreen* screen) = nullptr;
    IBaseScreen* previousScreen = nullptr; // up button
    IBaseScreen* nextScreen = nullptr; // down button
    IBaseScreen* forwardScreen = nullptr; // right button
    IBaseScreen* backScreen = nullptr; // left button
    IBaseScreen* selectedScreen = nullptr; // select button
    bool isRendered();
    void setNeedRender();
    virtual void render() = 0;
    virtual void processInput(Button buttonPressed) = 0;
};

#endif