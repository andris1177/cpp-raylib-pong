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

    int single_player_bv1(int screenWidth, int screenHeight)
    {
        InitWindow(screenWidth, screenHeight, "Pong");
        SetTargetFPS(60);

        Pedal p(screenWidth-4, screenHeight/2, 4, screenHeight/4);

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(BLUE);
            p.Draw();
            p.Move();
            EndDrawing();
        }

        CloseWindow();
        return 0;
    }
}

