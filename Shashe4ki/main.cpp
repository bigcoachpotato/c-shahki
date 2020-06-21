#include "strategies/computerlogic.h"
#include "game/game.h"
#include "strategies/field.h"


enum Type_Of_Game {
    CVC,
    PVC,
    CVP,
    PVP
};

Type_Of_Game type_of_game() {
    cout
            << "Choose the number of type of game:\n 1. CVC - computer VS computer(they have simple but different strategies of game)\n 2. PVC - player VS computer if u want play for white.\n 3. CVP - player VS computer if u want play for black.\n 4. PVP - Player VS Player game\n ";
    short game_type;
    cin >> game_type;
    while (game_type < 1 || game_type > 4) {
        cout << "Choose other option";
        cin >> game_type;
    }
    Type_Of_Game type;
    switch (game_type) {
        case 1: {
            type = CVC;
            break;
        }
        case 2: {
            type = PVC;
            break;
        }
        case 3: {
            type = CVP;
            break;
        }
        case 4: {
            type = PVP;
            break;
        }
        default:
            cout << "Choose other option\n ";
            break;
    }
    return type;
}

Field gameoptions() {
    Type_Of_Game is_type = type_of_game();
    switch (is_type) {
        case PVP: {
            Field gamefield(false, false);
            return gamefield;
        }
        case CVP: {
            Field gamefield(true, false);
            return gamefield;
        }
        case PVC: {
            Field gamefield(false, true);
            return gamefield;
        }
        case CVC: {
            Field gamefield(true, true, true);
            return gamefield;
        }
    }
}

int main() {
    Field gamefield = gameoptions();
    char curturn = 'w';
    for (int i = 0; i < 450; i++) {
        gamefield.write();
        game(gamefield, curturn);
    }
    cout << "\nTIE\n";
    return 0;
}
