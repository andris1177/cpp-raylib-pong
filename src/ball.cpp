#include "../header/definition.h"
#include "../header/ball.h"
#include "raylib.h"
#include <stdlib.h>
#include <cmath>

Ball::Ball(int screeWidth, int screenHeight)
{
    x = screeWidth/2;
    y = screenHeight/2;
    radius = 25;
    speed = 8;
    angle = rand()/1000000 % 7;
}

position Ball::getPos()
{
    return {x, y};
}

int Ball::getRadius()
{
    return radius;
}

void Ball::move()
{
    x += speed * cos(angle);
    y += speed * sin(angle);
}

void Ball::draw()
{
    DrawCircle(x, y, radius, WHITE);
}

void Ball::collide(bool direction)
{
    if (!direction)
    {
        if(y < 50)
        {
            y = radius+10;
        }else{
            y-= 10;
        }
        angle = 2*PI-angle; 
    }

    else
    {   
        if(x < 50)
        {
            x = radius+10;
        }else{
            x-= 10;
        }
        angle = PI-angle;
        if (angle < 0)
        {
            angle += 2 * PI;
        }
    }
    if (angle == PI)
    {
        angle = rand() % 7;
    }
}

void Ball::reset(int x, int y)
{
    this->x = x;
    this->y = y;
    angle = rand()/1000000 % 7;
}