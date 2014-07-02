#include <stdio.h>
#include "functions.h"

int main(void)
{
    printLogo();

    int menuChoice;
    char mainMenuOptions[][OPTION_MAX_LENGTH] = {"1. Play", "2. Quit"};
    menuSelection(&menuChoice, "MAIN MENU", mainMenuOptions, 2);

    if(menuChoice == 2) {
        printf("\n");
        return 0;
    } else {
        char numberOfPlayersOptions[][OPTION_MAX_LENGTH] = {"1. One player (play with computer)", "2. Two players (play with friend)"};
        menuSelection(&menuChoice, "NUMBER OF PLAYERS", numberOfPlayersOptions, 2);

        if(menuChoice == 2)
            multiplayer();
        else {
            char difficultyLevelOptions[][OPTION_MAX_LENGTH] = {"1. Easy", "2. Medium", "3. Hard"};
            menuSelection(&menuChoice, "DIFFICULTY LEVEL", difficultyLevelOptions, 3);
            singleplayer(menuChoice);
        }
        return 0;
    }
}