#pragma once
#include "ball.h"
#include "pedal.h"
#include "raylib.h"
#include <iostream>
namespace Game
{
    class Pong
    {
    private:
        int screenWidth;
        int screenHeight;
        int maxFps;
        int gameMode;
        int player1_up;
        int player1_down;
        int player2_up;
        int player2_down;
        Pedal* pedals[2];
        Ball* ball;
        Sound paddel;
        Sound wall;
        Sound score;

    public:
        Pong(settings setting, int mode);
        void handle_input();
        void draw();
        void run();
        bool collided(Ball* b, Pedal* p);
        bool collidedge(Ball* b, char side);
    };
}