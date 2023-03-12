#ifndef OASIS2_GAME_H
#define OASIS2_GAME_H

#include "board.h"

class Game {
public:
    Game();

    void run();

    ~Game(); //Destructor (to release memory)

private:
    Board *myBoard;
    Monster *theMonster;
    Player *currentPlayer;
};


#endif //OASIS2_GAME_H
