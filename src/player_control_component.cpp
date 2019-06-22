#include "player_control_component.h"
#include "ascii_component.h"
#include "close_event.h"
#include "move_event.h"
#include <ncurses.h>
#include "map.h"

PlayerControlComponent::PlayerControlComponent(Game *g, std::pair<int, int> pos) : ControlComponent(pos),
    game(g)
{
    initscr();
    noecho();
    curs_set(0);
    h = g->getHeight();
    w = g->getWidth();
    messageline = newwin(3, w, 1, 1);
    field = newwin(h, w, 4, 1);
    statline = newwin(3, w, h + 4, 1);
}

PlayerControlComponent::~PlayerControlComponent()
{
    endwin();
}

Event *PlayerControlComponent::makeTurn(const Map &m)
{
    refresh();
    wclear(field);
    box(field, 0, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (auto e : m.entities[i][j]) {
                auto ac = e->get<AsciiComponent>();
                if (ac)
                    mvwaddch(field, i + 1, j + 1, ac->getChar());
            }
        }
    }
    wrefresh(field);
    char c = getch();
    auto ret = std::make_pair(0, 0);
    switch (c) {
        case 'q':
            return new CloseEvent(game, 0);
            break;
        case 'h':
            ret = std::make_pair(0, -1);
            break;
        case 'l':
            ret = std::make_pair(0, 1);
            break;
        case 'k':
            ret = std::make_pair(-1, 0);
            break;
        case 'j':
            ret = std::make_pair(1, 0);
            break;
    }
    wclear(messageline);
    box(messageline, 0, 0);
    mvwprintw(messageline, 1, 1, "Move vector is %d %d", ret.first, ret.second);
    wrefresh(messageline);
    box(statline, 0, 0);
    wrefresh(statline);
    auto next = pos;
    next.first += ret.first;
    next.second += ret.second;
    return new MoveEvent(pos, next, e, m.nextTurn(m.getTurn()));
}

void PlayerControlComponent::pullMessage(const std::string &s)
{
    last_message = s;
}
