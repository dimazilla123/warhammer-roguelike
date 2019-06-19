#include "game.h"
#include "control_component.h"
#include "monster_control_component.h"
#include "player_control_component.h"
#include "ascii_component.h"

Game::Game(size_t h, size_t w)
{
    map = new Map(h, w);
    map->addEntity(0, 0, create_player());
    map->addEntity(4, 4, create_monster());
    map->addEntity(5, 4, create_monster());
    Entity *e = create_monster();
    map->addEntity(4, 5, e);
}

Game::~Game()
{
    delete map;
}

Entity *Game::create_monster()
{
    Entity *e = new Entity;
    e->addComponent(std::type_index(typeid(ControlComponent)), new MonsterControlComponent());
    e->addComponent(std::type_index(typeid(AsciiComponent)), new AsciiComponent('M', 2));
    return e;
}

Entity *Game::create_player()
{
    Entity *e = new Entity;
    e->addComponent(std::type_index(typeid(ControlComponent)), new PlayerControlComponent(this));
    e->addComponent(std::type_index(typeid(AsciiComponent)), new AsciiComponent('@', 2));
    return e;
}

void Game::exit()
{
    to_exit = true;
}

void Game::gameLoop()
{
    while (!to_exit)
        map->update();
}

int Game::getHeight() const
{
    return map->entities.size();
}

int Game::getWidth() const
{
    return map->entities[0].size();
}
