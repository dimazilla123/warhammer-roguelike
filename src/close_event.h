#ifndef CLOSE_EVENT_H
#define CLOSE_EVENT_H

#include "event.h"
#include "game.h"

class CloseEvent : public Event {
public:
    CloseEvent(Game *g_, unsigned long long t_) : g(g_) { t = t_; };
    Game *getGame() const;
    void setGame(Game *m);
private:
    Game *g;
};

#endif
