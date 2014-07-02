#include <stdio.h>
#include <stdlib.h> /* for srand() in drawing() */
#include <time.h> /* for time() in drawing() */
#include <string.h> /* for strlen() in menuChoose */
#include <stdbool.h> /* for true and false in anyWinners() */

#define OPTION_MAX_LENGTH 40

void printLogo(void);
void menuSelection(int * choice, char * title, char options[][OPTION_MAX_LENGTH], int numberOfOptions);

void printTitle(char * title);
void printMenuOptions(char options[][OPTION_MAX_LENGTH], int numberOfOptions);
void askForMenuNumber(int * choice, int numberOfOptions);

void singleplayer(int difficultyLevel);
void multiplayer(void);

int drawing(void);
bool anyWinners(char boardState[]);

int main(void)
{
    printLogo();

    int mainMenuChoice;
    char mainMenuOptions[][OPTION_MAX_LENGTH] = {"1. Play", "2. Quit"};
    menuSelection(&mainMenuChoice, "MAIN MENU", mainMenuOptions, 2);

    if(mainMenuChoice == 2) {
        printf("\n");
        return 0;
    } else {
        int numberOfPlayers;
        char numberOfPlayersOptions[][OPTION_MAX_LENGTH] = {"1. One player (play with computer)", "2. Two players (play with friend)"};
        menuSelection(&numberOfPlayers, "NUMBER OF PLAYERS", numberOfPlayersOptions, 2);

        if(numberOfPlayers == 2)
            multiplayer();
        else {
            int difficultyLevel;
            char difficultyLevelOptions[][OPTION_MAX_LENGTH] = {"1. Easy", "2. Medium", "3. Hard"};
            menuSelection(&difficultyLevel, "DIFFICULTY LEVEL", difficultyLevelOptions, 3);

            singleplayer(difficultyLevel);
        }
        return 0;
    }
}

