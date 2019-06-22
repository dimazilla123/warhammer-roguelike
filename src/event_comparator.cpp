#include "event_comparator.h"
#include "control_event.h"
#include "control_event.h"
#include "control_event.h"

bool EventComparator::operator()(Event *a, Event *b) const
{
    return a->getTime() > b->getTime();
}
