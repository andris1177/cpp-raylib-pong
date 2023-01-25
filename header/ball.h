#pragma once
#include "definition.h"
class Ball
{
private:
    int x;
    int y;
    int radius;
    int speed;
    float angle;

public:
    position getPos();
    int getRadius();
    void move();
    void draw();
    void collide(bool direction);
    void reset(int x, int y);
    Ball(int screeWidth, int screenHeight);
};