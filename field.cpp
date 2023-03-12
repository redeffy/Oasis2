#include <cstdlib>
#include "field.h"


Field::Field(char input) { // Making the field an attribute
    fieldType = input;
    if (fieldType == 'd' || fieldType == 'l' || fieldType == 'r') {
        int number = rand() % 3;

        if (number == 0) {
            attribute = 'a';
        } else if (number == 1) {
            attribute = 's';
        } else if (number == 2) {
            attribute = 'i';
        }
    }
}

void Field::trigger(Player *player) { //Add lives, reduce lives or get a relic
    if (fieldType == 'd') {
        player->challenge(attribute);
    } else if (fieldType == 'l') {
        player->addLife();
        player->receiveBenefit(attribute);
    } else if (fieldType == 'r') {
        player->addRelics();
        player->receiveBenefit(attribute);
    }
    fieldType = 'e'; //Setting the field to empty field after the character walked there
}

char Field::getFieldType() {
    return fieldType;
}

