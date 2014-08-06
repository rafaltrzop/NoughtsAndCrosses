#include "core.h"
#include "view.h" /* for prototypes used in menuSelection() */
#include "game_modes.h" /* for prototypes used in chooseMode() */

#include <stdio.h>
#include <stdlib.h> /* for exit() in playAgain() and srand() in drawing() */
#include <time.h> /* for time() in drawing() */

void menuSelection(int * choice, char * title, char * options[], int numberOfOptions)
{
    printTitle(title);
    printMenuOptions(options, numberOfOptions);
    printf("   |                                                                        |\n");
    askForMenuNumber(choice, numberOfOptions);
}

void askForMenuNumber(int * choice, int numberOfOptions)
{
    do {
        printf("   |   Type number:                                                         |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        while(!scanf("%d", choice)) getchar(); /* in case you type some letters */
    } while(*choice < 1 || *choice > numberOfOptions);
}

void chooseMode(void)
{
    int menuChoice;
    char * numberOfPlayersOptions[] = {
        "1. One player (you vs computer)",
        "2. Two players (you vs friend)"
    };
    menuSelection(&menuChoice, "NUMBER OF PLAYERS", numberOfPlayersOptions, 2);

    menuChoice == 1 ? singleplayer() : multiplayer();
}

void playAgain(void (*mode)(void))
{
    int menuChoice;
    char * playAgainOptions[] = {
        "1. Yes",
        "2. No"
    };
    menuSelection(&menuChoice, "DO YOU WANT TO PLAY AGAIN?", playAgainOptions, 2);

    if(menuChoice == 1)
        mode();
    else
        printf("   |                                                                        |\n"
               "   ==========================================================================\n\n");

    exit(EXIT_SUCCESS);
}

int drawing(void)
{
    srand(time(NULL));
    return rand()%101 < 50 ? 1 : 2;
}

int anyWinners(char board[])
{
    int i;

    /* check every row */
    for(i = 0; i < 7; i += 3)
        if(board[i] != ' ' && board[i] == board[i+1] && board[i] == board[i+2])
            return 1;

    /* check every column */
    for(i = 0; i < 3; i++)
        if(board[i] != ' ' && board[i] == board[i+3] && board[i] == board[i+6])
            return 1;

    /* check diagonals */
    if(board[4] != ' ' && ((board[0] == board[4] && board[0] == board[8]) || (board[2] == board[4] && board[2] == board[6])))
        return 1;

    return 0;
}

void checkForEndOfGame(int * i, int * field, char board[], void (*mode)(void))
{
    // 5 symbols or more can cause an end of the game (note that we iterate i from 0)
    // if any of the 9 moves didn't end the game with winner then it is a tie
    if(*i > 3 && anyWinners(board))
    {
        printGameboard(board);
        printf("   |                                \"%c\" WINS!                               |\n", board[*field-1]);
        playAgain(mode);
    } else if(*i == 8) {
        printGameboard(board);
        printf("   |                              IT'S A TIE!                               |\n");
        playAgain(mode);
    }
}