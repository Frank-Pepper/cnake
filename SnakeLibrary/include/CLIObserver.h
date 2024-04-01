#ifndef SNAKEGAME_CLIOBSERVER_H
#define SNAKEGAME_CLIOBSERVER_H

#include "Observer.h"

class CLIObserver : public Observer {
public:
    explicit CLIObserver(const GamePtr &game);
    void play();
    void report() override;
    void print();
};


#endif //SNAKEGAME_CLIOBSERVER_H
