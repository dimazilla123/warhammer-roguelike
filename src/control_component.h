#ifndef CONTROL_COMPONENT_H
#define CONTROL_COMPONENT_H

#include "component.h"
#include "event.h"
#include <utility>

class Map;

class ControlComponent : public Component {
public:
    ControlComponent(std::pair<int, int> pos_) : pos(pos_) {}
    virtual std::pair<int, int> move(const Map &m);
    virtual Event *makeTurn(const Map &m);
    void setPos(const std::pair<int, int> &p) { pos = p; };
    std::pair<int, int> getPos() const { return pos; };
private:
    std::pair<int, int> pos;
};

#endif
