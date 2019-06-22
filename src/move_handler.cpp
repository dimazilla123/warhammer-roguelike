#include "move_handler.h"
#include "control_component.h"
#include "map.h"

void moveHandler(Map *m, Event *e)
{
    MoveEvent *ev = static_cast<MoveEvent*>(e);
    Entity *ent = ev->subject;
    auto check_bounds = [m](const std::pair<int, int> &pos) {
        auto [x, y] = pos;
        return 0 <= x && x < m->entities.size() &&
               0 <= y && y < m->entities[0].size();
    };
    if (check_bounds(ev->start_pos) && check_bounds(ev->targ_pos)) {
        m->removeEntity(ev->start_pos, ent);
        m->addEntity(ev->targ_pos, ent);
        auto cc = ent->get<ControlComponent>();
        if (cc) {
            cc->setPos(ev->targ_pos);
        }
    }
    Event *ce = new ControlEvent(ent, e->getTime());
    m->pushEvent(ce);
}
