#include "ai.h"
#include "core.h" /* for prototypes used in minimax() */

#include <stdlib.h>
#include <string.h> /* for memcpy() in minimax() */
#include <stdbool.h> /* for boolean data type in minimax() */

int minimax(char node[], int depth, bool maximizingPlayer, int * move)
{
  int gameResult = anyWinners(node);
  if(depth == 0 || gameResult || fullBoard(node)) /* depth == 0 or node is a terminal node */
    return gameResult * (depth+1);

  int bestValue, val;
  if (maximizingPlayer)
  {
    bestValue = -11;
    for(int i = 0; i < 9; i++)
    {
      if(node[i] == ' ')
      {
        char child[9];
        memcpy(child, node, 9 * sizeof(char));
        child[i] = 'X';

        val = minimax(child, depth - 1, false, move);
        if(val > bestValue)
        {
          bestValue = val;
          if(depth == 9) *move = i;
        }
      }
    }
    return bestValue;
  } else {
    bestValue = 11;
    for(int i = 0; i < 9; i++) {
      if(node[i] == ' ')
      {
        char child[9];
        memcpy(child, node, 9 * sizeof(char));
        child[i] = 'O';

        val = minimax(child, depth - 1, true, move);
        bestValue = bestValue < val ? bestValue : val;
      }
    }
    return bestValue;
  }
}

void aiGenerateMove(int difficultyLevel, int * field, char board[])
{
    if(difficultyLevel == 1)
        do {
            *field = rand() % 9 + 1; /* use seed from drawing() function */
        } while(board[*field-1] != ' ');
    else if(difficultyLevel == 2) {
        int i;

        // X X -
        // Y Y -
        // Z Z -
        for(i = 0; i < 7; i += 3)
            if(board[i] != ' ' && board[i] == board[i+1] && board[i+2] == ' ')
            {
                *field = i + 3;
                return;
            }

        // - X X
        // - Y Y
        // - Z Z
        for(i = 1; i < 8; i += 3)
            if(board[i] != ' ' && board[i] == board[i+1] && board[i-1] == ' ')
            {
                *field = i;
                return;
            }

        // X - X
        // Y - Y
        // Z - Z
        for(i = 0; i < 7; i += 3)
            if(board[i] != ' ' && board[i] == board[i+2] && board[i+1] == ' ')
            {
                *field = i + 2;
                return;
            }

        // X Y Z
        // X Y Z
        // - - -
        for(i = 0; i < 3; i++)
            if(board[i] != ' ' && board[i] == board[i+3] && board[i+6] == ' ')
            {
                *field = i + 7;
                return;
            }

        // - - -
        // X Y Z
        // X Y Z
        for(i = 3; i < 6; i++)
            if(board[i] != ' ' && board[i] == board[i+3] && board[i-3] == ' ')
            {
                *field = i - 2;
                return;
            }

        // X Y Z
        // - - -
        // X Y Z
        for(i = 0; i < 3; i++)
            if(board[i] != ' ' && board[i] == board[i+6] && board[i+3] == ' ')
            {
                *field = i + 4;
                return;
            }

        // X - -
        // - X -
        // - - -
        if(board[0] != ' ' && board[0] == board[4] && board[8] == ' ')
        {
            *field = 9;
            return;
        }

        // - - -
        // - X -
        // - - X
        if(board[4] != ' ' && board[4] == board[8] && board[0] == ' ')
        {
            *field = 1;
            return;
        }

        // X - -
        // - - -
        // - - X
        if(board[0] != ' ' && board[0] == board[8] && board[4] == ' ')
        {
            *field = 5;
            return;
        }

        // - - X
        // - X -
        // - - -
        if(board[2] != ' ' && board[2] == board[4] && board[6] == ' ')
        {
            *field = 7;
            return;
        }

        // - - -
        // - X -
        // X - -
        if(board[4] != ' ' && board[4] == board[6] && board[2] == ' ')
        {
            *field = 3;
            return;
        }

        // - - X
        // - - -
        // X - -
        if(board[2] != ' ' && board[2] == board[6] && board[4] == ' ')
        {
            *field = 5;
            return;
        }

        aiGenerateMove(1, field, board);
    }
}