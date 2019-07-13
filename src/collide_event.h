#ifndef COLLIDE_EVENT_H
#define COLLIDE_EVENT_H

#include "event.h"
#include "entity.h"

class CollideEvent : public Event {
public:
    CollideEvent(Entity *collider_, Entity *collided_, unsigned long long t_)
    {
        collider = collider_;
        collided = collided_;
        t = t_;
    }
    Entity *getCollider() const { return collider; }
    Entity *getCollided() const { return collided; }
    void setCollider(Entity *e) { collider = e; }
    void setCollided(Entity *e) { collided = e; }
private:
    Entity *collider;
    Entity *collided;
};

#endif
