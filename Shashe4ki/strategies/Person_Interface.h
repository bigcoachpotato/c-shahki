#ifndef SHASHE4KI_PERSON_INTERFACE_H
#define SHASHE4KI_PERSON_INTERFACE_H

#include "basic_interface.h"
#include "../game/field.h"


using namespace std;


class User : public Basic_interface {
public:
    User() = default;

    vector<short> choose_way(char &who_am_i_, Field &field) override;

    pair<short, short> choose_one_of_(map<pair<short, short>, bool> &storage_killers) override;

    char win_step(Field &gamefield) override;

    bool check_correct(vector<short> situation, char &curturn, Field &gamefield) override;
};

#endif //SHASHE4KI_PERSON_INTERFACE_H
