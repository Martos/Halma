#include "../include/gameEngine.h"

void errorHandler(int code) {
    if (code == 1) {
        printf("Error code [%d] : Errore input \n", code);
    }
}

void initializeBoard(char playerIcon1, char playerIcon2){
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

void printMatrix(){
    int i = 0,
        j = 0;
    
    printf("\n    0  1  2  3  4  5  6  7 \n");
    printf("\n");
    for(i = 0; i < ROWS; i++){
        printf("%d  ", i);
        for(j = 0; j < COLUMNS; j++){
            printf("[%c]", halmaBoard[i][j]);
            if(j == COLUMNS - 1) printf("\n");
        }

    }
}

void move(int x, int y, char giocatore){

}