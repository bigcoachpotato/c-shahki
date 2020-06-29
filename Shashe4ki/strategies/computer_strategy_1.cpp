#include "computer_strategy_1.h"

char Computer_strategy_1::win_step(Field &gamefield) {
    if (gamefield.white->myturns.empty())
        return 'b';
    if (gamefield.black->myturns.empty())
        return 'w';
    return 'n';
}

vector<short> Computer_strategy_1::choose_way(char &who_am_i_, Field &field) {
    map<pair<short, short>, bool> mymap;
    if (who_am_i_ == 'w' || who_am_i_ == 'q')
        mymap = field.white->myturns;
    else
        mymap = field.black->myturns;
    for (auto it = mymap.begin(); it != mymap.end(); it++) {
        if (who_am_i_ == 'w') {
            if (field.field[it->first.first - 1][it->first.second - 1] == '-') {
                return {it->first.first, it->first.second, short(it->first.first - 1), short(it->first.second - 1)};
            }
            if (field.field[it->first.first - 1][it->first.second + 1] == '-') {
                return {it->first.first, it->first.second, short(it->first.first - 1), short(it->first.second + 1)};
            }
        }
        if (who_am_i_ == 'b') {
            if (field.field[it->first.first + 1][it->first.second - 1] == '-') {
                return {it->first.first, it->first.second, short(it->first.first + 1), short(it->first.second - 1)};
            }
            if (field.field[it->first.first + 1][it->first.second + 1] == '-') {
                return {it->first.first, it->first.second, short(it->first.first + 1), short(it->first.second + 1)};
            }
        }

        if (field.field[it->first.first + 1][it->first.second - 1] == '-') {
            return {it->first.first, it->first.second, short(it->first.first + 1), short(it->first.second - 1)};
        }
        if (field.field[it->first.first + 1][it->first.second + 1] == '-') {
            return {it->first.first, it->first.second, short(it->first.first + 1), short(it->first.second + 1)};
        }
        if (field.field[it->first.first - 1][it->first.second - 1] == '-') {
            return {it->first.first, it->first.second, short(it->first.first - 1), short(it->first.second - 1)};
        }
        if (field.field[it->first.first - 1][it->first.second + 1] == '-') {
            return {it->first.first, it->first.second, short(it->first.first - 1), short(it->first.second + 1)};
        }

    }
    if (who_am_i_ == 'w') {
        return {-1, -1};
    } else {
        return {-1, -1};
    }
}

bool Computer_strategy_1::check_correct(vector<short> situation, char &curturn, Field &gamefield) {
    return false;
}
