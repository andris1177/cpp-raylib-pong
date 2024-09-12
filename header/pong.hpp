#pragma once

#include "settings.hpp"
#include "menu.hpp"

#define RAYGUI_IMPLEMENTATION

class Pong
{
public:
    Pong();
    ~Pong();
    void run();

private:
    void initRaylib();
    void mainLoop();
    void draw();

private:
    Settings* settings;
    Menu* menu;
};
