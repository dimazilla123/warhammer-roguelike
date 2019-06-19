#ifndef MAP_H
#define MAP_H

#include "entity.h"
#include <vector>

class Map {
public:
    Map(size_t h, size_t w);
    ~Map();
    void add_entity(size_t x, size_t y, Entity *e);
    void remove_entity(size_t x, size_t y, Entity *e);
    void update();
    std::vector<std::vector<std::vector<Entity*>>> entities;
};

#endif
