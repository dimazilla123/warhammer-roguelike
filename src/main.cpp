#include <iostream>
#include "game.h"

int main(int argc, char *argv[])
{
    Game g(25, 80);
    g.gameLoop();

    return 0;
}
