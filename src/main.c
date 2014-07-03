#include <stdio.h>
#include "view.h"
#include "controllers.h"
#include "constants.h"

int main(void)
{
    printLogo();

    int menuChoice;
    char mainMenuOptions[][OPTION_MAX_LENGTH] = {
        "1. Play",
        "2. Quit"
    };
    menuSelection(&menuChoice, "MAIN MENU", mainMenuOptions, 2);

    if(menuChoice == 2) {
        printf("\n");
    } else {
        char numberOfPlayersOptions[][OPTION_MAX_LENGTH] = {
            "1. One player (you vs computer)",
            "2. Two players (you vs friend)"
        };
        menuSelection(&menuChoice, "NUMBER OF PLAYERS", numberOfPlayersOptions, 2);

        if(menuChoice == 2)
            multiplayer();
        else {
            char difficultyLevelOptions[][OPTION_MAX_LENGTH] = {
                "1. Easy",
                "2. Normal",
                "3. Hard"
            };
            menuSelection(&menuChoice, "DIFFICULTY LEVEL", difficultyLevelOptions, 3);
            singleplayer(menuChoice);
        }
    }
    return 0;
}