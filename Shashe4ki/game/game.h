#ifndef SHASHE4KI_GAME_H
#define SHASHE4KI_GAME_H

#include "field.h"
#include "../strategies/computerlogic.h"
#include "standardrules.h"


namespace game_space {
    void game(Field &gamefiel, char &curturn);

    void change_turn(char &curturn);

    template<typename T>
    void check_vulnerable_position(Field &gamefield, T &checkedforkill, char &curturn);

    template<typename T>
    bool check_for_kill(T &i, Field &gamefield, char &curturn);
}

#endif //SHASHE4KI_GAME_H