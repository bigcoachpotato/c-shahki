#include "field.h"

Field::Field(bool white_is_computer, bool black_is_computer) {
    white_is_computer_ = white_is_computer;
    black_is_computer_ = black_is_computer;
    if (white_is_computer)
        type_of_strategy_white = 1;
    if (black_is_computer)
        type_of_strategy_black = 1;
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
                        whiteturns[{i, j}] = true;
                    } else {
                        blackturns[{i, j}] = true;
                    }
                    field[i][j] = curColor;
                    j += 2;
                    continue;
                } else {
                    if (curColor == 'w') {
                        whiteturns[{i, j + 1}] = true;
                    } else if (curColor == 'b') {
                        blackturns[{i, j + 1}] = true;
                    }
                    field[i][j + 1] = curColor;
                    j += 2;
                }
            }
        }
    }
}

Field::Field(bool white_is_computer, bool black_is_computer, bool tournament) {
    white_is_computer_ = white_is_computer;
    black_is_computer_ = black_is_computer;
    type_of_strategy_white = 1;
    type_of_strategy_black = 2;
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
                        whiteturns[{i, j}] = true;
                    } else {
                        blackturns[{i, j}] = true;
                    }
                    field[i][j] = curColor;
                    j += 2;
                    continue;
                } else {
                    if (curColor == 'w') {
                        whiteturns[{i, j + 1}] = true;
                    } else if (curColor == 'b') {
                        blackturns[{i, j + 1}] = true;
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
    if (blackturns.count({fromX, fromY}) || whiteturns.count({fromX, fromY})) {
        if (blackturns.count({fromX, fromY})) {
            if (black_kings.count({fromX, fromY})) {
                black_kings.erase({fromX, fromY});
                black_kings[{toX, toY}] = true;
            }
            blackturns.erase({fromX, fromY});
            blackturns[{toX, toY}] = true;
        } else {
            if (white_queens.count({fromX, fromY})) {
                white_queens.erase({fromX, fromY});
                white_queens[{toX, toY}] = true;
            }
            whiteturns.erase({fromX, fromY});
            whiteturns[{toX, toY}] = true;
        }
        field[toX][toY] = field[fromX][fromY];
        field[fromX][fromY] = '-';
        if (field[toX][toY] == 'w' && toX == 1) {
            field[toX][toY] = 'q';
            white_queens[{toX, toY}] = true;
        } else if (field[toX][toY] == 'b' && toX == 8) {
            field[toX][toY] = 'k';
            black_kings[{toX, toY}] = true;
        }
        return;
    }
    throw exception();
}
