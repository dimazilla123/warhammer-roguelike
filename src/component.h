#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"

class Component {
public:
    virtual ~Component() {}
    Entity *e;
};

#endif
