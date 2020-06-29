#include "game.h"

void game_space::game(Field &gamefield, char &curturn) {
    if (gamefield.white->me->win_step(gamefield) != 'n') {
        gamefield.winner = gamefield.white->me->win_step(gamefield);
    }
    map<pair<short, short>, bool> checkedforkill;
    check_vulnerable_position(gamefield, checkedforkill, curturn);
    while (!checkedforkill.empty()) {
        auto i = checkedforkill.begin();
        if (check_for_kill(i, gamefield, curturn))
            return;
        checkedforkill.erase({i->first.first, i->first.second});
    }
    vector<short> input;
    if (curturn == 'w' && gamefield.white->i_am_computer == true) {
        input = gamefield.white->me->choose_way(curturn, gamefield);
    } else if (curturn == 'b' && gamefield.black->i_am_computer == true) {
        input = gamefield.black->me->choose_way(curturn, gamefield);
    } else {
        input = input_coords();
        Basic_interface *z;
        if (curturn == 'w')
            z = gamefield.white->me;
        else
            z = gamefield.black->me;
        while (!z->check_correct(input, curturn, gamefield))
            input = input_coords();
    }
    if (input[0] == -1)
        return;
    gamefield.turn(input[0], input[1], input[2], input[3]);
    if (input[2] != 1 && input[2] != 8 && input[3] != 1 && input[3] != 8) {
        int function_worked_times = 0;
        while (can_be_killed(input[2], input[3], gamefield)) {
            function_worked_times += 1;
            if (gamefield.field[input[2]][input[3]] == 'w' && input[2] == 1) {
                gamefield.field[input[2]][input[3]] = 'q';
                gamefield.white->my_king_turns[{input[2], input[3]}] = true;
            } else if (gamefield.field[input[2]][input[3]] == 'b' && input[2] == 8) {
                gamefield.field[input[2]][input[3]] = 'k';
                gamefield.black->my_king_turns[{input[2], input[3]}] = true;
            }
        }
        if (function_worked_times) {
            if (function_worked_times % 2 == 0)
                change_turn(curturn);
            return;
        }
    }
    check_vulnerable_position(gamefield, checkedforkill, curturn);
    while (!checkedforkill.empty()) {
        auto i = checkedforkill.begin();
        if (check_for_kill(i, gamefield, curturn))
            return;
        checkedforkill.erase({i->first.first, i->first.second});
    }
    change_turn(curturn);

}

template<typename T>
bool game_space::check_for_kill(T &i, Field &gamefield, char &curturn) {
    {
        if (i->first.first + 1 < 9 && i->first.second + 1 < 9) {
            int function_worked_times = 0;
            short left_top = i->first.first;
            short right_top = i->first.second;
            while (can_be_killed(left_top, right_top, gamefield)) {
                function_worked_times += 1;
                if (gamefield.field[left_top][right_top] == 'w' && left_top == 1) {
                    gamefield.field[left_top][right_top] = 'q';
                    gamefield.white->my_king_turns[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black->my_king_turns[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return true;
            }
        }
        if (i->first.first - 1 > 0 && i->first.second - 1 > 0) {
            int function_worked_times = 0;
            short left_top = i->first.first;
            short right_top = i->first.second;
            while (can_be_killed(left_top, right_top, gamefield)) {
                function_worked_times += 1;
                if (gamefield.field[left_top][right_top] == 'w' && left_top == 1) {
                    gamefield.field[left_top][right_top] = 'q';
                    gamefield.white->my_king_turns[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black->my_king_turns[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return true;
            }
        }
        if (i->first.first - 1 > 0 && i->first.second + 1 < 9) {
            int function_worked_times = 0;
            short left_top = i->first.first;
            short right_top = i->first.second;
            while (can_be_killed(left_top, right_top, gamefield)) {
                function_worked_times += 1;
                if (gamefield.field[left_top][right_top] == 'w' && left_top == 1) {
                    gamefield.field[left_top][right_top] = 'q';
                    gamefield.white->my_king_turns[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black->my_king_turns[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return true;
            }
        }
        if (i->first.first + 1 < 9 && i->first.second - 1 > 0) {
            int function_worked_times = 0;
            short left_top = i->first.first;
            short right_top = i->first.second;
            while (can_be_killed(left_top, right_top, gamefield)) {
                function_worked_times += 1;
                if (gamefield.field[left_top][right_top] == 'w' && left_top == 1) {
                    gamefield.field[left_top][right_top] = 'q';
                    gamefield.white->my_king_turns[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black->my_king_turns[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return true;
            }
        }
        return false;
    }
}


template<typename T>
void game_space::check_vulnerable_position(Field &gamefield, T &checkedforkill, char &curturn) {
    if (curturn == 'b') {
        for (auto i : gamefield.white->myturns) {
            checkedforkill[{i.first.first, i.first.second}] = true;
        }
    } else
        for (auto i : gamefield.black->myturns) {
            checkedforkill[{i.first.first, i.first.second}] = true;
        }
}

void game_space::change_turn(char &curturn) {
    curturn = (curturn == 'w') ? 'b' : 'w';
}


