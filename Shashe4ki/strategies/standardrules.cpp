#include "standardrules.h"
#include <iostream>

bool check_correct(vector<short> situation, char &curturn, Field &gamefield) {
    if (gamefield.field[situation[0]][situation[1]] == gamefield.field[situation[2]][situation[3]])
        return false;
    char figure_state = (gamefield.returncolor(situation[0], situation[1]));
    if ((curturn == 'w' && (figure_state == 'w' || figure_state == 'q')) ||
        (curturn == 'b' && (figure_state == 'b' || figure_state == 'k'))) {
        if (figure_state != 'k' && figure_state != 'q') {
            if (figure_state == 'b') {
                if (situation[0] + 1 == situation[2] &&
                    (situation[1] == situation[3] - 1 || situation[1] == situation[3] + 1)) {
                    if (gamefield.returncolor(situation[2], situation[3] == '-'))
                        return true;
                }
            } else {
                if (situation[0] - 1 == situation[2] &&
                    (situation[1] == situation[3] - 1 || situation[1] == situation[3] + 1)) {
                    if (gamefield.returncolor(situation[2], situation[3] == '-'))
                        return true;
                }
            }
        } else if (figure_state == 'k' || figure_state == 'q') {
            if (abs(situation[0] - situation[2]) == abs(situation[1] - situation[3])) {
                if (curturn == 'w' && figure_state == 'q') {
                    if (gamefield.returncolor(situation[2], situation[3]) == '-') {
                        if (situation[0] > situation[2]) {
                            if (situation[1] > situation[3]) {
                                short left_x = situation[2];
                                short top_y = situation[3];
                                short counter_element_on_the_way = 0;
                                while (situation[1] != top_y) {
                                    char returned_color = gamefield.returncolor(situation[2], situation[3]);
                                    if (returned_color == 'q' || returned_color == 'w')
                                        return false;
                                    if (returned_color == 'k' || returned_color == 'b') {
                                        counter_element_on_the_way += 1;
                                        left_x += 1;
                                        top_y += 1;
                                        if (counter_element_on_the_way > 1)
                                            return false;
                                        continue;
                                    }
                                    left_x += 1;
                                    top_y += 1;
                                    counter_element_on_the_way = 0;
                                }
                                return true;
                            } else {
                                short left_x = situation[2];
                                short top_y = situation[3];
                                int counter_element_on_the_way = 0;
                                while (situation[1] != top_y) {
                                    char returned_color = gamefield.returncolor(situation[2], situation[3]);
                                    if (returned_color == 'q' || returned_color == 'w')
                                        return false;
                                    if (returned_color == 'k' || returned_color == 'b') {
                                        counter_element_on_the_way += 1;
                                        left_x += 1;
                                        top_y -= 1;
                                        if (counter_element_on_the_way > 1)
                                            return false;
                                        continue;
                                    }
                                    left_x += 1;
                                    top_y -= 1;
                                    counter_element_on_the_way = 0;
                                }
                                return true;
                            }
                        } else {
                            if (situation[1] > situation[3]) {
                                short left_x = situation[2];
                                short top_y = situation[3];
                                int counter_element_on_the_way = 0;
                                while (situation[1] != top_y) {
                                    char returned_color = gamefield.returncolor(situation[2], situation[3]);
                                    if (returned_color == 'q' || returned_color == 'w')
                                        return false;
                                    if (returned_color == 'k' || returned_color == 'b') {
                                        counter_element_on_the_way += 1;
                                        left_x -= 1;
                                        top_y += 1;
                                        if (counter_element_on_the_way > 1)
                                            return false;
                                        continue;
                                    }
                                    left_x -= 1;
                                    top_y += 1;
                                    counter_element_on_the_way = 0;
                                }
                                return true;
                            } else {
                                short left_x = situation[2];
                                short top_y = situation[3];
                                int counter_element_on_the_way = 0;
                                while (situation[1] != top_y) {
                                    char returned_color = gamefield.returncolor(situation[2], situation[3]);
                                    if (returned_color == 'q' || returned_color == 'w')
                                        return false;
                                    if (returned_color == 'k' || returned_color == 'b') {
                                        counter_element_on_the_way += 1;
                                        left_x -= 1;
                                        top_y -= 1;
                                        if (counter_element_on_the_way > 1)
                                            return false;
                                        continue;
                                    }
                                    left_x -= 1;
                                    top_y -= 1;
                                    counter_element_on_the_way = 0;
                                }
                                return true;
                            }
                        }
                    }
                } else if (curturn == 'b' && figure_state == 'k') {
                    if (gamefield.returncolor(situation[2], situation[3]) == '-') {
                        if (situation[0] > situation[2]) {
                            if (situation[1] > situation[3]) {
                                short left_x = situation[2];
                                short top_y = situation[3];
                                int counter_element_on_the_way = 0;
                                while (situation[1] != top_y) {
                                    char returned_color = gamefield.returncolor(situation[2], situation[3]);
                                    if (returned_color == 'q' || returned_color == 'w')
                                        return false;
                                    if (returned_color == 'k' || returned_color == 'b') {
                                        counter_element_on_the_way += 1;
                                        left_x += 1;
                                        top_y += 1;
                                        if (counter_element_on_the_way > 1)
                                            return false;
                                        continue;
                                    }
                                    left_x += 1;
                                    top_y += 1;
                                    counter_element_on_the_way = 0;
                                }
                                return true;
                            } else {
                                short left_x = situation[2];
                                short top_y = situation[3];
                                int counter_element_on_the_way = 0;
                                while (situation[1] != situation[3]) {
                                    char returned_color = gamefield.returncolor(situation[2], situation[3]);
                                    if (returned_color == 'q' || returned_color == 'w')
                                        return false;
                                    if (returned_color == 'k' || returned_color == 'b') {
                                        counter_element_on_the_way += 1;
                                        left_x += 1;
                                        top_y -= 1;
                                        if (counter_element_on_the_way > 1)
                                            return false;
                                        continue;
                                    }
                                    left_x += 1;
                                    top_y -= 1;
                                    counter_element_on_the_way = 0;
                                }
                                return true;
                            }
                        } else {
                            if (situation[1] > situation[3]) {
                                int counter_element_on_the_way = 0;
                                short left_x = situation[2];
                                short top_y = situation[3];
                                while (situation[1] != situation[3]) {
                                    char returned_color = gamefield.returncolor(situation[2], situation[3]);
                                    if (returned_color == 'k' || returned_color == 'b')
                                        return false;
                                    if (returned_color == 'q' || returned_color == 'w') {
                                        counter_element_on_the_way += 1;
                                        left_x -= 1;
                                        top_y += 1;
                                        if (counter_element_on_the_way > 1)
                                            return false;
                                        continue;
                                    }
                                    left_x -= 1;
                                    top_y += 1;
                                    counter_element_on_the_way = 0;
                                }
                                return true;
                            } else {
                                int counter_element_on_the_way = 0;
                                short left_x = situation[2];
                                short top_y = situation[3];
                                while (situation[1] != top_y) {
                                    char returned_color = gamefield.returncolor(situation[2], situation[3]);
                                    if (returned_color == 'k' || returned_color == 'b')
                                        return false;
                                    if (returned_color == 'q' || returned_color == 'w') {
                                        counter_element_on_the_way += 1;
                                        left_x -= 1;
                                        top_y -= 1;
                                        if (counter_element_on_the_way > 1)
                                            return false;
                                        continue;
                                    }
                                    left_x -= 1;
                                    top_y -= 1;
                                    counter_element_on_the_way = 0;
                                }
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

vector<short> input_coords() {
    cout << "insert coords from X by LEFT, Y by TOP sides\n";
    cout << "X: ";
    short x, xto, yto;
    cin >> x;
    cout << "Y: ";
    short y;
    cin >> y;
    cout << "Where move X by LEFT, Y by TOP\n X: ";
    cin >> xto;
    cout << "Y: ";
    cin >> yto;
    vector<short> ans = {x, y, xto, yto};
    return ans;
}

bool can_be_killed(short &left_coord, short &top_coord, Field &field) {
    char figure = field.returncolor(left_coord, top_coord);
    map<pair<short, short>, bool> storage_killers;
    bool is_it_comp = false;
    if ((figure == 'w' || figure == 'q') && field.black_is_computer_ == true) {
        is_it_comp = true;
    } else if ((figure == 'b' || figure == 'k') && field.white_is_computer_ == true) {
        is_it_comp = true;
    }
    if (figure == 'q' || figure == 'w') {
        if (field.blackturns.count({left_coord + 1, top_coord + 1}))
            if (left_coord - 1 > -1 && top_coord - 1 > -1 && field.field[left_coord - 1][top_coord - 1] == '-') {
                storage_killers[{left_coord + 1, top_coord + 1}] = true;
            }
        if (field.blackturns.count({left_coord - 1, top_coord - 1}))
            if (left_coord + 1 < 9 && top_coord + 1 < 9 && field.field[left_coord + 1][top_coord + 1] == '-') {
                storage_killers[{left_coord - 1, top_coord - 1}] = true;
            }
        if (field.blackturns.count({left_coord + 1, top_coord - 1}))
            if (left_coord - 1 > -1 && top_coord + 1 < 9 && field.field[left_coord - 1][top_coord + 1] == '-') {
                storage_killers[{left_coord + 1, top_coord - 1}] = true;
            }
        if (field.blackturns.count({left_coord - 1, top_coord + 1}))
            if (left_coord + 1 < 9 && top_coord - 1 > -1 && field.field[left_coord + 1][top_coord - 1] == '-') {
                storage_killers[{left_coord - 1, top_coord + 1}] = true;
            }
    } else if (figure == 'b' || figure == 'k') {
        if (field.whiteturns.count({left_coord + 1, top_coord + 1}))
            if (field.field[left_coord - 1][top_coord - 1] == '-') {
                storage_killers[{left_coord + 1, top_coord + 1}] = true;
            }
        if (field.whiteturns.count({left_coord - 1, top_coord - 1}))
            if (field.field[left_coord + 1][top_coord + 1] == '-') {
                storage_killers[{left_coord - 1, top_coord - 1}] = true;
            }
        if (field.whiteturns.count({left_coord + 1, top_coord - 1}))
            if (field.field[left_coord - 1][top_coord + 1] == '-') {
                storage_killers[{left_coord + 1, top_coord - 1}] = true;
            }
        if (left_coord + 1 < 9 && top_coord - 1 > -1 && field.whiteturns.count({left_coord - 1, top_coord + 1}))
            if (field.field[left_coord + 1][top_coord - 1] == '-') {
                storage_killers[{left_coord - 1, top_coord + 1}] = true;
            }
    }
    if (figure == 'b' || figure == 'k') {
        vector<pair<short, short>> candidates;
        for (auto i : field.white_queens) {
            if (abs(left_coord - i.first.first) == abs(top_coord - i.first.second))
                candidates.emplace_back(i.first.first, i.first.second);
        }
        for (auto i : candidates) {
            if (i.first > left_coord && i.second > top_coord) {
                short left, top;
                left = i.first - 1;
                top = i.second - 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        left -= 1;
                        top -= 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    check_blocks = 0;
                    left -= 1;
                    top -= 1;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first < left_coord && i.second < top_coord) {
                short left, top;
                left = i.first + 1;
                top = i.second + 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        left += 1;
                        top += 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left += 1;
                    top += 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first > left_coord && i.second < top_coord) {
                short left, top;
                left = i.first - 1;
                top = i.second + 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        left -= 1;
                        top += 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left -= 1;
                    top += 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first < left_coord && i.second > top_coord) {
                short left, top;
                left = i.first + 1;
                top = i.second - 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        left += 1;
                        top -= 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left += 1;
                    top -= 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
        }
    }
    if (figure == 'q' || figure == 'w') {
        vector<pair<short, short>> candidates;
        for (auto i : field.black_kings) {
            if (abs(left_coord - i.first.first) == abs(top_coord - i.first.second))
                candidates.emplace_back(i.first.first, i.first.second);
        }
        for (auto i : candidates) {
            if (i.first > left_coord && i.second > top_coord) {
                short left, top;
                left = i.first - 1;
                top = i.second - 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        left -= 1;
                        top -= 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    check_blocks = 0;
                    left -= 1;
                    top -= 1;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first < left_coord && i.second < top_coord) {
                short left, top;
                left = i.first + 1;
                top = i.second + 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        left += 1;
                        top += 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left += 1;
                    top += 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first > left_coord && i.second < top_coord) {
                short left, top;
                left = i.first - 1;
                top = i.second + 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        left -= 1;
                        top += 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left -= 1;
                    top += 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first < left_coord && i.second > top_coord) {
                short left, top;
                left = i.first + 1;
                top = i.second - 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        left += 1;
                        top -= 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left += 1;
                    top -= 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
        }
    }
    if (storage_killers.size() > 1) {
        if (is_it_comp) {
            pair<short, short> choose = choose_one_of_(storage_killers);
            storage_killers.clear();
            storage_killers[{choose.first, choose.second}] = true;
        } else {
            char who = 'n';
            if (figure == 'b' || figure == 'k')
                who = 'w';
            else
                who = 'b';
            field.write();
            cout << who << " need choose figure which kills at coords : " << left_coord << ' ' << top_coord;
            cout << "\n list of killers \n";
            for (auto i : storage_killers) {
                cout << i.first.first << ' ' << i.first.second << '\n';
            }
            short left_killer = 0, top_killer = 0;
            while (storage_killers.count({left_killer, top_killer}) != true) {
                cin >> left_killer >> top_killer;
            }
            if (storage_killers.count({left_killer, top_killer}))
                storage_killers.clear();
            storage_killers[{left_killer, top_killer}] = true;
        }
    };
    if (storage_killers.size() == 1 &&
        (field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'w' ||
         field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'b')) {
        char who = 'n';
        if (figure == 'b' || figure == 'k') {
            who = 'w';
        } else {
            who = 'b';
        }
        if (storage_killers.begin()->first.first > left_coord && storage_killers.begin()->first.second > top_coord) {
            field.field[storage_killers.begin()->first.first - 2][storage_killers.begin()->first.second -
                                                                  2] = field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[storage_killers.begin()->first.first - 1][storage_killers.begin()->first.second - 1] = '-';
            if (who == 'w') {
                field.whiteturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.whiteturns[{storage_killers.begin()->first.first - 2,
                                  storage_killers.begin()->first.second - 2}] = true;
                if (field.black_kings.count(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1}) == 0)
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                }
            } else if (who == 'b') {
                field.blackturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.blackturns[{storage_killers.begin()->first.first - 2,
                                  storage_killers.begin()->first.second - 2}] = true;
                if (field.white_queens.count(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1}) == 0)
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                }
            }
            left_coord = storage_killers.begin()->first.first - 2;
            top_coord = storage_killers.begin()->first.second - 2;

        } else if (storage_killers.begin()->first.first < left_coord &&
                   storage_killers.begin()->first.second < top_coord) {
            field.field[storage_killers.begin()->first.first + 2][storage_killers.begin()->first.second +
                                                                  2] = field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[storage_killers.begin()->first.first + 1][storage_killers.begin()->first.second + 1] = '-';
            if (who == 'w') {
                field.whiteturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.whiteturns[{storage_killers.begin()->first.first + 2,
                                  storage_killers.begin()->first.second + 2}] = true;
                if (field.black_kings.count(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1}) == 0)
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                }
            } else if (who == 'b') {
                field.blackturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.blackturns[{storage_killers.begin()->first.first + 2,
                                  storage_killers.begin()->first.second + 2}] = true;
                if (field.white_queens.count(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1}) == 0)
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                }
            }
            left_coord = storage_killers.begin()->first.first + 2;
            top_coord = storage_killers.begin()->first.second + 2;
        } else if (storage_killers.begin()->first.first < left_coord &&
                   storage_killers.begin()->first.second > top_coord) {
            field.field[storage_killers.begin()->first.first + 2][storage_killers.begin()->first.second -
                                                                  2] = field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[storage_killers.begin()->first.first + 1][storage_killers.begin()->first.second - 1] = '-';
            if (who == 'w') {
                field.whiteturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.whiteturns[{storage_killers.begin()->first.first + 2,
                                  storage_killers.begin()->first.second - 2}] = true;
                if (field.black_kings.count(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1}) == 0)
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                }
            } else if (who == 'b') {
                field.blackturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.blackturns[{storage_killers.begin()->first.first + 2,
                                  storage_killers.begin()->first.second - 2}] = true;
                if (field.white_queens.count(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1}) == 0)
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                }
            }
            left_coord = storage_killers.begin()->first.first + 2;
            top_coord = storage_killers.begin()->first.second - 2;
        } else if (storage_killers.begin()->first.first > left_coord &&
                   storage_killers.begin()->first.second < top_coord) {
            field.field[storage_killers.begin()->first.first - 2][storage_killers.begin()->first.second +
                                                                  2] = field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[storage_killers.begin()->first.first - 1][storage_killers.begin()->first.second + 1] = '-';
            if (who == 'w') {
                field.whiteturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.whiteturns[{storage_killers.begin()->first.first - 2,
                                  storage_killers.begin()->first.second + 2}] = true;
                if (field.black_kings.count(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1}) == 0)
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                }
            } else if (who == 'b') {
                field.blackturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.blackturns[{storage_killers.begin()->first.first - 2,
                                  storage_killers.begin()->first.second + 2}] = true;
                if (field.white_queens.count(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1}) == 0)
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                }
            }
            left_coord = storage_killers.begin()->first.first - 2;
            top_coord = storage_killers.begin()->first.second + 2;
        }
        if (field.field[left_coord][top_coord] == 'w' && left_coord == 1) {
            field.field[left_coord][top_coord] = 'q';
            field.white_queens[{left_coord, top_coord}] = true;
        } else if (field.field[left_coord][top_coord] == 'b' && left_coord == 8) {
            field.field[left_coord][top_coord] = 'k';
            field.black_kings[{left_coord, top_coord}] = true;
        }
        while (needs_kill_next(left_coord, top_coord, field)) {
            continue;
            if (field.field[left_coord][top_coord] == 'w' && left_coord == 1) {
                field.field[left_coord][top_coord] = 'q';
                field.white_queens[{left_coord, top_coord}] = true;
            } else if (field.field[left_coord][top_coord] == 'b' && left_coord == 8) {
                field.field[left_coord][top_coord] = 'k';
                field.black_kings[{left_coord, top_coord}] = true;
            }
        }
        return true;
    }
    if (storage_killers.size() == 1 &&
        (field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'k' ||
         field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'q')) {
        if (storage_killers.begin()->first.first > left_coord && storage_killers.begin()->first.second > top_coord) {
            map<pair<short, short>, bool> positions_to_stay;
            short i = left_coord - 1;
            short j = top_coord - 1;
            while (i >= 1 && j >= 1) {
                if (field.field[i][j] != '-')
                    break;
                positions_to_stay[{i, j}] = true;
                i -= 1;
                j -= 1;
            }
            if (positions_to_stay.empty())
                return false;
            short pos_x = -1, pos_y = -1;
            if (is_it_comp) {
                pair<short, short> choose = choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                cout << "choose position to stay your figure in :\n";
                for (auto z : positions_to_stay) {
                    cout << z.first.first << ' ' << z.first.second << '\n';
                }

                while (positions_to_stay.count({pos_x, pos_y}) != true) {
                    cin >> pos_x >> pos_y;
                }
            }
            field.field[pos_x][pos_y] = field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[left_coord][top_coord] = '-';
            if (field.field[pos_x][pos_y] == 'k') {
                field.black_kings.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black_kings[{pos_x, pos_y}] = true;
                field.blackturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.blackturns[{pos_x, pos_y}] = true;
                if (field.white_queens.count({left_coord, top_coord}) == 0)
                    field.whiteturns.erase({left_coord, top_coord});
                else {
                    field.white_queens.erase({left_coord, top_coord});
                    field.whiteturns.erase({left_coord, top_coord});
                }
            } else {
                field.white_queens.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white_queens[{pos_x, pos_y}] = true;
                field.whiteturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.whiteturns[{pos_x, pos_y}] = true;
                if (field.black_kings.count({left_coord, top_coord}) == 0)
                    field.blackturns.erase({left_coord, top_coord});
                else {
                    field.black_kings.erase({left_coord, top_coord});
                    field.blackturns.erase({left_coord, top_coord});
                }
            }
            left_coord = pos_x;
            top_coord = pos_y;
            while (needs_kill_next(left_coord, top_coord, field)) {
                continue;
            }
            return true;
        }
        if (storage_killers.begin()->first.first < left_coord && storage_killers.begin()->first.second < top_coord) {
            map<pair<short, short>, bool> positions_to_stay;
            short i = left_coord + 1;
            short j = top_coord + 1;
            while (i < 9 && j < 9) {
                if (field.field[i][j] != '-')
                    break;
                positions_to_stay[{i, j}] = true;
                i += 1;
                j += 1;
            }
            if (positions_to_stay.empty())
                return false;
            short pos_x = -1, pos_y = -1;
            if (is_it_comp) {
                pair<short, short> choose = choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                cout << "choose position to stay your figure in :\n";
                for (auto z : positions_to_stay) {
                    cout << z.first.first << ' ' << z.first.second << '\n';
                }

                while (positions_to_stay.count({pos_x, pos_y}) != true) {
                    cin >> pos_x >> pos_y;
                }
            }
            field.field[pos_x][pos_y] = field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[left_coord][top_coord] = '-';
            if (field.field[pos_x][pos_y] == 'k') {
                field.black_kings.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black_kings[{pos_x, pos_y}] = true;
                field.blackturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.blackturns[{pos_x, pos_y}] = true;
                if (field.white_queens.count({left_coord, top_coord}) == 0)
                    field.whiteturns.erase({left_coord, top_coord});
                else {
                    field.white_queens.erase({left_coord, top_coord});
                    field.whiteturns.erase({left_coord, top_coord});
                }
            } else {
                field.white_queens.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white_queens[{pos_x, pos_y}] = true;
                field.whiteturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.whiteturns[{pos_x, pos_y}] = true;
                if (field.black_kings.count({left_coord, top_coord}) == 0)
                    field.blackturns.erase({left_coord, top_coord});
                else {
                    field.black_kings.erase({left_coord, top_coord});
                    field.blackturns.erase({left_coord, top_coord});
                }
            }
            left_coord = pos_x;
            top_coord = pos_y;
            while (needs_kill_next(left_coord, top_coord, field)) {
                continue;
            }
            return true;
        }
        if (storage_killers.begin()->first.first < left_coord && storage_killers.begin()->first.second > top_coord) {
            map<pair<short, short>, bool> positions_to_stay;
            short i = left_coord + 1;
            short j = top_coord - 1;
            while (i < 9 && j >= 1) {
                if (field.field[i][j] != '-')
                    break;
                positions_to_stay[{i, j}] = true;
                i += 1;
                j -= 1;
            }
            if (positions_to_stay.empty())
                return false;
            short pos_x = -1, pos_y = -1;
            if (is_it_comp) {
                cout << "choose position to stay your figure in :\n";
                pair<short, short> choose = choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                for (auto z : positions_to_stay) {
                    cout << z.first.first << ' ' << z.first.second << '\n';
                }

                while (positions_to_stay.count({pos_x, pos_y}) != true) {
                    cin >> pos_x >> pos_y;
                }
            }
            field.field[pos_x][pos_y] = field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[left_coord][top_coord] = '-';
            if (field.field[pos_x][pos_y] == 'k') {
                field.black_kings.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black_kings[{pos_x, pos_y}] = true;
                field.blackturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.blackturns[{pos_x, pos_y}] = true;
                if (field.white_queens.count({left_coord, top_coord}) == 0)
                    field.whiteturns.erase({left_coord, top_coord});
                else {
                    field.white_queens.erase({left_coord, top_coord});
                    field.whiteturns.erase({left_coord, top_coord});
                }
            } else {
                field.white_queens.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white_queens[{pos_x, pos_y}] = true;
                field.whiteturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.whiteturns[{pos_x, pos_y}] = true;
                if (field.black_kings.count({left_coord, top_coord}) == 0)
                    field.blackturns.erase({left_coord, top_coord});
                else {
                    field.black_kings.erase({left_coord, top_coord});
                    field.blackturns.erase({left_coord, top_coord});
                }
            }
            left_coord = pos_x;
            top_coord = pos_y;
            while (needs_kill_next(left_coord, top_coord, field)) {
                continue;
            }
            return true;
        }
        if (storage_killers.begin()->first.first > left_coord && storage_killers.begin()->first.second < top_coord) {
            map<pair<short, short>, bool> positions_to_stay;
            short i = left_coord - 1;
            short j = top_coord + 1;
            while (i >= 1 && j < 9) {
                if (field.field[i][j] != '-')
                    break;
                positions_to_stay[{i, j}] = true;
                i -= 1;
                j += 1;
            }
            if (positions_to_stay.empty())
                return false;

            short pos_x = -1, pos_y = -1;
            if (is_it_comp) {
                pair<short, short> choose = choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                cout << "choose position to stay your figure in :\n";
                for (auto z : positions_to_stay) {
                    cout << z.first.first << ' ' << z.first.second << '\n';
                }

                while (positions_to_stay.count({pos_x, pos_y}) != true) {
                    cin >> pos_x >> pos_y;
                }
            }
            field.field[pos_x][pos_y] = field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[left_coord][top_coord] = '-';
            if (field.field[pos_x][pos_y] == 'k') {
                field.black_kings.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black_kings[{pos_x, pos_y}] = true;
                field.blackturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.blackturns[{pos_x, pos_y}] = true;
                if (field.white_queens.count({left_coord, top_coord}) == 0)
                    field.whiteturns.erase({left_coord, top_coord});
                else {
                    field.white_queens.erase({left_coord, top_coord});
                    field.whiteturns.erase({left_coord, top_coord});
                }
            } else {
                field.white_queens.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white_queens[{pos_x, pos_y}] = true;
                field.whiteturns.erase({storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.whiteturns[{pos_x, pos_y}] = true;
                if (field.black_kings.count({left_coord, top_coord}) == 0)
                    field.blackturns.erase({left_coord, top_coord});
                else {
                    field.black_kings.erase({left_coord, top_coord});
                    field.blackturns.erase({left_coord, top_coord});
                }
            }
            left_coord = pos_x;
            top_coord = pos_y;
            while (needs_kill_next(left_coord, top_coord, field)) {
                continue;
            }
            return true;
        }
    }

    return false;
}

bool needs_kill_next(short &left_coord, short &top_coord, Field &field) {

    char figure = field.returncolor(left_coord, top_coord);
    map<pair<short, short>, bool> storage_killers;
    bool is_it_comp = false;
    if ((figure == 'w' || figure == 'q') && field.white_is_computer_ == true) {
        is_it_comp = true;
    } else if ((figure == 'b' || figure == 'k') && field.black_is_computer_ == true) {
        is_it_comp = true;
    }
    if (figure == 'w') {
        if (field.blackturns.count({left_coord + 1, top_coord + 1}))
            if (field.field[left_coord + 2][top_coord + 2] == '-') {
                storage_killers[{left_coord + 1, top_coord + 1}] = true;
            }
        if (field.blackturns.count({left_coord - 1, top_coord - 1}))
            if (field.field[left_coord - 2][top_coord - 2] == '-') {
                storage_killers[{left_coord - 1, top_coord - 1}] = true;
            }
        if (field.blackturns.count({left_coord + 1, top_coord - 1}))
            if (field.field[left_coord + 2][top_coord - 2] == '-') {
                storage_killers[{left_coord + 1, top_coord - 1}] = true;
            }
        if (field.blackturns.count({left_coord - 1, top_coord + 1}))
            if (field.field[left_coord - 2][top_coord + 2] == '-') {
                storage_killers[{left_coord - 1, top_coord + 1}] = true;
            }
    } else if (figure == 'b') {
        if (field.whiteturns.count({left_coord + 1, top_coord + 1}))
            if (field.field[left_coord + 2][top_coord + 2] == '-') {
                storage_killers[{left_coord + 1, top_coord + 1}] = true;
            }
        if (field.whiteturns.count({left_coord - 1, top_coord - 1}))
            if (field.field[left_coord - 2][top_coord - 2] == '-') {
                storage_killers[{left_coord - 1, top_coord - 1}] = true;
            }
        if (field.whiteturns.count({left_coord + 1, top_coord - 1}))
            if (field.field[left_coord + 2][top_coord - 2] == '-') {
                storage_killers[{left_coord + 1, top_coord - 1}] = true;
            }
        if (field.whiteturns.count({left_coord - 1, top_coord + 1}))
            if (field.field[left_coord - 2][top_coord + 2] == '-') {
                storage_killers[{left_coord - 1, top_coord + 1}] = true;
            }
    }
    if (figure == 'k') {
        vector<pair<short, short>> candidates;
        for (auto i : field.white_queens) {
            if (abs(left_coord - i.first.first) == abs(top_coord - i.first.second) && i.first.first != 8 &&
                i.first.first != 1 && i.first.second != 8 && i.first.second != 1)
                candidates.emplace_back(i.first.first, i.first.second);
        }
        for (auto i : field.whiteturns)
            if (abs(left_coord - i.first.first) == abs(top_coord - i.first.second) && i.first.first != 8 &&
                i.first.first != 1 && i.first.second != 8 && i.first.second != 1)
                candidates.emplace_back(i.first.first, i.first.second);
        for (auto i : candidates) {
            if (i.first > left_coord && i.second > top_coord) {
                short left, top;
                left = i.first - 1;
                top = i.second - 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        left -= 1;
                        top -= 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    check_blocks = 0;
                    left -= 1;
                    top -= 1;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first < left_coord && i.second < top_coord) {
                short left, top;
                left = i.first + 1;
                top = i.second + 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        left += 1;
                        top += 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left += 1;
                    top += 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first > left_coord && i.second < top_coord) {
                short left, top;
                left = i.first - 1;
                top = i.second + 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        left -= 1;
                        top += 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left -= 1;
                    top += 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first < left_coord && i.second > top_coord) {
                short left, top;
                left = i.first + 1;
                top = i.second - 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        left += 1;
                        top -= 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left += 1;
                    top -= 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
        }
    }
    if (figure == 'q') {
        vector<pair<short, short>> candidates;
        for (auto i : field.black_kings) {
            if (abs(left_coord - i.first.first) == abs(top_coord - i.first.second) && i.first.first != 8 &&
                i.first.first != 1 && i.first.second != 8 && i.first.second != 1)
                candidates.emplace_back(i.first.first, i.first.second);
        }
        for (auto i : field.blackturns) {
            if (abs(left_coord - i.first.first) == abs(top_coord - i.first.second) && i.first.first != 8 &&
                i.first.first != 1 && i.first.second != 8 && i.first.second != 1)
                candidates.emplace_back(i.first.first, i.first.second);
        }
        for (auto i : candidates) {
            if (i.first > left_coord && i.second > top_coord) {
                short left, top;
                left = i.first - 1;
                top = i.second - 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        left = 1;
                        top -= 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    check_blocks = 0;
                    left -= 1;
                    top -= 1;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first < left_coord && i.second < top_coord) {
                short left, top;
                left = i.first + 1;
                top = i.second + 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        left += 1;
                        top += 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left += 1;
                    top += 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first > left_coord && i.second < top_coord) {
                short left, top;
                left = i.first - 1;
                top = i.second + 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        left -= 1;
                        top += 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left -= 1;
                    top += 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
            if (i.first < left_coord && i.second > top_coord) {
                short left, top;
                left = i.first + 1;
                top = i.second - 1;
                short check_blocks = 0;
                while (left != left_coord || top != top_coord) {
                    if (field.field[left][top] == 'q' || field.field[left][top] == 'w') {
                        check_blocks += 1;
                        break;
                    }
                    if (field.field[left][top] == 'k' || field.field[left][top] == 'b') {
                        check_blocks += 1;
                        left += 1;
                        top -= 1;
                        if (check_blocks > 1)
                            break;
                        continue;
                    }
                    left += 1;
                    top -= 1;
                    check_blocks = 0;
                }
                if (check_blocks == 0) {
                    storage_killers[{i.first, i.second}] = true;
                }
            }
        }
    }
    if (storage_killers.size() > 1) {
        if (is_it_comp) {
            pair<short, short> choose = choose_one_of_(storage_killers);
            storage_killers.clear();
            storage_killers[{choose.first, choose.second}] = true;
        } else {
            field.write();
            cout << figure << " need choose figure which be killed";
            cout << "\n list of killers \n";
            for (auto i : storage_killers) {
                cout << i.first.first << ' ' << i.first.second << '\n';
            }
            short left_killer, top_killer;
            cin >> left_killer >> top_killer;
            if (storage_killers.count({left_killer, top_killer}))
                storage_killers.clear();
            storage_killers[{left_killer, top_killer}] = true;
        }
    };
    if (storage_killers.size() == 1 && (figure == 'w' || figure == 'b')) {
        if (storage_killers.begin()->first.first > left_coord && storage_killers.begin()->first.second > top_coord) {
            field.field[storage_killers.begin()->first.first + 1][storage_killers.begin()->first.second +
                                                                  1] = field.field[
                    storage_killers.begin()->first.first - 1][storage_killers.begin()->first.second - 1];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[storage_killers.begin()->first.first - 1][storage_killers.begin()->first.second - 1] = '-';
            if (figure == 'w') {
                field.whiteturns.erase(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                field.whiteturns[{storage_killers.begin()->first.first + 1,
                                  storage_killers.begin()->first.second + 1}] = true;
                if (field.blackturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else if (figure == 'b') {
                field.blackturns.erase(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                field.blackturns[{storage_killers.begin()->first.first + 1,
                                  storage_killers.begin()->first.second + 1}] = true;
                if (field.whiteturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            left_coord = storage_killers.begin()->first.first + 1;
            top_coord = storage_killers.begin()->first.second + 1;
        } else if (storage_killers.begin()->first.first < left_coord &&
                   storage_killers.begin()->first.second < top_coord) {
            field.field[storage_killers.begin()->first.first - 1][storage_killers.begin()->first.second -
                                                                  1] = field.field[
                    storage_killers.begin()->first.first + 1][storage_killers.begin()->first.second + 1];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[storage_killers.begin()->first.first + 1][storage_killers.begin()->first.second + 1] = '-';
            if (figure == 'w') {
                field.whiteturns.erase(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                field.whiteturns[{storage_killers.begin()->first.first - 1,
                                  storage_killers.begin()->first.second - 1}] = true;
                if (field.blackturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else if (figure == 'b') {
                field.blackturns.erase(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                field.blackturns[{storage_killers.begin()->first.first - 1,
                                  storage_killers.begin()->first.second - 1}] = true;
                if (field.whiteturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            left_coord = storage_killers.begin()->first.first - 1;
            top_coord = storage_killers.begin()->first.second - 1;
        } else if (storage_killers.begin()->first.first < left_coord &&
                   storage_killers.begin()->first.second > top_coord) {
            field.field[storage_killers.begin()->first.first - 1][storage_killers.begin()->first.second +
                                                                  1] = field.field[
                    storage_killers.begin()->first.first + 1][storage_killers.begin()->first.second - 1];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[storage_killers.begin()->first.first + 1][storage_killers.begin()->first.second - 1] = '-';
            if (figure == 'w') {
                field.whiteturns.erase(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                field.whiteturns[{storage_killers.begin()->first.first - 1,
                                  storage_killers.begin()->first.second + 1}] = true;
                if (field.blackturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else if (figure == 'b') {
                field.blackturns.erase(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                field.blackturns[{storage_killers.begin()->first.first - 1,
                                  storage_killers.begin()->first.second + 1}] = true;
                if (field.whiteturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            left_coord = storage_killers.begin()->first.first - 1;
            top_coord = storage_killers.begin()->first.second + 1;
        } else if (storage_killers.begin()->first.first > left_coord &&
                   storage_killers.begin()->first.second < top_coord) {
            field.field[storage_killers.begin()->first.first + 1][storage_killers.begin()->first.second -
                                                                  1] = field.field[
                    storage_killers.begin()->first.first - 1][storage_killers.begin()->first.second + 1];
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            field.field[storage_killers.begin()->first.first - 1][storage_killers.begin()->first.second + 1] = '-';
            if (figure == 'w') {
                field.whiteturns.erase(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                field.whiteturns[{storage_killers.begin()->first.first + 1,
                                  storage_killers.begin()->first.second - 1}] = true;
                if (field.blackturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else if (figure == 'b') {
                field.blackturns.erase(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                field.blackturns[{storage_killers.begin()->first.first + 1,
                                  storage_killers.begin()->first.second - 1}] = true;
                if (field.whiteturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            left_coord = storage_killers.begin()->first.first + 1;
            top_coord = storage_killers.begin()->first.second - 1;
        }
        if (field.field[left_coord][top_coord] == 'w' && left_coord == 1) {
            field.field[left_coord][top_coord] = 'q';
            field.white_queens[{left_coord, top_coord}] = true;
        } else if (field.field[left_coord][top_coord] == 'b' && left_coord == 8) {
            field.field[left_coord][top_coord] = 'k';
            field.black_kings[{left_coord, top_coord}] = true;
        }
        return true;
    }
    if (storage_killers.size() == 1 && (figure == 'q' || figure == 'k')) {
        if (left_coord > storage_killers.begin()->first.first && top_coord > storage_killers.begin()->first.second) {
            map<pair<short, short>, bool> positions_to_stay;
            short i = storage_killers.begin()->first.first - 1;
            short j = storage_killers.begin()->first.second - 1;
            while (i >= 1 && j >= 1) {
                if (field.field[i][j] != '-')
                    break;
                positions_to_stay[{i, j}] = true;
                i -= 1;
                j -= 1;
            }
            if (positions_to_stay.empty())
                return false;
            short pos_x = -1, pos_y = -1;
            if (is_it_comp) {
                pair<short, short> choose = choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                cout << "choose position to stay your figure in :\n";
                for (auto z : positions_to_stay) {
                    cout << z.first.first << ' ' << z.first.second << '\n';
                }

                while (positions_to_stay.count({pos_x, pos_y}) != true) {
                    cin >> pos_x >> pos_y;
                }
            }
            field.field[pos_x][pos_y] = field.field[left_coord][top_coord];
            field.field[left_coord][top_coord] = '-';
            if (field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'q' ||
                field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'w') {
                field.black_kings.erase({left_coord, top_coord});
                field.black_kings[{pos_x, pos_y}] = true;
                field.blackturns.erase({left_coord, top_coord});
                field.blackturns[{pos_x, pos_y}] = true;
                if (field.white_queens.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else {
                field.white_queens.erase({left_coord, top_coord});
                field.white_queens[{pos_x, pos_y}] = true;
                field.whiteturns.erase({left_coord, top_coord});
                field.whiteturns[{pos_x, pos_y}] = true;
                if (field.black_kings.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            left_coord = pos_x;
            top_coord = pos_y;
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            return true;
        }
        if (left_coord < storage_killers.begin()->first.first && top_coord < storage_killers.begin()->first.second) {
            map<pair<short, short>, bool> positions_to_stay;
            short i = storage_killers.begin()->first.first + 1;
            short j = storage_killers.begin()->first.second + 1;
            while (i < 9 && j < 9) {
                if (field.field[i][j] != '-')
                    break;
                positions_to_stay[{i, j}] = true;
                i += 1;
                j += 1;
            }
            if (positions_to_stay.empty())
                return false;
            short pos_x = -1, pos_y = -1;
            if (is_it_comp) {
                pair<short, short> choose = choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                cout << "choose position to stay your figure in :\n";
                for (auto z : positions_to_stay) {
                    cout << z.first.first << ' ' << z.first.second << '\n';
                }

                while (positions_to_stay.count({pos_x, pos_y}) != true) {
                    cin >> pos_x >> pos_y;
                }
            }
            field.field[pos_x][pos_y] = field.field[left_coord][top_coord];
            field.field[left_coord][top_coord] = '-';
            if (field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'q' ||
                field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'w') {
                field.black_kings.erase({left_coord, top_coord});
                field.black_kings[{pos_x, pos_y}] = true;
                field.blackturns.erase({left_coord, top_coord});
                field.blackturns[{pos_x, pos_y}] = true;
                if (field.white_queens.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else {
                field.white_queens.erase({left_coord, top_coord});
                field.white_queens[{pos_x, pos_y}] = true;
                field.whiteturns.erase({left_coord, top_coord});
                field.whiteturns[{pos_x, pos_y}] = true;
                if (field.black_kings.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            left_coord = pos_x;
            top_coord = pos_y;
            return true;
        }
        if (left_coord > storage_killers.begin()->first.first && top_coord < storage_killers.begin()->first.second) {
            map<pair<short, short>, bool> positions_to_stay;
            short i = storage_killers.begin()->first.first - 1;
            short j = storage_killers.begin()->first.second + 1;
            while (i >= 1 && j < 9) {
                if (field.field[i][j] != '-')
                    break;
                positions_to_stay[{i, j}] = true;
                i -= 1;
                j += 1;
            }
            if (positions_to_stay.empty())
                return false;

            short pos_x = -1, pos_y = -1;
            if (is_it_comp) {
                pair<short, short> choose = choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                cout << "choose position to stay your figure in :\n";
                for (auto z : positions_to_stay) {
                    cout << z.first.first << ' ' << z.first.second << '\n';
                }

                while (positions_to_stay.count({pos_x, pos_y}) != true) {
                    cin >> pos_x >> pos_y;
                }
            }
            field.field[pos_x][pos_y] = field.field[left_coord][top_coord];
            field.field[left_coord][top_coord] = '-';
            if (field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'q' ||
                field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'w') {
                field.black_kings.erase({left_coord, top_coord});
                field.black_kings[{pos_x, pos_y}] = true;
                field.blackturns.erase({left_coord, top_coord});
                field.blackturns[{pos_x, pos_y}] = true;
                if (field.white_queens.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else {
                field.white_queens.erase({left_coord, top_coord});
                field.white_queens[{pos_x, pos_y}] = true;
                field.whiteturns.erase({left_coord, top_coord});
                field.whiteturns[{pos_x, pos_y}] = true;
                if (field.black_kings.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            left_coord = pos_x;
            top_coord = pos_y;
            return true;
        }
        if (left_coord < storage_killers.begin()->first.first && top_coord > storage_killers.begin()->first.second) {
            map<pair<short, short>, bool> positions_to_stay;
            short i = storage_killers.begin()->first.first + 1;
            short j = storage_killers.begin()->first.second - 1;
            while (i < 9 && j >= 1) {
                if (field.field[i][j] != '-')
                    break;
                positions_to_stay[{i, j}] = true;
                i += 1;
                j -= 1;
            }
            if (positions_to_stay.empty())
                return false;
            short pos_x = -1, pos_y = -1;
            if (is_it_comp) {
                pair<short, short> choose = choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                cout << "choose position to stay your figure in :\n";
                for (auto z : positions_to_stay) {
                    cout << z.first.first << ' ' << z.first.second << '\n';
                }

                while (positions_to_stay.count({pos_x, pos_y}) != true) {
                    cin >> pos_x >> pos_y;
                }
            }
            field.field[pos_x][pos_y] = field.field[left_coord][top_coord];
            field.field[left_coord][top_coord] = '-';
            if (field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'q' ||
                field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] == 'w') {
                field.black_kings.erase({left_coord, top_coord});
                field.black_kings[{pos_x, pos_y}] = true;
                field.blackturns.erase({left_coord, top_coord});
                field.blackturns[{pos_x, pos_y}] = true;
                if (field.white_queens.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white_queens.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.whiteturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else {
                field.white_queens.erase({left_coord, top_coord});
                field.white_queens[{pos_x, pos_y}] = true;
                field.whiteturns.erase({left_coord, top_coord});
                field.whiteturns[{pos_x, pos_y}] = true;
                if (field.black_kings.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black_kings.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.blackturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            field.field[storage_killers.begin()->first.first][storage_killers.begin()->first.second] = '-';
            left_coord = pos_x;
            top_coord = pos_y;
            return true;
        }
    }
    return false;
}

