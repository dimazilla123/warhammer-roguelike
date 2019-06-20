#include "control_event.h"

ControlEvent::ControlEvent(Entity *e_, unsigned long long t_) : e(e_)
{
    t = t_;
}
