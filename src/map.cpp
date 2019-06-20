#include "map.h"
#include "control_component.h"
#include "ascii_component.h"
#include <algorithm>
#include <unordered_set>

Map::Map(size_t h, size_t w)
{
    entities.resize(h, std::vector<std::vector<Entity*>>(w));
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
}

void Map::removeEntity(size_t x, size_t y, Entity *e)
{
    entities[x][y].erase(std::find(entities[x][y].begin(),
                                   entities[x][y].end(), e));
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
