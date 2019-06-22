#ifndef EVENT_COMPARATOR_H
#define EVENT_COMPARATOR_H

#include "event.h"

struct EventComparator {
    bool operator()(Event *a, Event *b) const;
};

#endif
