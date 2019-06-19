#ifndef CONTROL_COMPONENT_H
#define CONTROL_COMPONENT_H

#include "component.h"

class Map;

class ControlComponent : public Component {
public:
    virtual std::pair<int, int> move(const Map &m);
private:
};

#endif
