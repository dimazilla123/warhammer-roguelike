#include "map.h"
#include "control_component.h"
#include "ascii_component.h"
#include <algorithm>
#include <unordered_set>

Map::Map(size_t h, size_t w)
{
    entities.resize(h, std::vector<std::vector<Entity*>>(w));
    handlers[std::type_index(typeid(ControlEvent))] = controlHandler;
    handlers[std::type_index(typeid(MoveEvent))] = moveHandler;
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
    ev_q.push(new ControlEvent(e, turn));
}

void Map::removeEntity(size_t x, size_t y, Entity *e)
{
    entities[x][y].erase(std::find(entities[x][y].begin(),
                                   entities[x][y].end(), e));
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

void Map::update()
{
    std::unordered_set<Entity*> updated;
    for (int i = 0; i < entities.size(); i++) {
        for (int j = 0; j < entities[i].size(); j++) {
            for (auto e : entities[i][j]) {
                if (updated.find(e) != updated.end())
                    continue;
                updated.insert(e);
                auto cc = e->get<ControlComponent>();
                if (cc) {
                    auto [dx, dy] = cc->move(*this);
                    int x = i + dx;
                    int y = j + dy;
                    if (0 <= x && x < entities.size() &&
                        0 <= y && y < entities[0].size()) {
                        addEntity(x, y, e);
                        removeEntity(i, j, e);
                    }
                }
            }
        }
    }
}

void Map::nextTurn()
{
    turn = nextTurn(turn);
}

unsigned long long Map::nextTurn(unsigned long long t) const
{
    return t++;
}

void Map::pushEvent(Event *e)
{
    ev_q.push(e);
}

void Map::processEvent()
{
    Event *e = ev_q.top();
    ev_q.pop();
    handlers[std::type_index(typeid(ev_q))](this, e);
}

void controlHandler(Map *m, Event *e)
{
    ControlEvent *ev = static_cast<ControlEvent*>(e);
    Entity *ent = ev->e;
    auto cc = ent->get<ControlComponent>();
    if (cc) {
        Event *add = cc->makeTurn(*m);
    }
}

void moveHandler(Map *m, Event *e)
{
    MoveEvent *ev = static_cast<MoveEvent*>(e);
    Entity *ent = ev->subject;
    auto check_bounds = [m](const std::pair<int, int> &pos) {
        auto [x, y] = pos;
        return 0 <= x && x < m->entities.size() &&
               0 <= y && y < m->entities[0].size();
    };
    if (check_bounds(ev->start_pos) && check_bounds(ev->targ_pos)) {
        m->removeEntity(ev->start_pos, ent);
        m->addEntity(ev->targ_pos, ent);
    }
}
