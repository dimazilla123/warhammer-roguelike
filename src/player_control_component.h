#ifndef PLAYER_CONTROL_COMPONENT_H
#define PLAYER_CONTROL_COMPONENT_H

#include "control_component.h"
#include "game.h"

class PlayerControlComponent : public ControlComponent {
public:
    PlayerControlComponent(Game *g);
    ~PlayerControlComponent();
    std::pair<int, int> move(const Map &m);
private:
    Game *game;
};

#endif
