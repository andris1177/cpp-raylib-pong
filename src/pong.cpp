#include "../header/pong.h"

Game::Pong::Pong(settings setting, int mode)
{
    this->gameMode = mode;
    this->setting = setting;
    this->ball = new Ball(setting.screenWidth, setting.screenHeight);
    this->pedals[0] = new Pedal(setting.screenWidth, setting.screenHeight, 0);
    this->pedals[1] = new Pedal(setting.screenWidth, setting.screenHeight, 1);

    InitWindow(setting.screenWidth, setting.screenHeight, "Pong");
    InitAudioDevice(); 
    SetTargetFPS(setting.fps);
    
    run();
}

void Game::Pong::draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    this->ball->draw();
    this->pedals[0]->draw();
    this->pedals[1]->draw();
    DrawLine(setting.screenWidth/2, 0, setting.screenWidth/2, setting.screenHeight, WHITE);
    DrawText(TextFormat("%d", this->pedals[1]->getScore()), setting.screenWidth/2-80, 40, 80, WHITE);
    DrawText(TextFormat("%d", this->pedals[0]->getScore()), setting.screenWidth/2+40, 40, 80, WHITE);
    EndDrawing();
}

void Game::Pong::handle_input()
{
    //multi player 1v1
    if (gameMode == 2)
    {
        if (IsKeyDown(setting.player2_up))
        {
            this->pedals[1]->move(true);
        }

        if (IsKeyDown(setting.player2_down))
        {
            this->pedals[1]->move(false);
        }

        if (IsKeyDown(setting.player1_up))
        {
            this->pedals[0]->move(true);
        }

        if (IsKeyDown(setting.player1_down))
        {
            this->pedals[0]->move(false);
        }
    }

    //single player
    if (gameMode == 1)
    {
        //player controlled pedal
        if (IsKeyDown(setting.player1_up))
        {
            this->pedals[0]->move(true);
        }

        if (IsKeyDown(setting.player1_down))
        {
            this->pedals[0]->move(false);
        }

        // "ai" controlled pedal
        if (this->ball->getPos().y > this->pedals[1]->getPos().y)
        {
            this->pedals[1]->move(false);
        }
        else if (this->ball->getPos().y < this->pedals[1]->getPos().y)
        {
            this->pedals[1]->move(true);
        }
    }

    this->ball->move();

    if (this->collided(this->ball, this->pedals[0]))
    {
        this->ball->collide(true);
        PlaySound(this->paddel);
    }

    if (this->collided(this->ball, this->pedals[1]))
    {
        this->ball->collide(true);
        PlaySound(this->paddel);
    }

    if (this->collidedge(this->ball, 'l'))
    {
        this->pedals[0]->addScore();
        PlaySound(score);
        this->ball->reset(setting.screenWidth/2, setting.screenHeight/2);
    }

    if (this->collidedge(this->ball, 'r'))
    {
        this->pedals[1]->addScore();
        PlaySound(score);
        this->ball->reset(setting.screenWidth/2, setting.screenHeight/2);
    }

    if (this->collidedge(this->ball, 'u'))
    {
        this->ball->collide(false);
        PlaySound(this->wall);
    }

    if (this->collidedge(this->ball, 'd'))
    {
        this->ball->collide(false);
        PlaySound(this->wall);
    }
    
}

bool Game::Pong::collided(Ball* b, Pedal* p)
{
    position pedal = p->getPos();
    position ball = b->getPos();
    return (pedal.x - ball.x) * (pedal.x - ball.x) <= this->ball->getRadius() * this->ball->getRadius() && ball.y >= pedal.y && ball.y <= pedal.y + setting.screenHeight / 4;
}
bool Game::Pong::collidedge(Ball* b, char side)
{
    position ball = b->getPos();
    bool result;
    switch (side)
    {
    case 'u':
        result = ball.y - 0 <= b->getRadius();
        break;

    case 'd':
        result = setting.screenHeight - ball.y <= b->getRadius();
        break;

    case 'l':
        result =  ball.x - 0 <= b->getRadius();
        break;

    case 'r':
        result =  setting.screenWidth - ball.x <= b->getRadius();
        break;
    
    default:
        result = false;
        break;
    }
    return result;   
}

void Game::Pong::run()
{
    if (gameMode == 0)
    {
        return;
    }

    if (setting.fullScreen)
    {
        ToggleFullscreen();    
    }

    this->paddel = LoadSound("sounds/paddel.wav");
    this->wall = LoadSound("sounds/wall.wav");
    this->score = LoadSound("sounds/score.wav");

    while (!WindowShouldClose())
    {
        this->draw();
        this->handle_input();
    }
    
}

Game::Pong::~Pong()
{
    delete this->ball;
    delete this->pedals[0];
    delete this->pedals[1];
    UnloadSound(this->paddel);
    UnloadSound(this->wall);
    UnloadSound(this->score);
    CloseAudioDevice(); 
    CloseWindow();
}