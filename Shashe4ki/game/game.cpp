#include "game.h"

void game(Field &gamefield, char &curturn) {
    if (gamefield.whiteturns.empty()) {
        cout << "\nBlack Wins\n";
        exit(0);
    } else if (gamefield.blackturns.empty()) {
        cout << "\nWhite Wins\n";
        exit(0);
    }
    map<pair<short, short>, bool> checkedforkill;
    if (curturn == 'b') {
        for (auto i : gamefield.whiteturns) {
            checkedforkill[{i.first.first, i.first.second}] = true;
        }
    } else
        for (auto i : gamefield.blackturns) {
            checkedforkill[{i.first.first, i.first.second}] = true;
        }
    while (!checkedforkill.empty()) {
        auto i = checkedforkill.begin();
        if (i->first.first + 1 < 9 && i->first.second + 1 < 9) {
            int function_worked_times = 0;
            short left_top = i->first.first;
            short right_top = i->first.second;
            while (can_be_killed(left_top, right_top, gamefield)) {
                function_worked_times += 1;
                if (gamefield.field[left_top][right_top] == 'w' && left_top == 1) {
                    gamefield.field[left_top][right_top] = 'q';
                    gamefield.white_queens[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black_kings[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return;
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
                    gamefield.white_queens[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black_kings[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return;
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
                    gamefield.white_queens[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black_kings[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return;
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
                    gamefield.white_queens[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black_kings[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return;
            }
        }
        checkedforkill.erase({i->first.first, i->first.second});
    }
    vector<short> input;
    if ((curturn == 'w' && gamefield.white_is_computer_ == true) ||
        (curturn == 'b' && gamefield.black_is_computer_ == true)) {
        input = type_of_strategy(curturn, gamefield);
    } else {
        input = input_coords();
        while (!check_correct(input, curturn, gamefield))
            input = input_coords();
    }
    gamefield.turn(input[0], input[1], input[2], input[3]);
    if (input[2] != 1 && input[2] != 8 && input[3] != 1 && input[3] != 8) {
        int function_worked_times = 0;
        while (can_be_killed(input[2], input[3], gamefield)) {
            function_worked_times += 1;
            if (gamefield.field[input[2]][input[3]] == 'w' && input[2] == 1) {
                gamefield.field[input[2]][input[3]] = 'q';
                gamefield.white_queens[{input[2], input[3]}] = true;
            } else if (gamefield.field[input[2]][input[3]] == 'b' && input[2] == 8) {
                gamefield.field[input[2]][input[3]] = 'k';
                gamefield.black_kings[{input[2], input[3]}] = true;
            }
        }
        if (function_worked_times) {
            if (function_worked_times % 2 == 0)
                change_turn(curturn);
            return;
        }
    }
    if (curturn == 'w') {
        for (auto i : gamefield.whiteturns) {
            checkedforkill[{i.first.first, i.first.second}] = true;
        }
    } else
        for (auto i : gamefield.blackturns) {
            checkedforkill[{i.first.first, i.first.second}] = true;
        }
    while (!checkedforkill.empty()) {
        auto i = checkedforkill.begin();
        if (i->first.first + 1 < 9 && i->first.second + 1 < 9) {
            int function_worked_times = 0;
            short left_top = i->first.first;
            short right_top = i->first.second;
            while (can_be_killed(left_top, right_top, gamefield)) {
                function_worked_times += 1;
                if (gamefield.field[left_top][right_top] == 'w' && left_top == 1) {
                    gamefield.field[left_top][right_top] = 'q';
                    gamefield.white_queens[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black_kings[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return;
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
                    gamefield.white_queens[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black_kings[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return;
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
                    gamefield.white_queens[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black_kings[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return;
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
                    gamefield.white_queens[{left_top, right_top}] = true;
                } else if (gamefield.field[left_top][right_top] == 'b' && left_top == 8) {
                    gamefield.field[left_top][right_top] = 'k';
                    gamefield.black_kings[{left_top, right_top}] = true;
                }
            }
            if (function_worked_times) {
                if (function_worked_times % 2 == 0)
                    change_turn(curturn);
                return;
            }
        }
        checkedforkill.erase({i->first.first, i->first.second});
    }
    change_turn(curturn);

}


void change_turn(char &curturn) {
    curturn = (curturn == 'w') ? 'b' : 'w';
}

