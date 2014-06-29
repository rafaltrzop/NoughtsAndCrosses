#include <stdio.h>
#include <stdlib.h> /* for srand() in drawing() */
#include <time.h> /* for time() in drawing() */

void singleplayer(int difficultyLevel);
void multiplayer(void);

int drawing(void);
int checkWinner(void);

int main(void)
{
    /* =================== LOGO ==================== */

    /* ASCII Generator http://www.network-science.de/ascii/ (font: kban) */
    printf("\n"
         "   ==============================================================================\n"
         "   |                                                                            |\n"
         "   |                                                                            |\n"
         "   |                                                                            |\n"
         "   |          '|.   '|'                          '||        .                   |\n"
         "   |           |'|   |    ...   ... ...    ... .  || ..   .||.   ....           |\n"
         "   |           | '|. |  .|  '|.  ||  ||   || ||   ||' ||   ||   ||. '           |\n"
         "   |           |   |||  ||   ||  ||  ||    |''    ||  ||   ||   . '|..          |\n"
         "   |          .|.   '|   '|..|'  '|..'|.  '||||. .||. ||.  '|.' |'..|'          |\n"
         "   |                                     .|....'                                |\n"
         "   |                                                                            |\n"
         "   |                                               '||                          |\n"
         "   |                          ....   .. ...      .. ||                          |\n"
         "   |                         '' .||   ||  ||   .'  '||                          |\n"
         "   |                         .|' ||   ||  ||   |.   ||                          |\n"
         "   |                         '|..'|' .||. ||.  '|..'||.                         |\n"
         "   |                                                                            |\n"
         "   |                                                                            |\n"
         "   |             ..|'''.|                                                       |\n"
         "   |           .|'     '  ... ..    ...    ....   ....    ....   ....           |\n"
         "   |           ||          ||' '' .|  '|. ||. '  ||. '  .|...|| ||. '           |\n"
         "   |           '|.      .  ||     ||   || . '|.. . '|.. ||      . '|..          |\n"
         "   |            ''|....'  .||.     '|..|' |'..|' |'..|'  '|...' |'..|'          |\n"
         "   |                                                                            |\n"
         "   |                                                                            |\n"
         "   |                                                                            |\n"
         "   ==============================================================================\n");

    /* =================== MAIN MENU ==================== */

    printf("   | :::: MAIN MENU ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
         "   ==============================================================================\n"
         "   |                                                                            |\n"
         "   |   1. Play                                                                  |\n"
         "   |   2. Quit                                                                  |\n"
         "   |                                                                            |\n");

    int mainMenuChoice;
    do {
        printf("   |   Type menu number:                                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        while(!scanf("%d", &mainMenuChoice)) getchar(); /* in case you type some letters */
    } while(mainMenuChoice != 1 && mainMenuChoice != 2);
    printf("   |                                                                            |\n"
           "   ==============================================================================\n");

    if(mainMenuChoice == 2) {
        printf("\n");
        return 0;
    } else {

        /* =================== NUMBER OF PLAYERS ==================== */

        printf("   | :::: NUMBER OF PLAYERS ::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
           "   ==============================================================================\n"
           "   |                                                                            |\n"
           "   |   1. One player (play with computer)                                       |\n"
           "   |   2. Two players (play with friend)                                        |\n"
           "   |                                                                            |\n");

        int numberOfPlayers;
        do {
            printf("   |   Type menu number:                                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            while(!scanf("%d", &numberOfPlayers)) getchar(); /* in case you type some letters */
        } while(numberOfPlayers != 1 && numberOfPlayers != 2);
        printf("   |                                                                            |\n"
               "   ==============================================================================\n");

        /* =================== DIFFICULTY LEVEL ==================== */

        if(numberOfPlayers == 2)
            multiplayer();
        else {
            printf("   | :::: DIFFICULTY LEVEL :::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
             "   ==============================================================================\n"
             "   |                                                                            |\n"
             "   |   1. Easy                                                                  |\n"
             "   |   2. Medium                                                                |\n"
             "   |   3. Hard                                                                  |\n"
             "   |                                                                            |\n");

            int difficultyLevel ;
            do {
                printf("   |   Type menu number:                                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
                while(!scanf("%d", &difficultyLevel)) getchar(); /* in case you type some letters */
            } while(difficultyLevel != 1 && difficultyLevel != 2 && difficultyLevel != 3);
            printf("   |                                                                            |\n"
                   "   ==============================================================================\n");

            singleplayer(difficultyLevel);
        }
        return 0;
    }
}

void multiplayer(void)
{
    int startingPlayer = drawing();
    printf("   | :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
         "   ==============================================================================\n"
         "   |                                                                            |\n"
         "   |   Let's flip a coin:                                                       |\n"
         "   |   PLAYER %d starts the game!                                                |\n"
         "   |                                                                            |\n"
         "   |                                   |     |                                  |\n"
         "   |                                1  |  2  |  3                               |\n"
         "   |                              _____|_____|_____                             |\n"
         "   |                                   |     |                                  |\n"
         "   |                                4  |  5  |  6                               |\n"
         "   |                              _____|_____|_____                             |\n"
         "   |                                   |     |                                  |\n"
         "   |                                7  |  8  |  9                               |\n"
         "   |                                   |     |                                  |\n"
         "   |                                                                            |\n", startingPlayer);

    int i;
    int field;
    char board[9] = "         ";

    for(i = 0; i < 9; i++)
    {
        do {
            printf("   |   Put my symbol at field:                                                  |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            while(!scanf("%d", &field)) getchar(); /* in case you type some letters */
        } while(field < 1 || field > 9);

        if(board[field-1] != ' ')
        {
            i--;
            continue;
        }

        printf("   |                                                                            |\n"
               "   ==============================================================================\n");

        board[field-1] = i % 2 ? 'X' : 'O';
        int whoseTurnIsIt = (startingPlayer+i) % 2 + 1;

        printf("   | :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: |\n"
             "   ==============================================================================\n"
             "   |                                                                            |\n"
             "   |   PLAYER %d it's your turn now, make a move!                                |\n"
             "   |                                                                            |\n"
             "   |                                   |     |                                  |\n"
             "   |                                %c  |  %c  |  %c                               |\n"
             "   |                              _____|_____|_____                             |\n"
             "   |                                   |     |                                  |\n"
             "   |                                %c  |  %c  |  %c                               |\n"
             "   |                              _____|_____|_____                             |\n"
             "   |                                   |     |                                  |\n"
             "   |                                %c  |  %c  |  %c                               |\n"
             "   |                                   |     |                                  |\n"
             "   |                                                                            |\n", whoseTurnIsIt, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);

        if(i == 5) checkWinner(); /* minimum amount of symbols on gameboard that can cause an end of the game */
    }

        printf("   |                                                                            |\n"
               "   ==============================================================================\n");
}

void singleplayer(int difficultyLevel)
{
    //body to do
    printf("singleplayer\n");
}

int drawing(void)
{
    srand(time(NULL));
    return rand()%101 < 50 ? 1 : 2;
}

int checkWinner(void)
{
    return;
}