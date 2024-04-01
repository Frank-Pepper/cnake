#include <iostream>

#include "CLIObserver.h"


CLIObserver::CLIObserver(const GamePtr &game) : Observer(game) {}

void CLIObserver::play()
{
    GamePtr  game = getGame();
    SnakePtr snake = game->getSnake();
    while(true)
	{
        report();
		char a = std::cin.get();
		std::cin.ignore(9999999,'\n');
        if( a == 'w')
        {
			game->increaseTime();
	        snake->moveAll(up);
		}
        else if ( a == 'd')
        {
	        game->increaseTime();
	        snake->moveAll(right);
        }
        else if ( a == 's')
        {
	        game->increaseTime();
	        snake->moveAll(down);
        }
        else if ( a == 'a')
        {
	        game->increaseTime();
	        snake->moveAll(left);
        }
		else
        {
	        game->increaseTime();
	        snake->moveAll(game->getSnake()->getHead()->getD());
		}
        if(game->checkCollision())
            break;
        if( game->checkWin() )
		{
            report();
            std::cout << "Gratulacje wygrałeś" << "\n";
            break;
        }
    }
}

void CLIObserver::report()
{
    GamePtr game = getGame();
    //std::cout << game->getSnake()->getFullInfo();
    //std::pair<int, int> fruitLocation = game->getFruit()->getLocation();
    print();
    //std::cout << "Fruit location: (" << fruitLocation.first << " ; " << fruitLocation.second << ") Snake size: " << game->getSnake()->getSegments().size() << "\n";
	std::cout << "Score: " << game->getScoreManager()->calculateScore() << " Your highscore: " << game->getScoreManager()->getHighScore() << std::endl;

}

void CLIObserver::print()
{
    GamePtr game = getGame();
    int x = game->getFruit()->getLocation().first;
    int y = game->getFruit()->getLocation().second;
    std::pair<int, int> HeadLocation  = game->getSnake()->getHead()->getLocation();
    for( int i = 0; i <= game->getXSize()+2; i++){
        std::cout << "#";
    }
    std::cout << "\n";
    for( int j = game->getYSize(); j > 0; j-- ){
        std::cout << "#";
        for( int i = 1; i <= game->getXSize(); i++){
            if( i == HeadLocation.first && j == HeadLocation.second ){
                std::cout << "H";
            }else if(game->getSnake()->isTaken(i, j)){
                std::cout << "S";
            }else if(i == x && j == y){
                std::cout << "F";
            }else{
                std::cout << " ";
            }
        }
        std::cout << "#" << "\n";
    }
    for( int i = 0; i <= game->getXSize()+2; i++)
	{
        std::cout << "#";
    }
    std::cout << "\n";
}