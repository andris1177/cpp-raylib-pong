#include "header/pong.h"
#include "header/pedal.h"
#include "header/ball.h"
#include "header/menu.h"
#include "header/definition.h"

int main()
{
    int screenWidth = 1280;
    int screeHeight = 720;
    int fps = 60;
    int gameMode = 0;

    Menu *menu = new Menu(screenWidth, screeHeight, fps);
    gameMode = menu->run();
    delete menu;
    
    Pong *pong = new Pong(screenWidth, screeHeight, fps, gameMode);
    delete pong;
}