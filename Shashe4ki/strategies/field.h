#ifndef SHASHE4KI_FIELD_H
#define SHASHE4KI_FIELD_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Field {
public:
    Field(bool white_is_computer, bool black_is_computer);

    Field(bool white_is_computer, bool black_is_computer, bool tournament);

    void write();

    char returncolor(short X, short Y);

    void turn(short fromX, short fromY, short toX, short toY);

    vector<vector<char> > field;
    map<pair<short, short>, bool> blackturns;
    map<pair<short, short>, bool> whiteturns;
    map<pair<short, short>, bool> white_queens;
    map<pair<short, short>, bool> black_kings;
    bool white_is_computer_ = false;
    bool black_is_computer_ = false;
    short type_of_strategy_white;
    short type_of_strategy_black;
};

#endif //SHASHE4KI_FIELD_H
