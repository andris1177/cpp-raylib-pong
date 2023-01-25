#include <iostream>
#include "raylib.h"
namespace SinglePlayer1v1
{
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
        int speedX = 4;
        int speedY = 4;
        int screenWidth;
        int screenHeight;
        int j_score = 0;
        int b_score = 0;
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
            DrawText(std::to_string(b_score).c_str(), screenWidth/2-80, 40, 80, WHITE);
            DrawText(std::to_string(j_score).c_str(), screenWidth/2+40, 40, 80, WHITE);
        }

        void Move(Pedal& b_p, Pedal& j_p)
        {
            x += speedX;
            y += speedY;
            
            if (x > screenWidth)
            {
                if (y >= j_p.y && y <= j_p.y + screenHeight / 4)
                {
                    speedX *= -1;
                    j_score++;
                }

                else if (x > screenWidth + 12)
                {
                    CloseWindow();
                }
            }

            if (x < 0)
            {
                if (y >= b_p.y && y <= b_p.y + screenHeight / 4)
                {
                    speedX *= -1;
                    b_score++;
                }

                else if (x < -12)
                {
                    CloseWindow();
                }
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

    int single_player_1v1(int screenWidth, int screenHeight)
    {
        InitWindow(screenWidth, screenHeight, "Pong");
        SetTargetFPS(60);

        Pedal b_p(1, screenHeight/2, 4, screenHeight/4, 0);
        Pedal j_p(screenWidth-4, screenHeight/2, 4, screenHeight/4, 1);
        Ball b(screenWidth, screenHeight);

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(BLUE);
            //m.Draw();
            b_p.Draw();
            b_p.Move();
            j_p.Draw();
            j_p.Move();
            b.Draw();
            b.Move(b_p, j_p);
            DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
            EndDrawing();
        }

        CloseWindow();
        return 0;
    }
}