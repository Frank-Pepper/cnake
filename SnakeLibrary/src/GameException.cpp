#include "GameException.h"

GameException::GameException(std::string arg) : logic_error(arg) {}
