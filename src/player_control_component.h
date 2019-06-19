#ifndef PLAYER_CONTROL_COMPONENT_H
#define PLAYER_CONTROL_COMPONENT_H

#include "control_component.h"

class PlayerControlComponent : public ControlComponent {
public:
    PlayerControlComponent();
    ~PlayerControlComponent();
    std::pair<int, int> move(const Map &m);
};

#endif
