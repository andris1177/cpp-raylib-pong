#pragma once
#include "definition.h"
#include "raylib.h"

namespace Game
{
    class Pedal
    {
    private:
        int x;
        int y;
        int width;
        int height;
        int score;
        int speed;

    public:
        position getPos();
        void move(bool direction);
        void draw();
        int getScore();
        void addScore();
        Pedal(int screenwidth, int screenHeight, int oldal);
    };
}