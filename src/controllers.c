#include "controllers.h"
#include "view.h"
#include <stdio.h>
#include <stdlib.h> /* for srand() in drawing() */
#include <time.h> /* for time() in drawing() */

void menuSelection(int * choice, char * title, char options[][OPTION_MAX_LENGTH], int numberOfOptions)
{
    printTitle(title);
    printMenuOptions(options, numberOfOptions);
    askForMenuNumber(choice, numberOfOptions);
    printLine();
}

void askForMenuNumber(int * choice, int numberOfOptions)
{
    do {
        printf("   |   Type number:                                                             |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        while(!scanf("%d", choice)) getchar(); /* in case you type some letters */
    } while(*choice < 1 || *choice > numberOfOptions);
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