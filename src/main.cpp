#include <iostream>
#include "entity.h"
#include "control_component.h"
#include "ascii_component.h"
#include "monster_control_component.h"
#include "player_control_component.h"
#include "map.h"
#include <ncurses.h>

Entity *create_monster()
{
    Entity *e = new Entity;
    e->addComponent(std::type_index(typeid(ControlComponent)), new MonsterControlComponent());
    e->addComponent(std::type_index(typeid(AsciiComponent)), new AsciiComponent('M', 2));
    return e;
}

Entity *create_player()
{
    Entity *e = new Entity;
    e->addComponent(std::type_index(typeid(ControlComponent)), new PlayerControlComponent());
    e->addComponent(std::type_index(typeid(AsciiComponent)), new AsciiComponent('@', 2));
    return e;
}

int main(int argc, char *argv[])
{
    Map map(10, 10);

    map.add_entity(5, 5, create_monster());
    map.add_entity(1, 1, create_monster());
    map.add_entity(0, 8, create_player());
    while (true)
        map.update();

    return 0;
}
