#ifndef SHASHE4KI_STANDARDRULES_H
#define SHASHE4KI_STANDARDRULES_H

#include "field.h"
#include "computerlogic.h"

using namespace std;

vector<short> input_coords();

bool check_correct(vector<short> situation, char &curturn, Field &gamefield);

bool can_be_killed(short &left_coord, short &top_coord, Field &field);

bool needs_kill_next(short &left_coord, short &top_coord, Field &field);

#endif //SHASHE4KI_STANDARDRULES_H
