#ifndef SHASHE4KI_GAME_H
#define SHASHE4KI_GAME_H

#include "../strategies/field.h"
#include "../strategies/computerlogic.h"
#include "../strategies/standardrules.h"


void game(Field &gamefield, char &curturn);

void change_turn(char &curturn);


#endif //SHASHE4KI_GAME_H
