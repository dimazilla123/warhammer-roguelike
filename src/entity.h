#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <typeindex>
#include <map>

class Component;

class Entity {
public:
    ~Entity();
    void addComponent(std::type_index type, Component *c);

    template<typename T>
    T* get()
    {
        auto it = comps.find(std::type_index(typeid(T)));
        if (it != comps.end())
            return dynamic_cast<T*>(it->second);
        return nullptr;
    }
private:
    std::map<std::type_index, Component*> comps;
};

#endif
