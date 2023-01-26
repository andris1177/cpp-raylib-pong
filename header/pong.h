#pragma once
#include "ball.h"
#include "pedal.h"
class Pong
{
private:
    int screenWidth;
    int screenHeight;
    int maxFps;
    Pedal* pedals[2];
    Ball* ball;

public:
    void handle_input();
    void draw();
    void run();
    bool collided(Ball* b, Pedal* p);
    bool collidedge(Ball* b, char side);
    Pong(int screenWidth, int screenHeight, int fps);
};