#include "player_control_component.h"
#include "ascii_component.h"
#include <ncurses.h>
#include "map.h"

PlayerControlComponent::PlayerControlComponent(Game *g) : game(g)
{
    initscr();
    noecho();
}

PlayerControlComponent::~PlayerControlComponent()
{
    endwin();
}

std::pair<int, int> PlayerControlComponent::move(const Map &m)
{
    int h = m.entities.size();
    int w = m.entities[0].size();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (auto e : m.entities[i][j]) {
                auto ac = e->get<AsciiComponent>();
                if (ac)
                    mvaddch(i, j, ac->getChar());
            }
        }
    }
    char c = getch();
    switch (c) {
        case 'q':
            game->exit();
            break;
        case 'h':
            return std::make_pair(0, -1);
            break;
        case 'l':
            return std::make_pair(0, 1);
            break;
        case 'k':
            return std::make_pair(-1, 0);
            break;
        case 'j':
            return std::make_pair(1, 0);
            break;
        default:
            return std::make_pair(0, 0);
    }
}
