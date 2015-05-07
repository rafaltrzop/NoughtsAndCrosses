#ifndef AI_H
  #define AI_H

  #include <stdbool.h> /* for boolean data type in minimax() */

  int minimax(char node[], int depth, bool maximizingPlayer, int * move);
  void aiGenerateMove(int difficultyLevel, int * field, char board[]);
#endif