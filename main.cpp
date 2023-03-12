#include <iostream>
#include "board.h"
#include "game.h"

using namespace std;

void testGenerateFields() {
    Board board;
// Test that the minimum number of relics is incremented
    int originalMinNumRelics = board.getNumRelics();
    board.generateFields();
    assert(board.getNumRelics() == originalMinNumRelics + 1);
}

int main() {
    testGenerateFields();
    srand(time(NULL)); // Expression to randomize based on the time
    Game *theGame = new Game();
    theGame->run();
    delete theGame;
    return 0;
}