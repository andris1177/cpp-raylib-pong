#include "../header/generateConfig.hpp"

Game::GenerateConfig::GenerateConfig()
{
    //SetWindowState(FLAG_WINDOW_HIDDEN);
    this->testScreenWidth = 0;
    this->testScreenHeight = 0;
    this->testFps = 0;
    this->fileName = "game.cfg";
    

    if (!isFileExsist())
    {
        InitWindow(testScreenWidth, testScreenHeight, "Pong");
        SetTargetFPS(testFps);
        checkSystem();
        createFile();
        CloseWindow();
    }

}

bool Game::GenerateConfig::isFileExsist()
{
    return std::filesystem::exists(fileName);
}

void Game::GenerateConfig::checkSystem()
{
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    fps = GetFPS();
}

void Game::GenerateConfig::createFile()
{
    std::ofstream f(fileName);
    f << "FULL_SCREEN_WIDTH = " << screenWidth << "\n";
    f << "FULL_SCREEN_HEIGHT = " << screenHeight << "\n";
    f << "WINDOW_SCREEN_WIDTH = " << screenWidth / 2 << "\n";
    f << "WINDOW_SCREEN_HEIGHT = " << screenHeight / 2 << "\n";
    f << "FPS = 60" << "\n";
    f << "PLAYER1_UP = KEY_W" << "\n";
    f << "PLAYER1_DOWN = KEY_S" << "\n";
    f << "PLAYER2_UP = KEY_UP" << "\n";
    f << "PLAYER2_DOWN = KEY_DOWN" << "\n";
    f << "FULL_SREEN = false" << "\n";
    f << "# use the raylib key names" << "\n";
    f << "# player 1: left" << "\n";
    f << "# player 2: right" << "\n";
}