#ifndef CONTROLLERS_H
    #define CONTROLLERS_H
    #include "constants.h"

    void menuSelection(int * choice, char * title, char options[][OPTION_MAX_LENGTH], int numberOfOptions);
    void askForMenuNumber(int * choice, int numberOfOptions);
    int drawing(void);
    int anyWinners(char boardState[]);
#endif