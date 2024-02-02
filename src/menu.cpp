#include "../header/menu.h"

Game::Menu::Menu(settings setting)
{
    this->setting = setting;
    this->singlePlayer = false;
    this->multiPlayer = false;
    this->buttonWidth = 200;
    this->buttonHeight = 50;
    this->s_buttonX = setting.screenWidth / 2 - buttonWidth / 2;
    this->s_buttonY = setting.screenHeight / 2;
    this->m_buttonX = setting.screenWidth / 2 - buttonWidth / 2;
    this-> m_buttonY = setting.screenHeight / 2 + 100;
}

void Game::Menu::draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("PONG", setting.screenWidth/2-135, 60, 100, WHITE);
    DrawRectangle(s_buttonX, s_buttonY, buttonWidth, buttonHeight, WHITE);
    DrawText("Single Player", s_buttonX + 27, s_buttonY + 10, 25, BLACK);
    DrawRectangle(m_buttonX, m_buttonY, buttonWidth, buttonHeight, WHITE);
    DrawText("Multi Player", m_buttonX + 27, m_buttonY + 10, 25, BLACK);
    EndDrawing();
}

void Game::Menu::check_coilison()
{
    if (CheckCollisionPointRec(GetMousePosition(), { s_buttonX, s_buttonY, buttonWidth, buttonHeight }))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                singlePlayer = true;
            }
        }
        else
        {
            singlePlayer = false;
        }

    if (CheckCollisionPointRec(GetMousePosition(), { m_buttonX, m_buttonY, buttonWidth, buttonHeight }))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                multiPlayer = true;
            }
        }

        else
        {
            multiPlayer = false;
        }
}

int Game::Menu::run()
{
    InitWindow(setting.screenWidth, setting.screenHeight, "Pong");
    SetTargetFPS(setting.fps);

    while (!WindowShouldClose())
    {
        this->check_coilison();
        this->draw();
        if (singlePlayer)
        {
            CloseWindow();
            return 1;
        }

        else if(multiPlayer)
        {
            CloseWindow();
            return 2;
        }
    }
    CloseWindow();
    return 0;
}