#ifndef CONTROL_COMPONENT_H
#define CONTROL_COMPONENT_H

#include "component.h"
#include "event.h"
#include <utility>

class Map;

class ControlComponent : public Component {
public:
    virtual std::pair<int, int> move(const Map &m);
    virtual Event *makeTurn(const Map &m) { return nullptr; };
private:
};

#endif
