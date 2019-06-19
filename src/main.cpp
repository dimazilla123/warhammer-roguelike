#include <iostream>
#include "entity.h"
#include "ascii_component.h"
#include <ncurses.h>

int main(int argc, char *argv[])
{
    initscr();

    Entity e;
    AsciiComponent *ac = new AsciiComponent('@');
    e.addComponent(std::type_index(typeid(AsciiComponent)), ac);
    addch(e.get<AsciiComponent>()->getChar());
    getch();

    endwin();

    return 0;
}
