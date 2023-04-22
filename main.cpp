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

    Menu menu(screenWidth, screeHeight, fps);
    gameMode = menu.run();
    
    Pong game(screenWidth, screeHeight, fps, gameMode);
    game.run();
    
}