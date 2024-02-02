#pragma once
#include <iostream>

typedef struct {
    int x, y;
} position;

typedef struct {
    int screenWidth;
    int screenHeight;
    int fps;
    int player1_up;
    int player1_down;
    int player2_up;
    int player2_down;
    bool fullScreen;
} settings;