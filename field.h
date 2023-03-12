#ifndef _FIELD_H
#define _FIELD_H
#include "player.h"

class Field {
public:
    Field(char input);

    char getFieldType();

    void trigger(Player *player);

private:
    char fieldType;
    char attribute;
};

#endif

