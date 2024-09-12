#include "header/pong.hpp"

int main()
{
    Pong *pong = new Pong();
    pong->run();
    delete pong;
    return 0;
}
