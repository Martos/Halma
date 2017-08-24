/*
    Info : Vedi prototipo
*/
#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"

void consolePause() {
    int c;
    do {
        c = getchar();
    }while(c != '\n' && c != EOF);
    if (c == EOF) {
        // input stream ended, do something about it, exit perhaps
    } else {
        printf("\nPremi un tasto per continuare ...\n");
        getchar();
    }
}

void screenClear() {
    system("clear");
}