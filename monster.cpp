#include "board.h"
#include "player.h"

Monster::Monster() {
    positionL = 4; //Initial position [4][4]
    positionC = 4;
}

void Monster::movement(Player *player) {
    if (player->getPositionL() > positionL) {
        positionL += 1;
    } else if (player->getPositionL() < positionL) {
        positionL -= 1;
    } else if (player->getPositionC() > positionC) {
        positionC += 1;
    } else if (player->getPositionC() < positionC) {
        positionC -= 1;
    }
}

void Monster::reset() {
    positionL = 4; //Initial position [4][4]
    positionC = 4;
}

int Monster::getPositionC() {
    return positionC;
}

int Monster::getPositionL() {
    return positionL;
}
