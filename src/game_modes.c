#include "game_modes.h"
#include "core.h"
#include "view.h"
#include "ai.h" /* for aiGenerateMove() prototype */

#include <stdio.h>

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
            waitingForMove();
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