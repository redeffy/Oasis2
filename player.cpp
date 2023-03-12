#include <iostream>
#include "player.h"

using namespace std;

Player::Player() {
    agility = 1;
    strength = 1;
    intelligence = 1;
    while (1) {
        char input;
        cout << "Which of these 3 options would you like to be?\n"
                "Press 1 for NINJA\n"
                "Press 2 for SAMURAI\n"
                "Press 3 for SAGE\n"
                "Your choice? "
                "\n";
        cin >> input;
        if (input == '1') {
            agility = 3;
            break;
        } else if (input == '2') {
            strength = 3;
            break;
        } else if (input == '3') {
            intelligence = 3;
            break;
        } else {
            cout << "Invalid input! Try again!\n";
        }
    }
    intelligenceBenefits = 0;
    agilityBenefits = 0;
    strengthBenefits = 0;
    reset();
}

void Player::movement() {
    while (1) {
        char input;
        cout << "Your input?:\n";
        cin >> input;
        //How to make the character move and limiting the moves to the board
        if (input == 'w' && positionL > 0) {  //The character can just go Up if he is NOT in the line 0.
            positionL -= 1;
            break;
        } else if (input == 's' && positionL < 4) { //The character can just go down if he is NOT in the line 4.
            positionL += 1;
            break;
        } else if (input == 'd' &&
                   positionC < 4) { //The character can just go to the right if he is NOT in the column 4.
            positionC += 1;
            break;
        } else if (input == 'a' &&
                   positionC > 0) { //The character can just go to the left if he is NOT in the column 0.
            positionC -= 1;
            break;
        } else {
            cout << "Invalid input. Try again"
                    "\n";
        }
    }
}

void Player::challenge(char attribute) { //The player will be challenged in one of the attributes
    int currentValue; //Value is the strength, intelligence and agility that he currently have
    int *numBenefits; // Saves the benefit to reduce them later
    switch (attribute) {
        case 'a':
            currentValue = agility; //Use agility value for the random number
            numBenefits = &agilityBenefits;
            break;
        case 'i':
            currentValue = intelligence;
            numBenefits = &intelligenceBenefits;
            break;
        case 's':
            currentValue = strength;
            numBenefits = &strengthBenefits;
            break;
    }
    int randomNumber = rand() % (4 - currentValue); // The higher the current value is, the easy it gets.
    int guess;
    cout << "You are trapped in a danger field and need to play the mini game to escape!\n"
            "Guess a number between 0 and " << (4 - currentValue) << ":\n";
    while (1) {
        cin >> guess;
        if (guess >= 4 - currentValue && guess <= 0) {
            cout << "Wrong input. Try again!\n";
        } else {
            break;
        }
    }
    if (guess == randomNumber) {
        cout << "You guessed correct and passed the challenge!\n" << "\n";
    } else if (guess <= 4 - currentValue && guess >= 0) {
        // The user guessed wrong, so we check if he has a benefit in this attribute
        if (*numBenefits > 0) {
            cout << "You guessed wrong but you are not spending a life because you found an item earlier.\n" << "\n";
            *numBenefits = *numBenefits - 1;
        } else {
            cout << "You guessed wrong and lost a life!\n" << "\n";
            lives--;
        }

    }
}

void Player::receiveBenefit(char attribute) {
    if (attribute == 'a') {
        agilityBenefits++;
        cout << "You found an agility item!\n";
    } else if (attribute == 'i') {
        intelligenceBenefits++;
        cout << "You found an intelligence item!\n";
    } else if (attribute == 's') {
        strengthBenefits++;
        cout << "You found an strength item!\n";
    }
}

void Player::reset() {
    lives = 3; //Initial sets
    relics = 0;
    positionL = 0; //Initial position [0][0]
    positionC = 0;
}

void Player::printStatus() {
    cout << "Your Relics: " << relics << "\n";
    cout << "Your Lives: " << lives << "\n";
    cout << "Your Agility Items: " << agilityBenefits << "\n";
    cout << "Your Intelligence Items: " << intelligenceBenefits << "\n";
    cout << "Your Strength Items: " << strengthBenefits << "\n";
            cout << "\n";
}

int Player::getPositionC() {
    return positionC;
}

int Player::getPositionL() {
    return positionL;
}

int Player::getRelics() {
    return relics;
}

int Player::getLives() {
    return lives;
}

void Player::addLife() {
    lives += 1;
};

void Player::addRelics() {
    relics += 1;
}
