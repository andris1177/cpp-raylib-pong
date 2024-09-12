#include "../header/menu.hpp"
#include <iostream>

Menu::Menu()
{

}

void Menu::draw_gmode()
{
    if (GuiButton((Rectangle){100, 100, 200, 30}, "Click Me")) 
    {
        std::cout << "clicked\n";
    }
}

void Menu::draw_settings()
{

}

void Menu::draw_pause()
{

}

Menu::~Menu()
{

}
