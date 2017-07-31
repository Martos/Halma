#include "../include/osx_utils.h"

void consolePause() {
    system( "read -n 1 -s -p \"Premi un tasto per continuare...\"" );
    printf("\n");
}