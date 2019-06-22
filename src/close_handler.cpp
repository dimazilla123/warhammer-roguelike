#include "close_handler.h"
#include "close_event.h"
#include "map.h"

void closeHandler(Map *m, Event* e)
{
    CloseEvent *ev = static_cast<CloseEvent*>(e);
    ev->getGame()->exit();
}

