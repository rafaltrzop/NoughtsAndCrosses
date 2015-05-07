#include "view.h"

#include <stdio.h>
#include <unistd.h> /* for sleep() in waitingForMove() */
#include <string.h> /* for strlen() in printTitle() and printMenuOptions() */

void printLogo(void)
{
  /* ASCII Generator http://www.network-science.de/ascii/ (font: kban) */
  printf("\n"
         "   ==========================================================================\n"
         "   |                                                                        |\n"
         "   |                                                                        |\n"
         "   |                                                                        |\n"
         "   |        '|.   '|'                          '||        .                 |\n"
         "   |         |'|   |    ...   ... ...    ... .  || ..   .||.   ....         |\n"
         "   |         | '|. |  .|  '|.  ||  ||   || ||   ||' ||   ||   ||. '         |\n"
         "   |         |   |||  ||   ||  ||  ||    |''    ||  ||   ||   . '|..        |\n"
         "   |        .|.   '|   '|..|'  '|..'|.  '||||. .||. ||.  '|.' |'..|'        |\n"
         "   |                                   .|....'                              |\n"
         "   |                                                                        |\n"
         "   |                                             '||                        |\n"
         "   |                        ....   .. ...      .. ||                        |\n"
         "   |                       '' .||   ||  ||   .'  '||                        |\n"
         "   |                       .|' ||   ||  ||   |.   ||                        |\n"
         "   |                       '|..'|' .||. ||.  '|..'||.                       |\n"
         "   |                                                                        |\n"
         "   |                                                                        |\n"
         "   |           ..|'''.|                                                     |\n"
         "   |         .|'     '  ... ..    ...    ....   ....    ....   ....         |\n"
         "   |         ||          ||' '' .|  '|. ||. '  ||. '  .|...|| ||. '         |\n"
         "   |         '|.      .  ||     ||   || . '|.. . '|.. ||      . '|..        |\n"
         "   |          ''|....'  .||.     '|..|' |'..|' |'..|'  '|...' |'..|'        |\n"
         "   |                                                                        |\n"
         "   |                                                                        |\n");
}

void printGameboard(char board[])
{
  printf("   |                                                                        |\n"
         "   |                                 |     |                                |\n"
         "   |                              %c  |  %c  |  %c                             |\n"
         "   |                            _____|_____|_____                           |\n"
         "   |                                 |     |                                |\n"
         "   |                              %c  |  %c  |  %c                             |\n"
         "   |                            _____|_____|_____                           |\n"
         "   |                                 |     |                                |\n"
         "   |                              %c  |  %c  |  %c                             |\n"
         "   |                                 |     |                                |\n"
         "   |                                                                        |\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

void printTitle(char * title)
{
  printf("   |                                                                        |\n"
         "   ==========================================================================\n"
         "   | :::: %s ", title);
  for(int i = 0; i < 64 - strlen(title); i++)
    printf(":");
  printf(" |\n"
         "   ==========================================================================\n"
         "   |                                                                        |\n");
}

void printMenuOptions(char * options[], int numberOfOptions)
{
  for(int i = 0; i < numberOfOptions; i++)
  {
    printf("   |   %s", options[i]);
    for(int j = 0; j < 69 - strlen(options[i]); j++)
      printf(" ");
    printf("|\n");
  }
}

void waitingForMove(void)
{
  printf("   |   Thinking.                                                            |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
  for(int i = 0; i < 2; i++)
  {
    fflush(stdout);
    sleep(1);
    printf(".");
  }
  printf("\n");
}