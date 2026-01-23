#include "epid.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Mainfunktion
int main(void)
{
    srand((unsigned int)time(NULL)); // starter ved et tilfældigt tal, da rand teknisk set ikke er tilfældig;

    brugerInput();

    return 0;
}
