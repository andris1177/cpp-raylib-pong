#include "src/single_player1v1.cpp"
#include "src/single_playerbv1.cpp"
#include "src/multiplayer.cpp"
#include "raylib.h"

class Menu
{
public:
    int screenWidth;
    int screenHeight;
    int selectedOption;
    const int numOptions = 4;
    Rectangle singlePlayer1v1Button;
    Rectangle singlePlayerButton;
    Rectangle multiplayerButton;
    Rectangle quitButton;
    Menu(int width, int height)
    {
        screenWidth = width;
        screenHeight = height;
        selectedOption = 0;

        singlePlayer1v1Button.x = screenWidth/2 - 120;
        singlePlayer1v1Button.y = screenHeight/2 - 60;
        singlePlayer1v1Button.width = 240;
        singlePlayer1v1Button.height = 40;

        singlePlayerButton.x = screenWidth/2 - 120;
        singlePlayerButton.y = screenHeight/2 - 20;
        singlePlayerButton.width = 240;
        singlePlayerButton.height = 40;

        multiplayerButton.x = screenWidth/2 - 120;
        multiplayerButton.y = screenHeight/2 + 20;
        multiplayerButton.width = 240;
        multiplayerButton.height = 40;

        quitButton.x = 20;
        quitButton.y = screenHeight - 40;
        quitButton.width = 80;
        quitButton.height = 20;
    }

    void HandleInput()
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, singlePlayer1v1Button))
            {
                selectedOption = 0;
                SinglePlayer1v1::single_player_1v1(screenWidth, screenHeight);
                //CloseWindow();
            }
            else if (CheckCollisionPointRec(mousePos, singlePlayerButton))
            {
                selectedOption = 1;
                SinglePlayerbv1::single_player_bv1(screenWidth, screenHeight);
                CloseWindow();
            }
            else if (CheckCollisionPointRec(mousePos, multiplayerButton))
            {
                selectedOption = 2;
                std::cout << "Még nincs kész a multiplayer" << std::endl;
            }
            else if (CheckCollisionPointRec(mousePos, quitButton))
            {
                selectedOption = 3;
                CloseWindow();
            }
        }
    }

    void Draw()
    {
        DrawText("PONG", screenWidth/2 - MeasureText("PONG", 30)/2, screenHeight/4, 30, WHITE);
        if (selectedOption == 0) DrawRectangleRec(singlePlayer1v1Button, RED);
        else DrawRectangleRec(singlePlayer1v1Button, WHITE);
        DrawText("Single Player 1v1", singlePlayer1v1Button.x + singlePlayer1v1Button.width/2 - MeasureText("Single Player 1v1", 20)/2, singlePlayer1v1Button.y + singlePlayer1v1Button.height/2 - 10, 20, BLACK);

        if (selectedOption == 1) DrawRectangleRec(singlePlayerButton, RED);
        else DrawRectangleRec(singlePlayerButton, WHITE);
        DrawText("Single Player", singlePlayerButton.x + singlePlayerButton.width/2 - MeasureText("Single Player", 20)/2, singlePlayerButton.y + singlePlayerButton.height/2 - 10, 20, BLACK);

        if (selectedOption == 2) DrawRectangleRec(multiplayerButton, RED);
        else DrawRectangleRec(multiplayerButton, WHITE);
        DrawText("Multiplayer", multiplayerButton.x + multiplayerButton.width/2 - MeasureText("Multiplayer", 20)/2, multiplayerButton.y + multiplayerButton.height/2 - 10, 20, BLACK);

        if (selectedOption == 3) DrawRectangleRec(quitButton, RED);
        else DrawRectangleRec(quitButton, WHITE);
        DrawText("Quit", quitButton.x + quitButton.width/2 - MeasureText("Quit", 20)/2, quitButton.y + quitButton.height/2 - 10, 20, BLACK);
    }
};

int main()
{
    int screenWidth = 1280;
    int screenHeight = 720;
    Menu m(screenWidth, screenHeight);
    InitWindow(screenWidth, screenHeight, "Pong ");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        m.HandleInput();
        m.Draw();
        EndDrawing();
    }
}