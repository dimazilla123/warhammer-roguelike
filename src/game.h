#ifndef GAME_H
#define GAME_H

#include "map.h"


class Game {
public:
    Game(size_t h, size_t w);
    ~Game();
    void gameLoop();
    void exit();
    int getHeight() const;
    int getWidth() const;
private:
    bool to_exit = false;
    Map *map;

    Entity *create_monster(int x, int y);
    Entity *create_player(int x, int y);
    Entity *create_wall(int x, int y);
};

#endif
