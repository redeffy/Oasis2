#ifndef BOARD_H
#define BOARD_H
#include "monster.h"
#include "field.h"

class Board {
public:
    Board();

    void generateFields();

    int getNumRelics();

    void print(Player *player, Monster *monster);

    void triggerField(Player *player);

    ~Board();

private:
    Field *fields[5][5]; //Make board
    int numRelics; //The number of relics on the board
    int level;
};

#endif