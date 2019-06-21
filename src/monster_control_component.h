#ifndef MONSTER_CONTROL_COMPONENT
#define MONSTER_CONTROL_COMPONENT

#include "control_component.h"

class MonsterControlComponent : public ControlComponent {
public:
    std::pair<int, int> move(const Map &m);
    MonsterControlComponent(std::pair<int, int> pos) : ControlComponent(pos) {}
private:
    int turn = 0;
    std::pair<int, int> ret[2] = {
        std::make_pair(0, -1),
        std::make_pair(0, 1)
    };
};

#endif
