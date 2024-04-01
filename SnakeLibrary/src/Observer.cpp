#include "Observer.h"

Observer::Observer(const GamePtr &game) : game(game) {
    if(game == nullptr){
        throw GameException("Game is a nullptr");
    }
}

const GamePtr &Observer::getGame() const {
    return game;
}


