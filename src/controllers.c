#include "controllers.h"
#include "view.h" /* for prototypes used in menuSelection() */
#include <stdio.h>
#include <stdlib.h> /* for exit() in playAgain() and srand() in drawing() */
#include <time.h> /* for time() in drawing() */

void menuSelection(int * choice, char * title, char options[][OPTION_MAX_LENGTH], int numberOfOptions)
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

void playAgain(void (*mode)(void))
{
    int menuChoice;
    char playAgainOptions[][OPTION_MAX_LENGTH] = {
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

int anyWinners(char boardState[])
{
    int i;

    /* check every row */
    for(i = 0; i < 7; i += 3)
        if(boardState[i] != ' ' && boardState[i] == boardState[i+1] && boardState[i] == boardState[i+2])
            return 1;

    /* check every column */
    for(i = 0; i < 3; i++)
        if(boardState[i] != ' ' && boardState[i] == boardState[i+3] && boardState[i] == boardState[i+6])
            return 1;

    /* check diagonals */
    if(boardState[4] != ' ' && ((boardState[0] == boardState[4] && boardState[0] == boardState[8]) || (boardState[2] == boardState[4] && boardState[2] == boardState[6])))
        return 1;

    return 0;
}