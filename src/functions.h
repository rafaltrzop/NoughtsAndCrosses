#ifndef HEADER_H
    #define HEADER_H
    #define OPTION_MAX_LENGTH 32

    /* mess */
    void multiplayer(void);
    void singleplayer(int difficultyLevel);
    void playAgain(void (*mode)(void));

    /* controllers */
    void menuSelection(int * choice, char * title, char options[][OPTION_MAX_LENGTH], int numberOfOptions);
    void askForMenuNumber(int * choice, int numberOfOptions);
    int drawing(void);
    int anyWinners(char boardState[]);

    /* view */
    void printLogo(void);
    void printGameboard(char board[]);
    void printTitle(char * title);
    void printMenuOptions(char options[][OPTION_MAX_LENGTH], int numberOfOptions);
    void printLine(void);
#endif