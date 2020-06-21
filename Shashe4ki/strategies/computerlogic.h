#ifndef SHASHE4KI_COMPUTERLOGIC_H
#define SHASHE4KI_COMPUTERLOGIC_H

#include "field.h"

using namespace std;

pair<short, short> choose_one_of_(map<pair<short, short>, bool> &storage_killers);

vector<short> choose_way_1(char &who_am_i_, Field &field);

vector<short> choose_way_2(char &who_am_i_, Field &field);

vector<short> type_of_strategy(char &who_am_i_, Field &field);

#endif //SHASHE4KI_COMPUTERLOGIC_H
