#ifndef COLLIDE_COMPONENT_H
#define COLLIDE_COMPONENT_H

#include "component.h"

enum CollisionType {
    PUSH,
    CANNOT_PASS,
};

class CollideComponent : public Component {
public:
    CollideComponent(CollisionType t) : type(t) {}
    CollisionType getType() const { return type; }
    void setType(CollisionType t) { type = t; }
private:
    CollisionType type;
};

#endif
