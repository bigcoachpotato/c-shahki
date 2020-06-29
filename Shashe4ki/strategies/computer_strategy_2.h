#ifndef SHASHE4KI_COMPUTER_STRATEGY_2_H
#define SHASHE4KI_COMPUTER_STRATEGY_2_H

#include "computerlogic.h"

class Computer_strategy_2 : public Computer_interface {
public:
    Computer_strategy_2() = default;

    bool check_correct(vector<short> situation, char &curturn, Field &gamefield) override;

    vector<short> choose_way(char &who_am_i_, Field &field) override;

    char win_step(Field &gamefield) override;

    using Computer_interface::choose_one_of_;
};

#endif //SHASHE4KI_COMPUTER_STRATEGY_2_H
