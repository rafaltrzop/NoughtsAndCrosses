#include "view.h"
#include <stdio.h>
#include <string.h> /* for strlen() in printTitle() and printMenuOptions() */

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