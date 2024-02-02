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
        settings setting;
        int gameMode;
        Pedal* pedals[2];
        Ball* ball;
        Sound paddel;
        Sound wall;
        Sound score;

    public:
        Pong(settings setting, int mode);
        ~Pong();
        void handle_input();
        void draw();
        void run();
        bool collided(Ball* b, Pedal* p);
        bool collidedge(Ball* b, char side);
    };
}