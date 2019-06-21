#ifndef CLOSE_EVENT_H
#define CLOSE_EVENT_H

#include "event.h"
#include "game.h"

class CloseEvent : public Event {
public:
    CloseEvent(Game *g_) : g(g_) {};
    Game *getGame() const;
    void setGame(Game *m);
private:
    Game *g;
};

#endif
