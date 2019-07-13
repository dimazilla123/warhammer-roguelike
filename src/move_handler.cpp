#include "move_handler.h"
#include "control_component.h"
#include "collide_component.h"
#include "collide_event.h"
#include "map.h"

bool is_passable(Map *m, std::pair<int, int> pos)
{
    auto [x, y] = pos;
    for (auto e : m->entities[x][y]) {
        auto col_c = e->get<CollideComponent>();
        if (col_c && col_c->getType() == CollisionType::CANNOT_PASS)
            return false;
    }
    return true;
}

void moveHandler(Map *m, Event *e)
{
    MoveEvent *ev = static_cast<MoveEvent*>(e);
    Entity *ent = ev->subject;
    auto check_bounds = [m](const std::pair<int, int> &pos) {
        auto [x, y] = pos;
        return 0 <= x && x < m->entities.size() &&
               0 <= y && y < m->entities[0].size();
    };
    if (check_bounds(ev->start_pos) && check_bounds(ev->targ_pos) && is_passable(m, ev->targ_pos)) {
        m->removeEntity(ev->start_pos, ent);
        m->addEntity(ev->targ_pos, ent);
        auto cc = ent->get<ControlComponent>();
        if (cc) {
            cc->setPos(ev->targ_pos);
        }
    }
    if (check_bounds(ev->targ_pos))
        for (auto w : m->entities[ev->targ_pos.first][ev->targ_pos.second]) {
            if (w->get<CollideComponent>()) {
                m->pushEvent(new CollideEvent(ent, w, e->getTime()));
            }
        }
    Event *ce = new ControlEvent(ent, e->getTime());
    m->pushEvent(ce);
}
