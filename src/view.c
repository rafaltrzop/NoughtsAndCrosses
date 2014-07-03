#include "view.h"
#include "controllers.h" /* for "mess" to work */
#include <stdio.h>
#include <stdlib.h> /* for exit() in playAgain() */
#include <string.h> /* for strlen() in printTitle() and printMenuOptions() */

/* mess =============================================================================== */

void multiplayer(void)
{
    printTitle("GAMEBOARD");
    int startingPlayer = drawing();
    printf("   |   Let's flip a coin:                                                       |\n"
           "   |   PLAYER %d starts the game!                                                |\n", startingPlayer);
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
            printf("   |   \"%c\" wins!                                                                |\n", board[field-1]);
            printGameboard(board);

            playAgain(multiplayer);
        }

        if(i == 8)
        {
            printTitle("GAMEBOARD");
            printf("   |   It's a tie!                                                              |\n");
            printGameboard(board);

            playAgain(multiplayer);
        }

        int whoseTurnIsIt = (startingPlayer + i) % 2 + 1;

        printTitle("GAMEBOARD");
        printf("   |   PLAYER %d it's your turn now, make a move!                                |\n", whoseTurnIsIt);
        printGameboard(board);
    }
    printLine();
}

void singleplayer(int difficultyLevel)
{
    //body to do
    printf("singleplayer level: %d\n", difficultyLevel);
}

void playAgain(void (*mode)(void))
{
    printf("   ==============================================================================\n");
    int menuChoice;
    char playAgainOptions[][OPTION_MAX_LENGTH] = {
      "1. Yes",
      "2. No"
    };
    menuSelection(&menuChoice, "DO YOU WANT TO PLAY AGAIN?", playAgainOptions, 2);

    if(menuChoice == 1)
        mode();
    else
        printf("\n");

    exit(EXIT_SUCCESS);
}

/* view =================================================================================*/

void printLogo(void)
{
    /* ASCII Generator http://www.network-science.de/ascii/ (font: kban) */
    printf("\n"
           "   ==============================================================================\n"
           "   |                                                                            |\n"
           "   |                                                                            |\n"
           "   |                                                                            |\n"
           "   |          '|.   '|'                          '||        .                   |\n"
           "   |           |'|   |    ...   ... ...    ... .  || ..   .||.   ....           |\n"
           "   |           | '|. |  .|  '|.  ||  ||   || ||   ||' ||   ||   ||. '           |\n"
           "   |           |   |||  ||   ||  ||  ||    |''    ||  ||   ||   . '|..          |\n"
           "   |          .|.   '|   '|..|'  '|..'|.  '||||. .||. ||.  '|.' |'..|'          |\n"
           "   |                                     .|....'                                |\n"
           "   |                                                                            |\n"
           "   |                                               '||                          |\n"
           "   |                          ....   .. ...      .. ||                          |\n"
           "   |                         '' .||   ||  ||   .'  '||                          |\n"
           "   |                         .|' ||   ||  ||   |.   ||                          |\n"
           "   |                         '|..'|' .||. ||.  '|..'||.                         |\n"
           "   |                                                                            |\n"
           "   |                                                                            |\n"
           "   |             ..|'''.|                                                       |\n"
           "   |           .|'     '  ... ..    ...    ....   ....    ....   ....           |\n"
           "   |           ||          ||' '' .|  '|. ||. '  ||. '  .|...|| ||. '           |\n"
           "   |           '|.      .  ||     ||   || . '|.. . '|.. ||      . '|..          |\n"
           "   |            ''|....'  .||.     '|..|' |'..|' |'..|'  '|...' |'..|'          |\n"
           "   |                                                                            |\n"
           "   |                                                                            |\n"
           "   |                                                                            |\n"
           "   ==============================================================================\n");
}

void printGameboard(char board[])
{
    printf("   |                                                                            |\n"
           "   |                                   |     |                                  |\n"
           "   |                                %c  |  %c  |  %c                               |\n"
           "   |                              _____|_____|_____                             |\n"
           "   |                                   |     |                                  |\n"
           "   |                                %c  |  %c  |  %c                               |\n"
           "   |                              _____|_____|_____                             |\n"
           "   |                                   |     |                                  |\n"
           "   |                                %c  |  %c  |  %c                               |\n"
           "   |                                   |     |                                  |\n"
           "   |                                                                            |\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

void printTitle(char * title)
{
    printf("   | :::: %s ", title);
    for(int i = 0; i < 68 - strlen(title); i++)
        printf(":");
    printf(" |\n"
           "   ==============================================================================\n"
           "   |                                                                            |\n");
}

void printMenuOptions(char options[][OPTION_MAX_LENGTH], int numberOfOptions)
{
    for(int i = 0; i < numberOfOptions; i++)
    {
        printf("   |   %s", options[i]);
        for(int j = 0; j < 73 - strlen(options[i]); j++)
            printf(" ");
        printf("|\n");
    }
    printf("   |                                                                            |\n");
}

void printLine(void)
{
    printf("   |                                                                            |\n"
           "   ==============================================================================\n");
}