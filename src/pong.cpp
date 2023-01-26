#include "../header/pong.h"
#include "raylib.h"
#include <iostream>

Pong::Pong(int screenWidth, int screenHeight, int fps)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->maxFps = fps;
}

void Pong::draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    this->ball->draw();
    this->pedals[0]->draw();
    this->pedals[1]->draw();
    DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
    DrawText(std::to_string(this->pedals[1]->getScore()).c_str(), screenWidth/2-80, 40, 80, WHITE);
    DrawText(std::to_string(this->pedals[0]->getScore()).c_str(), screenWidth/2+40, 40, 80, WHITE);
    EndDrawing();
}

void Pong::handle_input()
{
    //pedál irányítás
    if (IsKeyDown(KEY_UP))
    {
        this->pedals[1]->move(true);
    }

    if (IsKeyDown(KEY_DOWN))
    {
        this->pedals[1]->move(false);
    }

    if (IsKeyDown(KEY_W))
    {
        this->pedals[0]->move(true);
    }

    if (IsKeyDown(KEY_S))
    {
        this->pedals[0]->move(false);
    }

    //labda mozgatása
    this->ball->move();

    //collide
    if (this->collided(this->ball, this->pedals[0]))
    {
        this->ball->collide(true);
    }

    if (this->collided(this->ball, this->pedals[1]))
    {
        this->ball->collide(true);
    }

    if (this->collidedge(this->ball, 'l'))
    {
        this->pedals[0]->addScore();
        this->ball->reset(screenWidth/2, screenHeight/2);
    }

    if (this->collidedge(this->ball, 'r'))
    {
        this->pedals[1]->addScore();
        this->ball->reset(screenWidth/2, screenHeight/2);
    }

    if (this->collidedge(this->ball, 'u'))
    {
        this->ball->collide(false);
    }

    if (this->collidedge(this->ball, 'd'))
    {
        this->ball->collide(false);
    }
}

bool Pong::collided(Ball* b, Pedal* p)
{
    position pedal = p->getPos();
    position ball = b->getPos();
    return (pedal.x - ball.x) * (pedal.x - ball.x) <= this->ball->getRadius() * this->ball->getRadius() && ball.y >= pedal.y && ball.y <= pedal.y + screenHeight / 4;
}
bool Pong::collidedge(Ball* b, char side)
{
    position ball = b->getPos();
    bool result;
    switch (side)
    {
    case 'u':
        result = ball.y - 0 <= b->getRadius();
        break;

    case 'd':
        result = screenHeight - ball.y <= b->getRadius();
        break;

    case 'l':
        result =  ball.x - 0 <= b->getRadius();
        break;

    case 'r':
        result =  screenWidth - ball.x <= b->getRadius();
        break;
    
    default:
        result = false;
        break;
    }
    return result;   
}

void Pong::run()
{
    this->ball = new Ball(screenWidth, screenHeight);
    this->pedals[0] = new Pedal(screenWidth, screenHeight, 0);
    this->pedals[1] = new Pedal(screenWidth, screenHeight, 1);

    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(maxFps);

    while (!WindowShouldClose())
    {
        this->draw();
        this->handle_input();
    }
    delete this->ball;
    delete this->pedals[0];
    delete this->pedals[1];
    CloseWindow();
}