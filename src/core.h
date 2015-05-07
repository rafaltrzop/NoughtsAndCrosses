#ifndef CORE_H
    #define CORE_H

    void menuSelection(int * choice, char * title, char * options[], int numberOfOptions);
    void askForMenuNumber(int * choice, int numberOfOptions);
    void chooseMode(void);
    void playAgain(void (*mode)(void));
    int drawing(void);
    int fullBoard(char board[]);
    int whoWon(char ch);
    int anyWinners(char board[]);
    void checkForEndOfGame(int * i, int * field, char board[], void (*mode)(void));
#endif