#ifndef CONTROLLERS_H
    #define CONTROLLERS_H
    #include "constants.h"

    void menuSelection(int * choice, char * title, char options[][OPTION_MAX_LENGTH], int numberOfOptions);
    void askForMenuNumber(int * choice, int numberOfOptions);
    void chooseMode(void);
    void playAgain(void (*mode)(void));
    int drawing(void);
    int anyWinners(char board[]);
    void checkForEndOfGame(int * i, int * field, char board[], void (*mode)(void));
#endif