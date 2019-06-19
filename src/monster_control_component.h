#ifndef MONSTER_CONTROL_COMPONENT
#define MONSTER_CONTROL_COMPONENT

#include "control_component.h"

class MonsterControlComponent : public ControlComponent {
public:
    std::pair<int, int> move(const Map &m);
};

#endif
