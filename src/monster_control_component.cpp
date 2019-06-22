#include "monster_control_component.h"
#include "move_event.h"
#include "map.h"

std::pair<int, int> MonsterControlComponent::move(const Map &m)
{
    turn ^= 1;
    return ret[turn ^ 1];
}

Event *MonsterControlComponent::makeTurn(const Map &m)
{
    MoveEvent *ev;
    auto [dx, dy] = move(m);
    std::pair<int, int> next = pos;
    next.first += dx;
    next.second += dy;

    ev = new MoveEvent(pos, next, e, m.nextTurn(m.getTurn()));
    return ev;
}
