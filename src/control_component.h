#ifndef CONTROL_COMPONENT_H
#define CONTROL_COMPONENT_H

#include "component.h"
#include "event.h"
#include <utility>

class Map;

class ControlComponent : public Component {
public:
    ControlComponent(std::pair<int, int> pos_) : pos(pos_) {}
    virtual ~ControlComponent() {}
    virtual Event *makeTurn(const Map &m) = 0;
    void setPos(const std::pair<int, int> &p) { pos = p; };
    std::pair<int, int> getPos() const { return pos; };
protected:
    std::pair<int, int> pos;
};

#endif
