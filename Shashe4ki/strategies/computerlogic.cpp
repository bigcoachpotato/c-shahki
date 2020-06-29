#include "computerlogic.h"
#include <time.h>

pair<short, short> Computer_interface::choose_one_of_(map<pair<short, short>, bool> &storage_killers) {
    auto it = storage_killers.begin();
    return {it->first.first, it->first.second};
}