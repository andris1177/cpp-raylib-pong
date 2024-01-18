#include <iostream>
#include <fstream>
#include "definition.h"
#include <unordered_map>
#include <string>

namespace Game
{
    class ReadConf
    {
    private:
        std::string file_path;
        int screenWidth;
        int screenHeight;
        int fps;
        int player1_up;
        int player1_down;
        int player2_up;
        int player2_down;
        std::string line;
        std::string value;
        static const std::unordered_map<std::string, int> keyMap;

    private:
        void ReadFile();
        int ConvertKeyControll(const std::string& key);

    public:
        ReadConf();
        settings GetSettings();
    };
}