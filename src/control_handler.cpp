#include "control_handler.h"
#include "control_component.h"
#include "map.h"

void controlHandler(Map *m, Event *e)
{
    ControlEvent *ev = static_cast<ControlEvent*>(e);
    Entity *ent = ev->e;
    auto cc = ent->get<ControlComponent>();
    if (cc) {
        Event *add = cc->makeTurn(*m);
        m->pushEvent(add);
        //Event *ce = new ControlEvent(ent, add->getTime());
        //m->pushEvent(ce);
    }
}


