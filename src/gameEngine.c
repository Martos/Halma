#include "../include/gameEngine.h"

int mainMenu(){
    int scelta;
    printf("=======================\n");
    printf("        HALMA-CLI      \n");
    printf("=======================\n");

    printf("1) Gioca ! \n");
    printf("2) Personalizza icone \n");
    printf("0) Esci \n");

    scanf("%d", &scelta);

    return scelta;
}

void initializeBoard(char playerIcon1, char playerIcon2){
    int i = 0,
        j = 0;

    for (i = 0; i < ROWS; i++) {
        
        for(j = 0; j < COLUMNS; j++){

            if(i == 0 && j < 6) halmaBoard[i][j] = playerIcon1;
            else if(i == 1 && j < 5) halmaBoard[i][j] = playerIcon1;
            else if(i == 2 && j < 4) halmaBoard[i][j] = playerIcon1;
            else if(i == 3 && j < 3) halmaBoard[i][j] = playerIcon1;
            else if(i == 4 && j < 2) halmaBoard[i][j] = playerIcon1;
            else if(i == 5 && j < 1) halmaBoard[i][j] = playerIcon1;
            else halmaBoard[i][j] = ' ';

            if(i == 15 && j > 9) halmaBoard[i][j] = playerIcon2;
            else if(i == 14 && j > 10) halmaBoard[i][j] = playerIcon2;
            else if(i == 13 && j > 11) halmaBoard[i][j] = playerIcon2;
            else if(i == 12 && j > 12) halmaBoard[i][j] = playerIcon2;
            else if(i == 11 && j > 13) halmaBoard[i][j] = playerIcon2;
            else if(i == 10 && j > 14) halmaBoard[i][j] = playerIcon2;
        }
    }
}

void printMatrix(){
    int i = 0,
        j = 0;
    
    for(i = 0; i < ROWS; i++){

        for(j = 0; j < COLUMNS; j++){
            printf("[%c]", halmaBoard[i][j]);
            if(j == 15) printf("\n");
        }

    }
}

void move(){

}