#pragma once
#include "raylib.h"

#include "raygui.h"

class Menu 
{
public:
    Menu();
    ~Menu();
    void draw_gmode();
    void draw_settings();
    void draw_pause();

public:
    bool gmodeState;
    bool settiongsState;
    bool pauseState;
};
