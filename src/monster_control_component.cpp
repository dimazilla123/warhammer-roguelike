#include "monster_control_component.h"

std::pair<int, int> MonsterControlComponent::move(const Map &m)
{
    turn ^= 1;
    return ret[turn ^ 1];
}
