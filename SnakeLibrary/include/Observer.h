#ifndef SNAKEGAME_OBSERVER_H
#define SNAKEGAME_OBSERVER_H

#include "Game.h"

class Observer {
private:
    GamePtr game;
public:
    explicit Observer(const GamePtr &game);
    const GamePtr &getGame() const;
    virtual void report() = 0;
};


#endif //SNAKEGAME_OBSERVER_H
