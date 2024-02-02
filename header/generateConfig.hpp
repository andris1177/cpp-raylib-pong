#pragma once
#include "raylib.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace Game
{
    class GenerateConfig
    {
    public:
        GenerateConfig();

    private:
        bool isFileExsist();
        void checkSystem();
        void createFile();

    private:
        int testFps;
        int testScreenWidth;
        int testScreenHeight;
        int fps;
        int screenWidth;
        int screenHeight;
        std::string fileName;
    };
} 
