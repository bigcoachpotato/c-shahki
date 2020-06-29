#include "Person_Interface.h"

char User::win_step(Field &gamefield) {
    if (gamefield.white->myturns.empty())
        return 'b';
    if (gamefield.black->myturns.empty())
        return 'w';
    return 'n';
}

bool User::check_correct(vector<short> situation, char &curturn, Field &gamefield) {
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

vector<short> User::choose_way(char &who_am_i_, Field &field) {
    return vector<short>();
}

pair<short, short> User::choose_one_of_(map<pair<short, short>, bool> &storage_killers) {
    return pair<short, short>();
}