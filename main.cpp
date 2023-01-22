#include <iostream>
#include "raylib.h"

class Pedal
{
public:
    int y;
    int x;
    int width;
    int height;
    int speed = 3;
    int oldal;
    Pedal(int pedalX, int pedalY, int pWidth, int pHeight, int poldal)
    {
        y = pedalY;
        x = pedalX;
        width = pWidth;
        height = pHeight;
        oldal = poldal;

    }

    void Draw()
    {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Move()
    {  
        if (oldal == 0)
        {      
            if (IsKeyDown(KEY_W))
            {
                y -= speed;
            }

            if (IsKeyDown(KEY_S))
            {
                y += speed;
            }
        }

        if (oldal == 1)
        {      
            if (IsKeyDown(KEY_UP))
            {
                y -= speed;
            }

            if (IsKeyDown(KEY_DOWN))
            {
                y += speed;
            }
        }
    }
};

class Ball
{
public:
    int x;
    int y;
    int speedX = 3;
    int speedY = 3;
    int screenWidth;
    int screenHeight;
    Ball(int width, int height)
    {
        x = width / 2;
        y = height / 2;
        screenWidth = width;
        screenHeight = height;
    }

    void Draw()
    {
        float ballRadius = 25;
        DrawCircle(x, y, ballRadius, WHITE);
    }

    void Move(Pedal& b_p, Pedal& j_p)
    {
        x += speedX;
        y += speedY;
        std::cout << "x: " << x << " " << "y: " <<  y << "jobb padel y: " << j_p.y << std::endl;
        
        if (x > screenWidth && x < screenWidth + 60)
        {
            if (y >= j_p.y || y <= j_p.y + screenHeight / 4)
            {
                speedX *= -1;
            }
        }

        else if (x > screenWidth + 70)
        {
            CloseWindow();
        }

        if (x < 0)
        {
            if (y >= b_p.y || y <= b_p.y + screenHeight / 4)
            {
                speedX *= -1;
            }
        }

        else if (x > screenWidth + 70)
        {
            CloseWindow();
        }

        if (y > screenHeight)
        {
            speedY *= -1;
        }

        if (y < 1)
        {
            speedY *= -1;
        }
    }
};

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    Pedal b_p(1, screenHeight/2, 4, screenHeight/4, 0);
    Pedal j_p(screenWidth-4, screenHeight/2, 4, screenHeight/4, 1);
    Ball b(screenWidth, screenHeight);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        b_p.Draw();
        b_p.Move();
        j_p.Draw();
        j_p.Move();
        b.Draw();
        b.Move(b_p, j_p);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}