#include "computer_strategy_2.h"
#include "time.h"

char Computer_strategy_2::win_step(Field &gamefield) {
    if (gamefield.white->myturns.empty())
        return 'b';
    if (gamefield.black->myturns.empty())
        return 'w';
    return 'n';
}

vector<short> Computer_strategy_2::choose_way(char &who_am_i_, Field &field) {
    map<pair<short, short>, bool> mymap;
    if (who_am_i_ == 'w' || who_am_i_ == 'q')
        mymap = field.white->myturns;
    else
        mymap = field.black->myturns;
    map<pair<short, short>, bool> map_for_turn;
    if (mymap.empty()) {
        if (who_am_i_ == 'w') {
            return {-1, -1};
        } else {
            return {-1, -1};
        }
    }
    for (auto it = mymap.begin(); it != mymap.end(); it++) {
        if (who_am_i_ == 'w') {
            if (field.field[it->first.first - 1][it->first.second - 1] == '-') {
                map_for_turn[{it->first.first, it->first.second}] = true;
                continue;
            }
            if (field.field[it->first.first - 1][it->first.second + 1] == '-') {
                map_for_turn[{it->first.first, it->first.second}] = true;
                continue;
            }
        }
        if (who_am_i_ == 'b') {
            if (field.field[it->first.first + 1][it->first.second - 1] == '-') {
                map_for_turn[{it->first.first, it->first.second}] = true;
                continue;
            }
            if (field.field[it->first.first + 1][it->first.second + 1] == '-') {
                map_for_turn[{it->first.first, it->first.second}] = true;
                continue;
            }
        }
        if (field.field[it->first.first + 1][it->first.second - 1] == '-') {
            map_for_turn[{it->first.first, it->first.second}] = true;
            continue;
        }
        if (field.field[it->first.first + 1][it->first.second + 1] == '-') {
            map_for_turn[{it->first.first, it->first.second}] = true;
            continue;
        }
        if (field.field[it->first.first - 1][it->first.second - 1] == '-') {
            map_for_turn[{it->first.first, it->first.second}] = true;
            continue;
        }
        if (field.field[it->first.first - 1][it->first.second + 1] == '-') {
            map_for_turn[{it->first.first, it->first.second}] = true;
            continue;
        }

    }
    if (map_for_turn.size() == 0) {
        if (who_am_i_ == 'w') {
            return {-1, -1};
        } else {
            return {-1, -1};
        }
    }
    int random = map_for_turn.size() - 1;
    srand(time(0));
    int j;
    if (random != 0)
        j = rand() % random;
    else
        j = 0;
    auto it = map_for_turn.begin();
    while (j > 0) {
        it++;
        j -= 1;
    }
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

bool Computer_strategy_2::check_correct(vector<short> situation, char &curturn, Field &gamefield) {
    return false;
}

