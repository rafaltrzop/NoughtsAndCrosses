#include <stdio.h>

void onePlayer(void);
void twoPlayers(void);

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
	}	else {

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

		if(numberOfPlayers == 2)
			twoPlayers();
		else
			onePlayer();

		return 0;
	}
}

void onePlayer(void)
{
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




}

















void twoPlayers(void)
{
	printf("Two players\n");
}