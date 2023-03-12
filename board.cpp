#include <cstdlib>
#include <iostream>
#include "board.h"

using namespace std;

Board::Board() {
    level = 0; //Initialize the level
    generateFields();
}

int Board::getNumRelics() {
    return numRelics;
}

void Board::print(Player *player, Monster *monster) { //Printing the board
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {
            if (player->getPositionC() == c && player->getPositionL() == l) {
                cout << "X "; //Making our character an X
            } else if (monster->getPositionC() == c && monster->getPositionL() == l) {
                cout << "M "; //Making the monster an M
            } else {
                cout << fields[l][c]->getFieldType() << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void Board::generateFields() { //Define the fields
    level++; //Initialized with 0 and setting to 1
    while (numRelics != level) { //Generate fields as long until the numRelics is equal to level
        numRelics = 0; //Reset to 0 because it would add the old numRelics to the last loop iteration
        for (int l = 0; l < 5; l++) {
            for (int c = 0; c < 5; c++) {
                if (l == 0 && c == 0){
                    fields[l][c] = new Field('e'); // The first field [0][0], will be always an empty
                    continue; //Go back to the loop
                }
                int number = rand() % 10; // Get the value between 0 and 9.(because of the modulo)
                if (number < 4) {//40% to be empty
                    fields[l][c] = new Field('e'); //Empty field, Assigning the field instead of char
                } else if (number < 8) { //40% to be danger
                    fields[l][c] = new Field('d'); //Danger field
                } else if (number < 9) { //10% to be life
                    fields[l][c] = new Field('l'); //Life field
                } else { // 10% to be relic
                    numRelics++; //So then I know how many relics are in the board
                    fields[l][c] = new Field('r'); //Relics field
                }
            }
        }
    }
}

void Board::triggerField(Player *player) { //Check where the player is and trigger the field (danger/relic/life field)
    fields[player->getPositionL()][player->getPositionC()]->trigger(player);
}

Board::~Board() { //Destructor (Because the field attached to the board, and after deleting the board the field needs to be clean up too)
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) { //releasing every field
            delete fields[l][c];
        }
    }
}
