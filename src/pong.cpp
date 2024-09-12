#include "../header/pong.hpp"

Pong::Pong()
{
    this->settings = new Settings();
    this->menu = new Menu();
}

void Pong::initRaylib()
{
    if (settings->settings["Fullscreen"] == false)
    {
        InitWindow(settings->settings["resolutionX"], settings->settings["resolutionY"], "Pong");
    }

    if (settings->settings["Fullscreen"] == true)
    {
        InitWindow(settings->settings["resolutionXFull"], settings->settings["resolutionYFull"], "Pong");
    }

    InitAudioDevice();
    SetTargetFPS(settings->settings["fps"]);
}

void Pong::run()
{
    initRaylib();
    mainLoop();
}

void Pong::mainLoop()
{   
    while (!WindowShouldClose()) 
    {
        draw();
    }
}

void Pong::draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    menu->draw_gmode();
    EndDrawing();
}

Pong::~Pong()
{
    delete settings;
    delete menu;
}
