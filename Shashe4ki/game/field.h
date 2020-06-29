#ifndef SHASHE4KI_FIELD_H
#define SHASHE4KI_FIELD_H

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "../strategies/computerlogic.h"
#include "../strategies/basic_interface.h"

using namespace std;

class Basic_interface;

class Computer_interface;

struct Storage {
    map<pair<short, short>, bool> myturns;
    map<pair<short, short>, bool> my_king_turns;
    bool i_am_computer = false;
    Basic_interface *me = nullptr;
};

class Field {
public:
    Basic_interface *take_ptr(int z);

    Field(bool white_is_computer, bool black_is_computer);

    Field(bool white_is_computer, bool black_is_computer, bool tournament);

    void field_restore();

    void write();

    char returncolor(short X, short Y);

    void turn(short fromX, short fromY, short toX, short toY);

    vector<vector<char> > field;
    Storage *white = nullptr;
    Storage *black = nullptr;
    char winner = 'n';
};


#endif //SHASHE4KI_FIELD_H