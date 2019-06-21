#ifndef MAP_H
#define MAP_H

#include "entity.h"
#include <vector>
#include "event.h"
#include "move_event.h"
#include "control_event.h"
#include <queue>
#include <functional>

class Map;

using HandlerFunction = std::function<void(Map*, Event*)>;

struct CompEvPtrs {
    bool operator()(Event *a, Event *b) const
    {
        return a->getTime() < b->getTime();
    }
};

class Map {
public:
    Map(size_t h, size_t w);
    ~Map();
    void addEntity(size_t x, size_t y, Entity *e);
    void removeEntity(size_t x, size_t y, Entity *e);
    void addEntity(std::pair<int, int> pos, Entity *e);
    void removeEntity(std::pair<int, int> pos, Entity *e);
    void update();
    std::vector<std::vector<std::vector<Entity*>>> entities;
    void nextTurn();
    unsigned long long nextTurn(unsigned long long t) const;
    unsigned long long getTurn() const { return turn; }
    void pushEvent(Event *e);
    void processEvent();
private:
    std::priority_queue<Event*, std::vector<Event*>, CompEvPtrs> ev_q;
    std::map<std::type_index, HandlerFunction> handlers;
    unsigned long long turn = 0;
};

void controlHandler(Map *m, Event *e);
void moveHandler(Map *m, Event *e);

#endif
