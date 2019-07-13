#include "map.h"
#include "control_component.h"
#include "ascii_component.h"
#include "close_event.h"
#include <algorithm>
#include <unordered_set>
#include <iostream>

Map::Map(size_t h, size_t w)
{
    entities.resize(h, std::vector<std::vector<Entity*>>(w));
    handlers[std::type_index(typeid(ControlEvent))] = controlHandler;
    handlers[std::type_index(typeid(MoveEvent))] = moveHandler;
    handlers[std::type_index(typeid(CloseEvent))] = closeHandler;
    handlers[std::type_index(typeid(CollideEvent))] = collideHandler;
}

Map::~Map()
{
    for (auto &line : entities)
        for (auto &cell : line)
            for (auto &e : cell)
                delete e;
}

void Map::addEntity(size_t x, size_t y, Entity *e)
{
    int l = 0, r = entities[x][y].size();
    int e_lev = 0;
    AsciiComponent *ac;
    if (ac = e->get<AsciiComponent>())
        e_lev = ac->getLevel();

    while (l + 1 < r) {
        int m = (l + r) / 2;
        int level = 0;
        if ((ac = entities[x][y][m]->get<AsciiComponent>()))
            level = ac->getLevel();
        if (level <= e_lev)
            l = m;
        else
            r = m;
    }
    entities[x][y].insert(entities[x][y].begin() + l, e);
    //ev_q.push(new ControlEvent(e, turn));
}

void Map::removeEntity(size_t x, size_t y, Entity *e)
{
    auto it = std::find(entities[x][y].begin(),
                        entities[x][y].end(), e);
    if (it != entities[x][y].end())
        entities[x][y].erase(it);
}

void Map::addEntity(std::pair<int, int> pos, Entity *e)
{
    auto [x, y] = pos;
    addEntity(x, y, e);
}

void Map::removeEntity(std::pair<int, int> pos, Entity *e)
{
    auto [x, y] = pos;
    removeEntity(x, y, e);
}

void Map::nextTurn()
{
    turn = nextTurn(turn);
}

unsigned long long Map::nextTurn(unsigned long long t) const
{
    return t += 10;
}

void Map::pushEvent(Event *e)
{
    ev_q.push(e);
}

bool Map::processEvent()
{
    if (ev_q.empty())
        return false;
    Event *e = ev_q.top();
    ev_q.pop();
    if (e) {
        std::cerr << "Handelling " << typeid(*e).name() << " at " <<
           e->getTime() << "\n";
        auto it = handlers.find(std::type_index(typeid(*e)));
        if (it != handlers.end())
            (it->second)(this, e);
        turn = e->getTime();
        delete e;
    }
    return true;
}

