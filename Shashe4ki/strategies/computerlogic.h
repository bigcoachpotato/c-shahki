#ifndef SHASHE4KI_COMPUTERLOGIC_H
#define SHASHE4KI_COMPUTERLOGIC_H

#include "../game/standardrules.h"
#include "basic_interface.h"

using namespace std;

class Computer_interface : public Basic_interface {
public:
    Computer_interface() = default;

    pair<short, short> choose_one_of_(map<pair<short, short>, bool> &storage_killers) override;
};


#endif //SHASHE4KI_COMPUTERLOGIC_H
