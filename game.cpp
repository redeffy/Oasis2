#include "game.h"
#include <iostream>

using namespace std;

Game::Game() {
    cout << "Welcome to the game Oasis Crawler!\n"
            "Collect all the Relics and don't let the monster catch you\n"
            "How to navigate:\n"
            "w navigate UP\n"
            "s navigate DOWN\n"
            "d navigate to the RIGHT\n"
            "a navigate to the LEFT\n"
            "\n";
    myBoard = new Board();
    theMonster = new Monster();
    currentPlayer = new Player();
}

void Game::run() {

    while (1) {
        myBoard->print(currentPlayer, theMonster); //Calling the function

        currentPlayer->printStatus(); //Calling the function

        theMonster->movement(currentPlayer); //Calling the function

        currentPlayer->movement(); // Calling the function

        myBoard->triggerField(currentPlayer); // Calling the function

        if (currentPlayer->getRelics() >= myBoard->getNumRelics()) { // When the player has at least the number of relics that was originally in the board
            cout << "Congratulations! You found the relics and won the level " << myBoard->getNumRelics() << "!!!\n";
            myBoard->generateFields();
            currentPlayer->reset();
            theMonster->reset();
            cout << "Level " << myBoard->getNumRelics() << " starting now!\n";
        } else if (currentPlayer->getLives() <= 0) {
            cout << "Oh no! You lost all your lives\n";
            break;
        } else if (currentPlayer->getPositionC() == theMonster->getPositionC() &&
                   currentPlayer->getPositionL() == theMonster->getPositionL()) {
            cout << "Oh no! The monster caught you\n" << "GAME OVER\n";
            break;
        }
    }
}

Game::~Game() {
    delete myBoard;
    delete theMonster;
    delete currentPlayer;
}