#include <memory>
#include "field.h"
#include "../strategies/computer_strategy_1.h"
#include "../strategies/computer_strategy_2.h"
#include "../strategies/Person_Interface.h"
#include "../strategies/basic_interface.h"

using namespace std;

Basic_interface *Field::take_ptr(int z) {
    if (z == 1) {
        Computer_strategy_1 *computer_Strategy1 = new Computer_strategy_1();
        return computer_Strategy1;
    } else if (z == 2) {
        Computer_strategy_2 *computer_Strategy2 = new Computer_strategy_2();
        return computer_Strategy2;
    } else if (z == 3) {
        User *computer_Strategy2 = new User();
        return computer_Strategy2;
    }
}

Field::Field(bool white_is_computer, bool black_is_computer) {
    white = new Storage;
    black = new Storage;
    white->me = take_ptr(3);
    black->me = take_ptr(3);
    white->i_am_computer = false;
    black->i_am_computer = false;
    if (white_is_computer) {
        white->i_am_computer = true;
        white->me = take_ptr(1);
    }
    if (black_is_computer) {
        black->i_am_computer = true;
        black->me = take_ptr(1);
    }
    field.resize(11, vector<char>(11, '0'));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            field[i][j] = '-';
        }
    }
    for (int i = 1; i < 9; i++) {
        field[0][i] = i + '0';
        field[i][0] = i + '0';
    }
    field[0][0] = ' ';
    for (int i = 1; i < 9; i++) {
        if (i < 4 || i >= 6) {
            char curColor = (i < 4) ? 'b' : 'w';
            for (int j = 1; j < 9;) {
                if (i % 2 == 0) {
                    if (curColor == 'w') {
                        white->myturns[{i, j}] = true;
                    } else {
                        black->myturns[{i, j}] = true;
                    }
                    field[i][j] = curColor;
                    j += 2;
                    continue;
                } else {
                    if (curColor == 'w') {
                        white->myturns[{i, j + 1}] = true;
                    } else if (curColor == 'b') {
                        black->myturns[{i, j + 1}] = true;
                    }
                    field[i][j + 1] = curColor;
                    j += 2;
                }
            }
        }
    }
}


Field::Field(bool white_is_computer, bool black_is_computer, bool tournament) {
    white = new Storage;
    black = new Storage;
    white->i_am_computer = white_is_computer;
    black->i_am_computer = black_is_computer;
    white->me = take_ptr(1);
    black->me = take_ptr(2);
    field.resize(11, vector<char>(11, '0'));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            field[i][j] = '-';
        }
    }
    for (int i = 1; i < 9; i++) {
        field[0][i] = i + '0';
        field[i][0] = i + '0';
    }
    field[0][0] = ' ';
    for (int i = 1; i < 9; i++) {
        if (i < 4 || i >= 6) {
            char curColor = (i < 4) ? 'b' : 'w';
            for (int j = 1; j < 9;) {
                if (i % 2 == 0) {
                    if (curColor == 'w') {
                        white->myturns[{i, j}] = true;
                    } else {
                        black->myturns[{i, j}] = true;
                    }
                    field[i][j] = curColor;
                    j += 2;
                    continue;
                } else {
                    if (curColor == 'w') {
                        white->myturns[{i, j + 1}] = true;
                    } else if (curColor == 'b') {
                        black->myturns[{i, j + 1}] = true;
                    }
                    field[i][j + 1] = curColor;
                    j += 2;
                }
            }
        }
    }
}

void Field::write() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << field[i][j] << ' ';
        }
        cout << '\n';
    }
}

char Field::returncolor(short X, short Y) {
    return field[X][Y];
}

void Field::turn(short fromX, short fromY, short toX, short toY) {
    if (black->myturns.count({fromX, fromY}) || white->myturns.count({fromX, fromY})) {
        if (black->myturns.count({fromX, fromY})) {
            if (black->my_king_turns.count({fromX, fromY})) {
                black->my_king_turns.erase({fromX, fromY});
                black->my_king_turns[{toX, toY}] = true;
            }
            black->myturns.erase({fromX, fromY});
            black->myturns[{toX, toY}] = true;
        } else {
            if (white->my_king_turns.count({fromX, fromY})) {
                white->my_king_turns.erase({fromX, fromY});
                white->my_king_turns[{toX, toY}] = true;
            }
            white->myturns.erase({fromX, fromY});
            white->myturns[{toX, toY}] = true;
        }
        field[toX][toY] = field[fromX][fromY];
        field[fromX][fromY] = '-';
        if (field[toX][toY] == 'w' && toX == 1) {
            field[toX][toY] = 'q';
            white->my_king_turns[{toX, toY}] = true;
        } else if (field[toX][toY] == 'b' && toX == 8) {
            field[toX][toY] = 'k';
            black->my_king_turns[{toX, toY}] = true;
        }
        return;
    }
    throw exception();
}

void Field::field_restore() {
    field.clear();
    winner = 'n';
    white->my_king_turns.clear();
    white->myturns.clear();
    black->my_king_turns.clear();
    black->myturns.clear();
    field.resize(11, vector<char>(11, '0'));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            field[i][j] = '-';
        }
    }
    for (int i = 1; i < 9; i++) {
        field[0][i] = i + '0';
        field[i][0] = i + '0';
    }
    field[0][0] = ' ';
    for (int i = 1; i < 9; i++) {
        if (i < 4 || i >= 6) {
            char curColor = (i < 4) ? 'b' : 'w';
            for (int j = 1; j < 9;) {
                if (i % 2 == 0) {
                    if (curColor == 'w') {
                        white->myturns[{i, j}] = true;
                    } else {
                        black->myturns[{i, j}] = true;
                    }
                    field[i][j] = curColor;
                    j += 2;
                    continue;
                } else {
                    if (curColor == 'w') {
                        white->myturns[{i, j + 1}] = true;
                    } else if (curColor == 'b') {
                        black->myturns[{i, j + 1}] = true;
                    }
                    field[i][j + 1] = curColor;
                    j += 2;
                }
            }
        }
    }
}