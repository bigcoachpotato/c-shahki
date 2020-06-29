#ifndef SHASHE4KI_STANDARDRULES_H
#define SHASHE4KI_STANDARDRULES_H

#include "field.h"
#include "../strategies/computerlogic.h"
#include <vector>

using namespace std;

class Field;

vector<short> input_coords();

bool can_be_killed(short &left_coord, short &top_coord, Field &field);

bool needs_kill_next(short &left_coord, short &top_coord, Field &field);

#endif //SHASHE4KI_STANDARDRULES_H
