#include "../header/settings.hpp"
#include "raylib.h"
#include <iostream>

Settings::Settings()
{
    if (fileExsist())
    {
       readSettings(); 
    }
    else 
    {
        autoDetectSettings();
        saveSettings();
    }
}

bool Settings::fileExsist()
{
    if (std::filesystem::exists("config.json"))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void Settings::readSettings()
{
    std::ifstream i("config.json");
    i >> settings;
}

void Settings::saveSettings()
{
    std::ofstream o("config.json");
    o << settings;
}

void Settings::autoDetectSettings()
{
    InitWindow(0, 0, " ");
    settings["resolutionX"] = GetMonitorWidth(GetCurrentMonitor());
    settings["resolutionY"] = GetMonitorHeight(GetCurrentMonitor());
    settings["fps"] = GetMonitorRefreshRate(GetCurrentMonitor());
}

Settings::~Settings()
{

}
