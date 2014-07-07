#include <stdio.h>
#include <stdlib.h> /* for rand() in aiPutSign() */
#include "view.h"
#include "controllers.h"
#include "constants.h"

void multiplayer(void);
void singleplayer(void);
int aiPutSign(int difficultyLevel, char board[]);

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
        else
            singleplayer();
    }
    return 0;
}

void multiplayer(void)
{
    int startingPlayer = drawing();

    printTitle("INSTRUCTIONS");
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

        board[field-1] = i % 2 ? 'O' : 'X';

        /* 5 symbols on gameboard can cause an end of the game (note that we iterate i from 0) */
        if(i > 3 && anyWinners(board))
        {
            printTitle("GAMEBOARD");
            printGameboard(board);
            printf("   |                                \"%c\" WINS!                               |\n", board[field-1]);

            playAgain(multiplayer);
        }

        if(i == 8)
        {
            printTitle("GAMEBOARD");
            printGameboard(board);
            printf("   |                               IT'S A TIE!                              |\n");

            playAgain(multiplayer);
        }

        /* prepare view for the next iteration */
        int whoseTurnIsIt = (startingPlayer + i) % 2 + 1;

        printTitle("GAMEBOARD");
        printf("   |   PLAYER %d it's your turn now, make a move!                            |\n", whoseTurnIsIt);
        printGameboard(board);
    }
}

void singleplayer(void)
{
    /* choose difficulty level */
    int difficultyLevel;
    char difficultyLevelOptions[][OPTION_MAX_LENGTH] = {
        "1. Easy",
        "2. Normal",
        "3. Hard"
    };
    menuSelection(&difficultyLevel, "DIFFICULTY LEVEL", difficultyLevelOptions, 3);

    /* decide who starts the game and print instructions */
    int startingPlayer = drawing();
    char players[2][78] = {
        "   |   YOU start the game!                                                  |",
        "   |   COMPUTER starts the game!                                            |"
    };

    printTitle("INSTRUCTIONS");
    printf("   |   Let's flip a coin:                                                   |\n"
           "%s\n", players[startingPlayer-1]);
    printGameboard("123456789");

    int field;
    char board[9] = "         "; /* nine spaces, one for each field */

    for(int i = 0; 1; i++)
    {
        int whoseTurnIsIt = (startingPlayer + i) % 2;

        /* depending on player ask for sign or run AI */
        if(whoseTurnIsIt == 1)
        {
            askForMenuNumber(&field, 9);

            /* ask for symbol again if given field is not empty */
            if(board[field-1] != ' ')
            {
                i--;
                continue;
            }

            board[field-1] = i % 2 ? 'O' : 'X';

            /* 5 symbols on gameboard can cause an end of the game (note that we iterate i from 0) */
            if(i > 3 && anyWinners(board))
            {
                printTitle("GAMEBOARD");
                printGameboard(board);
                printf("   |                                \"%c\" WINS!                               |\n", board[field-1]);

                playAgain(singleplayer);
            }

            if(i == 8)
            {
                printTitle("GAMEBOARD");
                printGameboard(board);
                printf("   |                               IT'S A TIE!                              |\n");

                playAgain(singleplayer);
            }

            /* prepare view for the next iteration */
            printTitle("GAMEBOARD");
            printf("   |   COMPUTER is making a move!                                           |\n");
            printGameboard(board);
        } else {
            int field = aiPutSign(difficultyLevel, board);
            board[field-1] = i % 2 ? 'O' : 'X';
            printf("   |   Type number: %d                                                       |\n", field);

            /* 5 symbols on gameboard can cause an end of the game (note that we iterate i from 0) */
            if(i > 3 && anyWinners(board))
            {
                printTitle("GAMEBOARD");
                printGameboard(board);
                printf("   |                                \"%c\" WINS!                               |\n", board[field-1]);

                playAgain(singleplayer);
            }

            if(i == 8)
            {
                printTitle("GAMEBOARD");
                printGameboard(board);
                printf("   |                              IT'S A TIE!                               |\n");

                playAgain(singleplayer);
            }

            /* prepare view for the next iteration */
            printTitle("GAMEBOARD");
            printf("   |   YOUR turn now, make a move!                                          |\n");
            printGameboard(board);
        }
    }
}

int aiPutSign(int difficultyLevel, char board[])
{
    if(difficultyLevel == 1)
    {
        int field = rand() % 9 + 1; /* use seed from drawing() function */
        return board[field-1] == ' ' ? field : aiPutSign(difficultyLevel, board);
    } else if(difficultyLevel == 2)
    {
        //to do
        return 2;
    } else if(difficultyLevel == 3)
    {
        //to do
        return 3;
    }
}