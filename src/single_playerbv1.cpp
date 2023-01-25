#include <iostream>
#include "raylib.h"
namespace SinglePlayerbv1
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
        Pedal(int pedalX, int pedalY, int pWidth, int pHeight)
        {
            y = pedalY;
            x = pedalX;
            width = pWidth;
            height = pHeight;

        }

        void Draw()
        {
            DrawRectangle(x, y, width, height, WHITE);
        }

        void Move()
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
            
        }

        void Move(Pedal& p, Bot& bt)
        {
            x += speedX;
            y += speedY;
            std::cout << "x: " << x << " " << "y: " <<  y <<  " bal pedal y:" << p.y <<   " jobb score: " << j_score << " bal score: " << b_score <<  std::endl;
            
            if (x < 0)
            {
                if (y >= bt.y && y <= bt.y + screenHeight / 4)
                {
                    speedX *= -1;
                    b_score++;
                }

                else if (x < -12)
                {
                    CloseWindow();
                }
            }

            if (x > screenWidth)
            {
                if (y >= p.y && y <= p.y + screenHeight / 4)
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

    class Bot
    {
    public:
        int ballX;
        int ballY;
        int x;
        int y;
        int s_width;
        int s_height;
        Bot(int widt, int height)
        {
            s_width = widt;
            s_height = height;
            x = 1;
            y = s_height/2;
        }

        void Draw()
        {
            DrawRectangle(x, y, 4, s_height/4, WHITE);
        }

        void Move(Ball& b)
        {
            if (b.y > y)
            {
                y++;
            }

            if (b.y < y)
            {
                y++;
            }
        }
    };


    int single_player_bv1(int screenWidth, int screenHeight)
    {
        InitWindow(screenWidth, screenHeight, "Pong");
        SetTargetFPS(60);

        Pedal p(screenWidth-4, screenHeight/2, 4, screenHeight/4);
        Ball b(screenWidth, screenHeight);
        Bot bt(screenWidth, screenHeight);

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(BLACK);
            p.Draw();
            p.Move();
            bt.Draw();
            bt.Move(b);
            b.Draw();
            b.Move(p, bt);
            DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
            EndDrawing();
        }

        CloseWindow();
        return 0;
    }
}

