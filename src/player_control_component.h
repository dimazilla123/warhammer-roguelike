#ifndef PLAYER_CONTROL_COMPONENT_H
#define PLAYER_CONTROL_COMPONENT_H

#include "control_component.h"
#include "game.h"
#include <ncurses.h>

class PlayerControlComponent : public ControlComponent {
public:
    PlayerControlComponent(Game *g);
    ~PlayerControlComponent();
    std::pair<int, int> move(const Map &m);
    void pullMessage(const std::string &s);
private:
    int h, w;
    std::string last_message;
    Game *game;
    WINDOW *field;
    WINDOW *messageline;
    WINDOW *statline;
};

#endif
