#ifndef HEADER_H
    #define HEADER_H
    #define OPTION_MAX_LENGTH 34

    void printLogo(void);
    void printGameboard(char board[]);
    void menuSelection(int * choice, char * title, char options[][OPTION_MAX_LENGTH], int numberOfOptions);

    void printTitle(char * title);
    void printMenuOptions(char options[][OPTION_MAX_LENGTH], int numberOfOptions);
    void askForMenuNumber(int * choice, int numberOfOptions);

    void singleplayer(int difficultyLevel);
    void multiplayer(void);

    int drawing(void);
    int anyWinners(char boardState[]);
    void playAgain(void (*mode)(void));
#endif