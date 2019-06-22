#include "game.h"
#include "control_component.h"
#include "monster_control_component.h"
#include "player_control_component.h"
#include "ascii_component.h"

Game::Game(size_t h, size_t w)
{
    map = new Map(h, w);
    create_player(5, 5);
    create_monster(10, 10);
}

Game::~Game()
{
    delete map;
}

Entity *Game::create_monster(int x, int y)
{
    Entity *e = new Entity;
    auto pos = std::make_pair(x, y);
    e->addComponent(std::type_index(typeid(ControlComponent)), new MonsterControlComponent(pos));
    e->addComponent(std::type_index(typeid(AsciiComponent)), new AsciiComponent('M', 2));
    map->addEntity(pos, e);
    map->pushEvent(new ControlEvent(e, map->getTurn()));
    map->nextTurn();
    return e;
}

Entity *Game::create_player(int x, int y)
{
    Entity *e = new Entity;
    auto pos = std::make_pair(x, y);
    e->addComponent(std::type_index(typeid(ControlComponent)), new PlayerControlComponent(this, pos));
    e->addComponent(std::type_index(typeid(AsciiComponent)), new AsciiComponent('@', 2));
    map->addEntity(pos, e);
    map->pushEvent(new ControlEvent(e, map->getTurn()));
    map->nextTurn();
    return e;
}

void Game::exit()
{
    to_exit = true;
}

void Game::gameLoop()
{
    while (!to_exit)
        if (!map->processEvent())
            to_exit = true;
}

int Game::getHeight() const
{
    return map->entities.size();
}

int Game::getWidth() const
{
    return map->entities[0].size();
}
