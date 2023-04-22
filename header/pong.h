#pragma once
#include "ball.h"
#include "pedal.h"
#include "raylib.h"
class Pong
{
private:
    int screenWidth;
    int screenHeight;
    int maxFps;
    int gameMode;
    Pedal* pedals[2];
    Ball* ball;
    Sound paddel;
    Sound wall;
    Sound score;

public:
    Pong(int screenWidth, int screenHeight, int fps, int mode);
    void handle_input();
    void draw();
    void run();
    bool collided(Ball* b, Pedal* p);
    bool collidedge(Ball* b, char side);
};