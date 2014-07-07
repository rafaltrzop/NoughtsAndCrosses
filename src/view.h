#ifndef VIEW_H
    #define VIEW_H
    #include "constants.h"

    void printLogo(void);
    void printGameboard(char board[]);
    void printTitle(char * title);
    void printMenuOptions(char options[][OPTION_MAX_LENGTH], int numberOfOptions);
#endif