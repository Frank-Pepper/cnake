#ifndef SNAKEGAME_GAMEEXCEPTION_H
#define SNAKEGAME_GAMEEXCEPTION_H

#include <stdexcept>

class GameException : public std::logic_error {
public:
    GameException(std::string arg);
};


#endif //SNAKEGAME_GAMEEXCEPTION_H
