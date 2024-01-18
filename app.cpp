#include "header/pong.h"
#include "header/menu.h"
#include "header/readConf.h"
#include "header/definition.h"

int main()
{
    int gameMode = 0;

    Game::ReadConf *readconf = new Game::ReadConf();
    settings setting = readconf->GetSettings();
    delete readconf;

    Game::Menu *menu = new Game::Menu(setting);
    gameMode = menu->run();
    delete menu;
    
    Game::Pong *pong = new Game::Pong(setting, gameMode);
    delete pong;
}