void multiplayer(void)
{
    int startingPlayer = drawing();
    printf("   | :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
           "   ==============================================================================\n"
           "   |                                                                            |\n"
           "   |   Let's flip a coin:                                                       |\n"
           "   |   PLAYER %d starts the game!                                                |\n"
           "   |                                                                            |\n"
           "   |                                   |     |                                  |\n"
           "   |                                1  |  2  |  3                               |\n"
           "   |                              _____|_____|_____                             |\n"
           "   |                                   |     |                                  |\n"
           "   |                                4  |  5  |  6                               |\n"
           "   |                              _____|_____|_____                             |\n"
           "   |                                   |     |                                  |\n"
           "   |                                7  |  8  |  9                               |\n"
           "   |                                   |     |                                  |\n"
           "   |                                                                            |\n", startingPlayer);

    int i;
    int field;
    char board[9] = "         "; /* nine spaces, one for each field */

    for(i = 0; 1; i++)
    {
        do {
            printf("   |   Put my symbol at field:                                                  |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            while(!scanf("%d", &field)) getchar(); /* in case you type some letters */
        } while(field < 1 || field > 9);

        /* ask for symbol again if given field is not empty */
        if(board[field-1] != ' ')
        {
            i--;
            continue;
        }

        printf("   |                                                                            |\n"
               "   ==============================================================================\n");

        board[field-1] = i % 2 ? 'X' : 'O';

        /* 5 symbols on gameboard can cause an end of the game (note that we iterate i from 0) */
        if(i > 3 && anyWinners(board))
        {
            printf("   | :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
                   "   ==============================================================================\n"
                   "   |                                                                            |\n"
                   "   |   \"%c\" wins!                                                                |\n"
                   "   |                                                                            |\n"
                   "   |                                   |     |                                  |\n"
                   "   |                                %c  |  %c  |  %c                               |\n"
                   "   |                              _____|_____|_____                             |\n"
                   "   |                                   |     |                                  |\n"
                   "   |                                %c  |  %c  |  %c                               |\n"
                   "   |                              _____|_____|_____                             |\n"
                   "   |                                   |     |                                  |\n"
                   "   |                                %c  |  %c  |  %c                               |\n"
                   "   |                                   |     |                                  |\n"
                   "   |                                                                            |\n"
                   "   ==============================================================================\n", board[field-1], board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);

            int playAgainChoice;
            char playAgainOptions[][OPTION_MAX_LENGTH] = {"1. Yes", "2. No"};
            menuSelection(&playAgainChoice, "DO YOU WANT TO PLAY AGAIN?", playAgainOptions, 2);

            if(playAgainChoice == 1)
                multiplayer();
            else
                printf("\n");

            return;
        }

        if(i == 8)
        {
            printf("   | :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
                   "   ==============================================================================\n"
                   "   |                                                                            |\n"
                   "   |   It's a tie!                                                              |\n"
                   "   |                                                                            |\n"
                   "   |                                   |     |                                  |\n"
                   "   |                                %c  |  %c  |  %c                               |\n"
                   "   |                              _____|_____|_____                             |\n"
                   "   |                                   |     |                                  |\n"
                   "   |                                %c  |  %c  |  %c                               |\n"
                   "   |                              _____|_____|_____                             |\n"
                   "   |                                   |     |                                  |\n"
                   "   |                                %c  |  %c  |  %c                               |\n"
                   "   |                                   |     |                                  |\n"
                   "   |                                                                            |\n"
                   "   ==============================================================================\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);

            int playAgainChoice;
            char playAgainOptions[][OPTION_MAX_LENGTH] = {"1. Yes", "2. No"};
            menuSelection(&playAgainChoice, "DO YOU WANT TO PLAY AGAIN?", playAgainOptions, 2);

            if(playAgainChoice == 1)
                multiplayer();
            else
                printf("\n");

            return;
        }

        int whoseTurnIsIt = (startingPlayer + i) % 2 + 1;

        printf("   | :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
               "   ==============================================================================\n"
               "   |                                                                            |\n"
               "   |   PLAYER %d it's your turn now, make a move!                                |\n"
               "   |                                                                            |\n"
               "   |                                   |     |                                  |\n"
               "   |                                %c  |  %c  |  %c                               |\n"
               "   |                              _____|_____|_____                             |\n"
               "   |                                   |     |                                  |\n"
               "   |                                %c  |  %c  |  %c                               |\n"
               "   |                              _____|_____|_____                             |\n"
               "   |                                   |     |                                  |\n"
               "   |                                %c  |  %c  |  %c                               |\n"
               "   |                                   |     |                                  |\n"
               "   |                                                                            |\n", whoseTurnIsIt, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
    }
        printf("   |                                                                            |\n"
               "   ==============================================================================\n");
}

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

void menuSelection(int * choice, char * title, char options[][OPTION_MAX_LENGTH], int numberOfOptions)
{
    printTitle(title);
    printMenuOptions(options, numberOfOptions);
    askForMenuNumber(choice, numberOfOptions);
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
    int i = 0;
    while(i < numberOfOptions)
    {
        printf("   |   %s", options[i]);
        for(int j = 0; j < 73 - strlen(options[i]); j++)
            printf(" ");
        printf("|\n");
        i++;
    }
    printf("   |                                                                            |\n");
}

void askForMenuNumber(int * choice, int numberOfOptions)
{
    do {
        printf("   |   Type menu number:                                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        while(!scanf("%d", choice)) getchar(); /* in case you type some letters */
    } while(*choice < 1 || *choice > numberOfOptions);
    printf("   |                                                                            |\n"
           "   ==============================================================================\n");
}

void singleplayer(int difficultyLevel)
{
    //body to do
    printf("singleplayer\n");
}

int drawing(void)
{
    srand(time(NULL));
    return rand()%101 < 50 ? 1 : 2;
}

bool anyWinners(char boardState[])
{
    int i;

      /* check every row */
    for(i = 0; i < 7; i += 3)
        if(boardState[i] != ' ' && boardState[i] == boardState[i+1] && boardState[i] == boardState[i+2])
            return true;

      /* check every column */
    for(i = 0; i < 3; i++)
        if(boardState[i] != ' ' && boardState[i] == boardState[i+3] && boardState[i] == boardState[i+6])
            return true;

    /* check diagonals */
    if(boardState[4] != ' ' && ((boardState[0] == boardState[4] && boardState[0] == boardState[8]) || (boardState[2] == boardState[4] && boardState[2] == boardState[6])))
        return true;

    return false;
}