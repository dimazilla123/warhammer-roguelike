#include "player_control_component.h"
#include "ascii_component.h"
#include <ncurses.h>
#include "map.h"

PlayerControlComponent::PlayerControlComponent()
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
    return std::make_pair(0, 0);
}
