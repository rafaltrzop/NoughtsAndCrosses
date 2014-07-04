#include <stdio.h>
#include "view.h"
#include "controllers.h"
#include "constants.h"

void multiplayer(void);
void singleplayer(int difficultyLevel);

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

void multiplayer(void)
{
    printTitle("GAMEBOARD");
    int startingPlayer = drawing();
    printf("   |   Let's flip a coin:                                                   |\n"
           "   |   PLAYER %d starts the game!                                            |\n", startingPlayer);
    printGameboard("123456789");

    int field;
    char board[9] = "         "; /* nine spaces, one for each field */

    for(int i = 0; 1; i++)
    {
        askForMenuNumber(&field, 9);

        /* ask for symbol again if given field is not empty */
        if(board[field-1] != ' ')
        {
            i--;
            continue;
        }

        printLine();

        board[field-1] = i % 2 ? 'X' : 'O';

        /* 5 symbols on gameboard can cause an end of the game (note that we iterate i from 0) */
        if(i > 3 && anyWinners(board))
        {
            printTitle("GAMEBOARD");
            printf("   |   \"%c\" wins!                                                            |\n", board[field-1]);
            printGameboard(board);

            playAgain(multiplayer);
        }

        if(i == 8)
        {
            printTitle("GAMEBOARD");
            printf("   |   It's a tie!                                                          |\n");
            printGameboard(board);

            playAgain(multiplayer);
        }

        int whoseTurnIsIt = (startingPlayer + i) % 2 + 1;

        printTitle("GAMEBOARD");
        printf("   |   PLAYER %d it's your turn now, make a move!                            |\n", whoseTurnIsIt);
        printGameboard(board);
    }
    printLine();
}

void singleplayer(int difficultyLevel)
{
    //body to do
    printf("singleplayer level: %d\n", difficultyLevel);
}