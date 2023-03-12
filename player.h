#ifndef _PLAYER_H
#define _PLAYER_H

class Player {
public:
    Player();

    void movement();

    int getPositionC();

    int getPositionL();

    int getRelics();

    int getLives();

    void addLife();

    void addRelics();

    void receiveBenefit(char attribute);

    void challenge(char attribute);

    void reset();

    void printStatus();

private:
    int lives;
    int relics;
    int positionC;
    int positionL;
    int strength;
    int intelligence;
    int agility;
    int agilityBenefits;
    int intelligenceBenefits;
    int strengthBenefits;
};

#endif



