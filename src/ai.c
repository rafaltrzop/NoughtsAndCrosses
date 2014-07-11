#include "ai.h"

#include <stdlib.h>

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

    if(difficultyLevel == 3)
    {
        //to do
    }
}