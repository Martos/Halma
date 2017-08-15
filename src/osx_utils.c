/*
    Info : Vedi prototipo
*/
#include <stdio.h>
#include <stdlib.h>

#include "../include/osx_utils.h"

void consolePause() {
    system( "read -n 1 -s -p \"Premi un tasto per continuare...\"" );
    printf("\n");
}

void screenClear() {
    system("clear");
}