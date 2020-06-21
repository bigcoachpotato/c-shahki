#include "computerlogic.h"
#include <time.h>

pair<short, short> choose_one_of_(map<pair<short, short>, bool> &storage_killers) {
    auto it = storage_killers.begin();
    return {it->first.first, it->first.second};
}


vector<short> choose_way_1(char &who_am_i_, Field &field) {
    map<pair<short, short>, bool> mymap;
    if (who_am_i_ == 'w' || who_am_i_ == 'q')
        mymap = field.whiteturns;
    else
        mymap = field.blackturns;
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
        cout << "White wins";
        exit(0);
    } else {
        cout << "Black wins";
        exit(0);
    }
}

vector<short> choose_way_2(char &who_am_i_, Field &field) {
    map<pair<short, short>, bool> mymap;
    if (who_am_i_ == 'w' || who_am_i_ == 'q')
        mymap = field.whiteturns;
    else
        mymap = field.blackturns;
    map<pair<short, short>, bool> map_for_turn;
    if (mymap.empty()) {
        if (who_am_i_ == 'w') {
            cout << "White wins";
            exit(0);
        } else {
            cout << "Black wins";
            exit(0);
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
            cout << "White wins";
            exit(0);
        } else {
            cout << "Black wins";
            exit(0);
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

vector<short> type_of_strategy(char &who_am_i_, Field &field) {
    if (who_am_i_ == 'w' || who_am_i_ == 'q') {
        if (field.type_of_strategy_white == 1)
            return choose_way_1(who_am_i_, field);
        else
            return choose_way_2(who_am_i_, field);
    } else if (who_am_i_ == 'b' || who_am_i_ == 'k') {
        if (field.type_of_strategy_black == 1)
            return choose_way_1(who_am_i_, field);
        else
            return choose_way_2(who_am_i_, field);
    }
}