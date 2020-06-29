#ifndef SHASHE4KI_BASIC_INTERFACE_H
#define SHASHE4KI_BASIC_INTERFACE_H

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Field;

class Basic_interface {
public:
    virtual bool check_correct(vector<short> situation, char &curturn, Field &gamefield) = 0;

    virtual vector<short> choose_way(char &who_am_i_, Field &field) = 0;

    virtual pair<short, short> choose_one_of_(map<pair<short, short>, bool> &storage_killers) = 0;

    virtual char win_step(Field &gamefield) = 0;
};

#endif //SHASHE4KI_BASIC_INTERFACE_H
