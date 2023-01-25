#include "header/pong.h"
#include "header/pedal.h"
#include "header/ball.h"
#include "header/definition.h"

int main()
{
    int screenWidth = 1280;
    int screeHeight = 720;
    Pong game(screenWidth, screeHeight);
    game.run();
}