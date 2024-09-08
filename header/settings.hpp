#pragma once

#include "json.hpp"
using json = nlohmann::json;
#include "raylib.h"

#include <iostream>
#include <filesystem>
#include <fstream>

class Settings
{
public:
    Settings();
    ~Settings();

private:
    void readSettings();
    void saveSettings(); 
    bool fileExsist();
    void autoDetectSettings();

public:
   json settings;
};
