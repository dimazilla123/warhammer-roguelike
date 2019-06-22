#include "close_event.h"

Game *CloseEvent::getGame() const
{
    return g;
}

void CloseEvent::setGame(Game *g_)
{
    g = g_;
}
