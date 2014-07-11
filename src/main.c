#include <stdio.h> /* for printf() */

#include "view.h" /* for printLogo() prototype */
#include "controllers.h" /* for menuSelection() and chooseMode() prototype */
#include "constants.h"

int main(void)
{
    printLogo();

    int menuChoice;
    char mainMenuOptions[][OPTION_MAX_LENGTH] = {
        "1. Play",
        "2. Quit"
    };
    menuSelection(&menuChoice, "MAIN MENU", mainMenuOptions, 2);

    switch(menuChoice)
    {
        case 1:
            chooseMode();
            break;
        case 2:
            printf("   |                                                                        |\n"
                   "   ==========================================================================\n\n");
            break;
    }
    return 0;
}