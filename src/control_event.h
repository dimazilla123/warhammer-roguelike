#ifndef CONTROL_EVENT_H
#define CONTROL_EVENT_H

#include "event.h"
#include "entity.h"

class ControlEvent : public Event {
public:
    ControlEvent(Entity *e, unsigned long long t_);
    Entity *e;
private:
};

#endif
