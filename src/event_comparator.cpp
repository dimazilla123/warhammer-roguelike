#include "event_comparator.h"
#include "control_event.h"

bool EventComparator::operator()(Event *a, Event *b) const
{
    ControlEvent *a_is_control = dynamic_cast<ControlEvent*>(a);
    ControlEvent *b_is_control = dynamic_cast<ControlEvent*>(b);
    if ((a_is_control && b_is_control) || (!a_is_control && !b_is_control))
        return (b_is_control == nullptr);
    return a->getTime() > b->getTime();
}
