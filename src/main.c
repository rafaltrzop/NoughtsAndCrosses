#include <stdio.h>

#include "view.h" /* for printLogo() prototype */
#include "core.h" /* for menuSelection() and chooseMode() prototype */
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

    if(menuChoice == 1)
        chooseMode();
    else
        printf("   |                                                                        |\n"
               "   ==========================================================================\n\n");

    return 0;
}