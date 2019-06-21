#include "control_component.h"
#include "move_event.h"
#include "map.h"

std::pair<int, int> ControlComponent::move(const Map &m)
{
    return std::make_pair(0, 0);
}

Event *ControlComponent::makeTurn(const Map &m)
{
    MoveEvent *ev;
    auto [dx, dy] = move(m);
    std::pair<int, int> next = pos;
    next.first += dx;
    next.second += dy;

    ev = new MoveEvent(pos, next, e, m.nextTurn(m.getTurn()));
    return ev;
}
