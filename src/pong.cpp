#include "../header/pong.hpp"

Pong::Pong()
{
    this->settings = new Settings();
}

Pong::~Pong()
{
    delete settings;
}
