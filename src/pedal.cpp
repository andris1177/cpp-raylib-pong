#include "../header/definition.h"
#include "../header/pedal.h"
#include "raylib.h"

Pedal::Pedal(int screenwidth, int screenHeight, int oldal) 
{
    width = 8;
    height = screenHeight/4;
    y = screenHeight/2 - height/2;
    x = oldal==0 ? 8 : screenwidth-width-8;
    score = 0;
    speed = 4;
};

position Pedal::getPos()
{
    return {this->x, this->y};
}

void Pedal::move(bool direction)
{
    if (direction == false)
    {
        this->y += this->speed;
        if (y > height * 3)
        {
            y = height *3;
        }
    }

    else
    {
        this->y -= this->speed;

        if (y < 0)
        {
            y = 0;
        }
    }
}

void Pedal::draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}

int Pedal::getScore()
{
    return score;
}

void Pedal::addScore()
{
    score++;
}
