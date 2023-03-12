#ifndef _MONSTER_H
#define _MONSTER_H

#include "player.h"

class Monster {
public:
    Monster();

    void movement(Player *player);

    int getPositionC();

    int getPositionL();

    void reset();

private:
    int positionC;
    int positionL;
};

#endif

