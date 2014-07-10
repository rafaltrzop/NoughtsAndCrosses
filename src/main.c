#include <stdio.h>
#include <stdlib.h> /* for rand() in aiPutSign() */
#include "view.h"
#include "controllers.h"
#include "constants.h"

void multiplayer(void);
void singleplayer(void);
void aiGenerateMove(int difficultyLevel, int * field, char board[]);

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
        printTitle("GAMEBOARD");
        checkForEndOfGame(&i, &field, board, multiplayer);

        /* prepare view for the next iteration */
        int whoseTurnIsIt = (startingPlayer + i) % 2 + 1;
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
    char player[2][78] = {
        "   |   YOU start the game!                                                  |",
        "   |   COMPUTER starts the game!                                            |"
    };

    printTitle("INSTRUCTIONS");
    printf("   |   Let's flip a coin:                                                   |\n"
           "%s\n", player[startingPlayer-1]);
    printGameboard("123456789");

    int field;
    char board[9] = "         "; /* nine spaces, one for each field */

    for(int i = 0; 1; i++)
    {
        int whoseTurnIsIt = (startingPlayer + i) % 2;

        /* depending on player ask for sign or run AI */
        if(whoseTurnIsIt)
        {
            askForMenuNumber(&field, 9);

            /* ask for symbol again if given field is not empty */
            if(board[field-1] != ' ')
            {
                i--;
                continue;
            }
        } else {
            aiGenerateMove(difficultyLevel, &field, board);
            printf("   |   Type number: %d                                                       |\n", field);
        }

        board[field-1] = i % 2 ? 'O' : 'X';
        printTitle("GAMEBOARD");

        checkForEndOfGame(&i, &field, board, singleplayer);

        /* prepare view for the next iteration */
        if(whoseTurnIsIt)
            printf("   |   COMPUTER is making a move!                                           |\n");
        else
            printf("   |   YOUR turn now, make a move!                                          |\n");

        printGameboard(board);
    }
}

void aiGenerateMove(int difficultyLevel, int * field, char board[])
{
    if(difficultyLevel == 1)
        do {
            *field = rand() % 9 + 1; /* use seed from drawing() function */
        } while(board[*field-1] != ' ');

    if(difficultyLevel == 2)
    {
        int cantBlock = 1;
        int i;

        // X X -
        // Y Y -
        // Z Z -
        for(i = 0; i < 7; i += 3)
            if(board[i] != ' ' && board[i] == board[i+1] && board[i+2] == ' ')
            {
                *field = i + 3;
                cantBlock = 0;
                break;
            }

        // - X X
        // - Y Y
        // - Z Z
        for(i = 1; i < 8; i += 3)
            if(board[i] != ' ' && board[i] == board[i+1] && board[i-1] == ' ')
            {
                *field = i;
                cantBlock = 0;
                break;
            }

        // X - X
        // Y - Y
        // Z - Z
        for(i = 0; i < 7; i += 3)
            if(board[i] != ' ' && board[i] == board[i+2] && board[i+1] == ' ')
            {
                *field = i + 2;
                cantBlock = 0;
                break;
            }

        // X Y Z
        // X Y Z
        // - - -
        for(i = 0; i < 3; i++)
            if(board[i] != ' ' && board[i] == board[i+3] && board[i+6] == ' ')
            {
                *field = i + 7;
                cantBlock = 0;
                break;
            }

        // - - -
        // X Y Z
        // X Y Z
        for(i = 3; i < 6; i++)
            if(board[i] != ' ' && board[i] == board[i+3] && board[i-3] == ' ')
            {
                *field = i - 2;
                cantBlock = 0;
                break;
            }

        // X Y Z
        // - - -
        // X Y Z
        for(i = 0; i < 3; i++)
            if(board[i] != ' ' && board[i] == board[i+6] && board[i+3] == ' ')
            {
                *field = i + 4;
                cantBlock = 0;
                break;
            }

        // X - -
        // - X -
        // - - -
        if(board[0] != ' ' && board[0] == board[4] && board[8] == ' ')
        {
            *field = 9;
            cantBlock = 0;
        }

        // - - -
        // - X -
        // - - X
        if(board[4] != ' ' && board[4] == board[8] && board[0] == ' ')
        {
            *field = 1;
            cantBlock = 0;
        }

        // X - -
        // - - -
        // - - X
        if(board[0] != ' ' && board[0] == board[8] && board[4] == ' ')
        {
            *field = 5;
            cantBlock = 0;
        }

        // - - X
        // - X -
        // - - -
        if(board[2] != ' ' && board[2] == board[4] && board[6] == ' ')
        {
            *field = 7;
            cantBlock = 0;
        }

        // - - -
        // - X -
        // X - -
        if(board[4] != ' ' && board[4] == board[6] && board[2] == ' ')
        {
            *field = 3;
            cantBlock = 0;
        }

        // - - X
        // - - -
        // X - -
        if(board[2] != ' ' && board[2] == board[6] && board[4] == ' ')
        {
            *field = 5;
            cantBlock = 0;
        }

        if(cantBlock) aiGenerateMove(1, field, board);
    }

    if(difficultyLevel > 2)
    {
        //to do
    }
}