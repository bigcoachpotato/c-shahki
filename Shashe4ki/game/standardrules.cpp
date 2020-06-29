#include "standardrules.h"
#include <iostream>
#include "game.h"

using namespace game_space;


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
    if ((figure == 'w' || figure == 'q') && field.black->i_am_computer == true) {
        is_it_comp = true;
    } else if ((figure == 'b' || figure == 'k') && field.white->i_am_computer == true) {
        is_it_comp = true;
    }
    if (figure == 'q' || figure == 'w') {
        if (field.black->myturns.count({left_coord + 1, top_coord + 1}))
            if (left_coord - 1 > -1 && top_coord - 1 > -1 && field.field[left_coord - 1][top_coord - 1] == '-') {
                storage_killers[{left_coord + 1, top_coord + 1}] = true;
            }
        if (field.black->myturns.count({left_coord - 1, top_coord - 1}))
            if (left_coord + 1 < 9 && top_coord + 1 < 9 && field.field[left_coord + 1][top_coord + 1] == '-') {
                storage_killers[{left_coord - 1, top_coord - 1}] = true;
            }
        if (field.black->myturns.count({left_coord + 1, top_coord - 1}))
            if (left_coord - 1 > -1 && top_coord + 1 < 9 && field.field[left_coord - 1][top_coord + 1] == '-') {
                storage_killers[{left_coord + 1, top_coord - 1}] = true;
            }
        if (field.black->myturns.count({left_coord - 1, top_coord + 1}))
            if (left_coord + 1 < 9 && top_coord - 1 > -1 && field.field[left_coord + 1][top_coord - 1] == '-') {
                storage_killers[{left_coord - 1, top_coord + 1}] = true;
            }
    } else if (figure == 'b' || figure == 'k') {
        if (field.white->myturns.count({left_coord + 1, top_coord + 1}))
            if (field.field[left_coord - 1][top_coord - 1] == '-') {
                storage_killers[{left_coord + 1, top_coord + 1}] = true;
            }
        if (field.white->myturns.count({left_coord - 1, top_coord - 1}))
            if (field.field[left_coord + 1][top_coord + 1] == '-') {
                storage_killers[{left_coord - 1, top_coord - 1}] = true;
            }
        if (field.white->myturns.count({left_coord + 1, top_coord - 1}))
            if (field.field[left_coord - 1][top_coord + 1] == '-') {
                storage_killers[{left_coord + 1, top_coord - 1}] = true;
            }
        if (left_coord + 1 < 9 && top_coord - 1 > -1 && field.white->myturns.count({left_coord - 1, top_coord + 1}))
            if (field.field[left_coord + 1][top_coord - 1] == '-') {
                storage_killers[{left_coord - 1, top_coord + 1}] = true;
            }
    }
    if (figure == 'b' || figure == 'k') {
        vector<pair<short, short>> candidates;
        for (auto i : field.white->my_king_turns) {
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
        for (auto i : field.black->my_king_turns) {
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
            pair<short, short> choose = field.white->me->choose_one_of_(storage_killers);
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
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->myturns[{storage_killers.begin()->first.first - 2,
                                      storage_killers.begin()->first.second - 2}] = true;
                if (field.black->my_king_turns.count(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1}) == 0)
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                }
            } else if (who == 'b') {
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->myturns[{storage_killers.begin()->first.first - 2,
                                      storage_killers.begin()->first.second - 2}] = true;
                if (field.white->my_king_turns.count(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1}) == 0)
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                    field.white->myturns.erase(
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
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->myturns[{storage_killers.begin()->first.first + 2,
                                      storage_killers.begin()->first.second + 2}] = true;
                if (field.black->my_king_turns.count(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1}) == 0)
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                }
            } else if (who == 'b') {
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->myturns[{storage_killers.begin()->first.first + 2,
                                      storage_killers.begin()->first.second + 2}] = true;
                if (field.white->my_king_turns.count(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1}) == 0)
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                    field.white->myturns.erase(
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
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->myturns[{storage_killers.begin()->first.first + 2,
                                      storage_killers.begin()->first.second - 2}] = true;
                if (field.black->my_king_turns.count(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1}) == 0)
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                }
            } else if (who == 'b') {
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->myturns[{storage_killers.begin()->first.first + 2,
                                      storage_killers.begin()->first.second - 2}] = true;
                if (field.white->my_king_turns.count(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1}) == 0)
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                    field.white->myturns.erase(
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
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->myturns[{storage_killers.begin()->first.first - 2,
                                      storage_killers.begin()->first.second + 2}] = true;
                if (field.black->my_king_turns.count(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1}) == 0)
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                }
            } else if (who == 'b') {
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->myturns[{storage_killers.begin()->first.first - 2,
                                      storage_killers.begin()->first.second + 2}] = true;
                if (field.white->my_king_turns.count(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1}) == 0)
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                }
            }
            left_coord = storage_killers.begin()->first.first - 2;
            top_coord = storage_killers.begin()->first.second + 2;
        }
        if (field.field[left_coord][top_coord] == 'w' && left_coord == 1) {
            field.field[left_coord][top_coord] = 'q';
            field.white->my_king_turns[{left_coord, top_coord}] = true;
        } else if (field.field[left_coord][top_coord] == 'b' && left_coord == 8) {
            field.field[left_coord][top_coord] = 'k';
            field.black->my_king_turns[{left_coord, top_coord}] = true;
        }
        while (needs_kill_next(left_coord, top_coord, field)) {
            continue;
            if (field.field[left_coord][top_coord] == 'w' && left_coord == 1) {
                field.field[left_coord][top_coord] = 'q';
                field.white->my_king_turns[{left_coord, top_coord}] = true;
            } else if (field.field[left_coord][top_coord] == 'b' && left_coord == 8) {
                field.field[left_coord][top_coord] = 'k';
                field.black->my_king_turns[{left_coord, top_coord}] = true;
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
                pair<short, short> choose = field.white->me->choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                if (!is_it_comp)
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
                field.black->my_king_turns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->my_king_turns[{pos_x, pos_y}] = true;
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->myturns[{pos_x, pos_y}] = true;
                if (field.white->my_king_turns.count({left_coord, top_coord}) == 0)
                    field.white->myturns.erase({left_coord, top_coord});
                else {
                    field.white->my_king_turns.erase({left_coord, top_coord});
                    field.white->myturns.erase({left_coord, top_coord});
                }
            } else {
                field.white->my_king_turns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->my_king_turns[{pos_x, pos_y}] = true;
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->myturns[{pos_x, pos_y}] = true;
                if (field.black->my_king_turns.count({left_coord, top_coord}) == 0)
                    field.black->myturns.erase({left_coord, top_coord});
                else {
                    field.black->my_king_turns.erase({left_coord, top_coord});
                    field.black->myturns.erase({left_coord, top_coord});
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
                pair<short, short> choose = field.white->me->choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                if (!is_it_comp)
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
                field.black->my_king_turns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->my_king_turns[{pos_x, pos_y}] = true;
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->myturns[{pos_x, pos_y}] = true;
                if (field.white->my_king_turns.count({left_coord, top_coord}) == 0)
                    field.white->myturns.erase({left_coord, top_coord});
                else {
                    field.white->my_king_turns.erase({left_coord, top_coord});
                    field.white->myturns.erase({left_coord, top_coord});
                }
            } else {
                field.white->my_king_turns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->my_king_turns[{pos_x, pos_y}] = true;
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->myturns[{pos_x, pos_y}] = true;
                if (field.black->my_king_turns.count({left_coord, top_coord}) == 0)
                    field.black->myturns.erase({left_coord, top_coord});
                else {
                    field.black->my_king_turns.erase({left_coord, top_coord});
                    field.black->myturns.erase({left_coord, top_coord});
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
                pair<short, short> choose = field.white->me->choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                if (!is_it_comp)
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
                field.black->my_king_turns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->my_king_turns[{pos_x, pos_y}] = true;
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->myturns[{pos_x, pos_y}] = true;
                if (field.white->my_king_turns.count({left_coord, top_coord}) == 0)
                    field.white->myturns.erase({left_coord, top_coord});
                else {
                    field.white->my_king_turns.erase({left_coord, top_coord});
                    field.white->myturns.erase({left_coord, top_coord});
                }
            } else {
                field.white->my_king_turns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->my_king_turns[{pos_x, pos_y}] = true;
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->myturns[{pos_x, pos_y}] = true;
                if (field.black->my_king_turns.count({left_coord, top_coord}) == 0)
                    field.black->myturns.erase({left_coord, top_coord});
                else {
                    field.black->my_king_turns.erase({left_coord, top_coord});
                    field.black->myturns.erase({left_coord, top_coord});
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
                pair<short, short> choose = field.white->me->choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                if (!is_it_comp)
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
                field.black->my_king_turns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->my_king_turns[{pos_x, pos_y}] = true;
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.black->myturns[{pos_x, pos_y}] = true;
                if (field.white->my_king_turns.count({left_coord, top_coord}) == 0)
                    field.white->myturns.erase({left_coord, top_coord});
                else {
                    field.white->my_king_turns.erase({left_coord, top_coord});
                    field.white->myturns.erase({left_coord, top_coord});
                }
            } else {
                field.white->my_king_turns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->my_king_turns[{pos_x, pos_y}] = true;
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                field.white->myturns[{pos_x, pos_y}] = true;
                if (field.black->my_king_turns.count({left_coord, top_coord}) == 0)
                    field.black->myturns.erase({left_coord, top_coord});
                else {
                    field.black->my_king_turns.erase({left_coord, top_coord});
                    field.black->myturns.erase({left_coord, top_coord});
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
    if ((figure == 'w' || figure == 'q') && field.white->i_am_computer == true) {
        is_it_comp = true;
    } else if ((figure == 'b' || figure == 'k') && field.black->i_am_computer == true) {
        is_it_comp = true;
    }
    if (figure == 'w') {
        if (field.black->myturns.count({left_coord + 1, top_coord + 1}))
            if (field.field[left_coord + 2][top_coord + 2] == '-') {
                storage_killers[{left_coord + 1, top_coord + 1}] = true;
            }
        if (field.black->myturns.count({left_coord - 1, top_coord - 1}))
            if (field.field[left_coord - 2][top_coord - 2] == '-') {
                storage_killers[{left_coord - 1, top_coord - 1}] = true;
            }
        if (field.black->myturns.count({left_coord + 1, top_coord - 1}))
            if (field.field[left_coord + 2][top_coord - 2] == '-') {
                storage_killers[{left_coord + 1, top_coord - 1}] = true;
            }
        if (field.black->myturns.count({left_coord - 1, top_coord + 1}))
            if (field.field[left_coord - 2][top_coord + 2] == '-') {
                storage_killers[{left_coord - 1, top_coord + 1}] = true;
            }
    } else if (figure == 'b') {
        if (field.white->myturns.count({left_coord + 1, top_coord + 1}))
            if (field.field[left_coord + 2][top_coord + 2] == '-') {
                storage_killers[{left_coord + 1, top_coord + 1}] = true;
            }
        if (field.white->myturns.count({left_coord - 1, top_coord - 1}))
            if (field.field[left_coord - 2][top_coord - 2] == '-') {
                storage_killers[{left_coord - 1, top_coord - 1}] = true;
            }
        if (field.white->myturns.count({left_coord + 1, top_coord - 1}))
            if (field.field[left_coord + 2][top_coord - 2] == '-') {
                storage_killers[{left_coord + 1, top_coord - 1}] = true;
            }
        if (field.white->myturns.count({left_coord - 1, top_coord + 1}))
            if (field.field[left_coord - 2][top_coord + 2] == '-') {
                storage_killers[{left_coord - 1, top_coord + 1}] = true;
            }
    }
    if (figure == 'k') {
        vector<pair<short, short>> candidates;
        for (auto i : field.white->my_king_turns) {
            if (abs(left_coord - i.first.first) == abs(top_coord - i.first.second) && i.first.first != 8 &&
                i.first.first != 1 && i.first.second != 8 && i.first.second != 1)
                candidates.emplace_back(i.first.first, i.first.second);
        }
        for (auto i : field.white->myturns)
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
        for (auto i : field.black->my_king_turns) {
            if (abs(left_coord - i.first.first) == abs(top_coord - i.first.second) && i.first.first != 8 &&
                i.first.first != 1 && i.first.second != 8 && i.first.second != 1)
                candidates.emplace_back(i.first.first, i.first.second);
        }
        for (auto i : field.black->myturns) {
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
            pair<short, short> choose = field.white->me->choose_one_of_(storage_killers);
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
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                field.white->myturns[{storage_killers.begin()->first.first + 1,
                                      storage_killers.begin()->first.second + 1}] = true;
                if (field.black->myturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else if (figure == 'b') {
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second - 1});
                field.black->myturns[{storage_killers.begin()->first.first + 1,
                                      storage_killers.begin()->first.second + 1}] = true;
                if (field.white->myturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.white->myturns.erase(
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
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                field.white->myturns[{storage_killers.begin()->first.first - 1,
                                      storage_killers.begin()->first.second - 1}] = true;
                if (field.black->myturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else if (figure == 'b') {
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second + 1});
                field.black->myturns[{storage_killers.begin()->first.first - 1,
                                      storage_killers.begin()->first.second - 1}] = true;
                if (field.white->myturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.white->myturns.erase(
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
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                field.white->myturns[{storage_killers.begin()->first.first - 1,
                                      storage_killers.begin()->first.second + 1}] = true;
                if (field.black->myturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else if (figure == 'b') {
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first + 1, storage_killers.begin()->first.second - 1});
                field.black->myturns[{storage_killers.begin()->first.first - 1,
                                      storage_killers.begin()->first.second + 1}] = true;
                if (field.white->myturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.white->myturns.erase(
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
                field.white->myturns.erase(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                field.white->myturns[{storage_killers.begin()->first.first + 1,
                                      storage_killers.begin()->first.second - 1}] = true;
                if (field.black->myturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else if (figure == 'b') {
                field.black->myturns.erase(
                        {storage_killers.begin()->first.first - 1, storage_killers.begin()->first.second + 1});
                field.black->myturns[{storage_killers.begin()->first.first + 1,
                                      storage_killers.begin()->first.second - 1}] = true;
                if (field.white->myturns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}))
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            }
            left_coord = storage_killers.begin()->first.first + 1;
            top_coord = storage_killers.begin()->first.second - 1;
        }
        if (field.field[left_coord][top_coord] == 'w' && left_coord == 1) {
            field.field[left_coord][top_coord] = 'q';
            field.white->my_king_turns[{left_coord, top_coord}] = true;
        } else if (field.field[left_coord][top_coord] == 'b' && left_coord == 8) {
            field.field[left_coord][top_coord] = 'k';
            field.black->my_king_turns[{left_coord, top_coord}] = true;
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
                pair<short, short> choose = field.white->me->choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                if (!is_it_comp)
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
                field.black->my_king_turns.erase({left_coord, top_coord});
                field.black->my_king_turns[{pos_x, pos_y}] = true;
                field.black->myturns.erase({left_coord, top_coord});
                field.black->myturns[{pos_x, pos_y}] = true;
                if (field.white->my_king_turns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else {
                field.white->my_king_turns.erase({left_coord, top_coord});
                field.white->my_king_turns[{pos_x, pos_y}] = true;
                field.white->myturns.erase({left_coord, top_coord});
                field.white->myturns[{pos_x, pos_y}] = true;
                if (field.black->my_king_turns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.black->myturns.erase(
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
                pair<short, short> choose = field.white->me->choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                if (!is_it_comp)
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
                field.black->my_king_turns.erase({left_coord, top_coord});
                field.black->my_king_turns[{pos_x, pos_y}] = true;
                field.black->myturns.erase({left_coord, top_coord});
                field.black->myturns[{pos_x, pos_y}] = true;
                if (field.white->my_king_turns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else {
                field.white->my_king_turns.erase({left_coord, top_coord});
                field.white->my_king_turns[{pos_x, pos_y}] = true;
                field.white->myturns.erase({left_coord, top_coord});
                field.white->myturns[{pos_x, pos_y}] = true;
                if (field.black->my_king_turns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.black->myturns.erase(
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
                pair<short, short> choose = field.white->me->choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                if (!is_it_comp)
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
                field.black->my_king_turns.erase({left_coord, top_coord});
                field.black->my_king_turns[{pos_x, pos_y}] = true;
                field.black->myturns.erase({left_coord, top_coord});
                field.black->myturns[{pos_x, pos_y}] = true;
                if (field.white->my_king_turns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else {
                field.white->my_king_turns.erase({left_coord, top_coord});
                field.white->my_king_turns[{pos_x, pos_y}] = true;
                field.white->myturns.erase({left_coord, top_coord});
                field.white->myturns[{pos_x, pos_y}] = true;
                if (field.black->my_king_turns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.black->myturns.erase(
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
                pair<short, short> choose = field.white->me->choose_one_of_(positions_to_stay);
                positions_to_stay.clear();
                pos_x = choose.first;
                pos_y = choose.second;
            } else {
                if (!is_it_comp)
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
                field.black->my_king_turns.erase({left_coord, top_coord});
                field.black->my_king_turns[{pos_x, pos_y}] = true;
                field.black->myturns.erase({left_coord, top_coord});
                field.black->myturns[{pos_x, pos_y}] = true;
                if (field.white->my_king_turns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.white->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.white->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                }
            } else {
                field.white->my_king_turns.erase({left_coord, top_coord});
                field.white->my_king_turns[{pos_x, pos_y}] = true;
                field.white->myturns.erase({left_coord, top_coord});
                field.white->myturns[{pos_x, pos_y}] = true;
                if (field.black->my_king_turns.count(
                        {storage_killers.begin()->first.first, storage_killers.begin()->first.second}) == 0)
                    field.black->myturns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                else {
                    field.black->my_king_turns.erase(
                            {storage_killers.begin()->first.first, storage_killers.begin()->first.second});
                    field.black->myturns.erase(
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