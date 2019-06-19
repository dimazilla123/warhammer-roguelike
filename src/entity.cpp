#include "entity.h"
#include "component.h"

Entity::~Entity()
{
    for (auto &p : comps)
        delete p.second;
}

void Entity::addComponent(std::type_index type, Component *c)
{
    comps[type] = c;
}
