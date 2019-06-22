#ifndef MAP_H
#define MAP_H

#include "entity.h"
#include "event.h"
#include "move_event.h"
#include "control_event.h"
#include "event_comparator.h"
#include "move_handler.h"
#include "control_handler.h"

#include <vector>
#include <queue>
#include <functional>

class Map;

using HandlerFunction = std::function<void(Map*, Event*)>;

class Map {
public:
    Map(size_t h, size_t w);
    ~Map();
    void addEntity(size_t x, size_t y, Entity *e);
    void removeEntity(size_t x, size_t y, Entity *e);
    void addEntity(std::pair<int, int> pos, Entity *e);
    void removeEntity(std::pair<int, int> pos, Entity *e);
    std::vector<std::vector<std::vector<Entity*>>> entities;
    std::map<Entity*, std::pair<int, int>> positions;
    void nextTurn();
    unsigned long long nextTurn(unsigned long long t) const;
    unsigned long long getTurn() const { return turn; }
    void pushEvent(Event *e);
    bool processEvent();
private:
    std::priority_queue<Event*, std::vector<Event*>, EventComparator> ev_q;
    std::map<std::type_index, HandlerFunction> handlers;
    unsigned long long turn = 0;
};

void closeHandler(Map *m, Event *e);

#endif
