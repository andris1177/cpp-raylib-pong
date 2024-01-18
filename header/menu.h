#pragma once
#include "definition.h"
#include "raylib.h"
#include <iostream>

namespace Game
{
    class Menu
    {
    private:
        int screenWidth;
        int screenHeight;
        int maxFps;
        bool singlePlayer;
        bool multiPlayer;
        float buttonWidth;
        float buttonHeight;
        float s_buttonX;
        float s_buttonY;
        float m_buttonX;
        float m_buttonY;


    public:
        Menu(settings setting);
        void draw();
        int run();
        void check_coilison();
    };
}