#ifndef GAME_H
#define GAME_H

#include "map.h"

class Game {
public:
    Game(size_t h, size_t w);
    ~Game();
    void gameLoop();
    void exit();
private:
    bool to_exit = false;
    Map *map;

    Entity *create_monster();
    Entity *create_player();
};

#endif
