#ifndef MOVE_EVENT_H
#define MOVE_EVENT_H

#include "event.h"
#include "entity.h"

class MoveEvent : public Event {
public:
    MoveEvent(std::pair<int, int> st_pos, std::pair<int, int> end_pos, Entity *e, unsigned long long t_) :
        start_pos(st_pos), targ_pos(end_pos), subject(e)
    {
        t = t_;
    }
    std::pair<int, int> start_pos;
    std::pair<int, int> targ_pos;
    Entity *subject;
private:
};

#endif
