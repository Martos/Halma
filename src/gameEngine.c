#include "../include/gameEngine.h"

void errorHandler(int code) {

    switch(code) {
        case 1 : { printf("Error code [%d] : Errore input \n", code); break; }
        case 2 : { printf("Error code [%d] : Mossa invalida \n", code); break; }
        default : { printf("Errore sconosciuto \n"); break; }
    }

}

void initializeBoard(char playerIcon1, char playerIcon2) {
    int i = 0,
        j = 0;

    for (i = 0; i < ROWS; i++) {
        
        for(j = 0; j < COLUMNS; j++){
            if(i == 0 && j < 4) halmaBoard[i][j] = playerIcon1;
            else if(i == 1 && j < 3) halmaBoard[i][j] = playerIcon1;
            else if(i == 2 && j < 2) halmaBoard[i][j] = playerIcon1;
            else if(i == 3 && j < 1) halmaBoard[i][j] = playerIcon1;
            else halmaBoard[i][j] = ' ';

            if(i == 7 && j > 3) halmaBoard[i][j] = playerIcon2;
            else if(i == 6 && j > 4) halmaBoard[i][j] = playerIcon2;
            else if(i == 5 && j > 5) halmaBoard[i][j] = playerIcon2;
            else if(i == 4 && j > 6) halmaBoard[i][j] = playerIcon2;
        }
    }
}

void printMatrix() {
    int i = 0,
        j = 0;
    
    printf("\033[22;33m\n     0  1  2  3  4  5  6  7 \033[0m\n");
    printf("\n");
    for(i = 0; i < ROWS; i++){
        printf("\033[22;33m %d  \033[0m", i);
        for(j = 0; j < COLUMNS; j++){
            printf("[\033[22;34m%c\033[0m]", halmaBoard[i][j]);
            if(j == COLUMNS - 1) printf("\033[0m \n");
        }

    }
}

void move(int holdX, int holdY, int destX, int destY, char giocatore) {
    char app = halmaBoard[holdX][holdY];
    printf("%c", app);
    if (app == giocatore) {
        halmaBoard[holdX][holdY] = ' ';
        halmaBoard[destX][destY] = app;
    } else 
        printf("Invalid \n");
}