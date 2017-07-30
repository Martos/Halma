#define ROWS 16
#define COLUMNS 16

//Mosse massime possibili
#define MAX_MOVE 25

//Area di gioco
static char halmaBoard[ROWS][COLUMNS] = {' '};

//Icone giocatori
char playerIcon1 = '*';
char playerIcon2 = '+';

//Menu principale
void mainMenu(){

}

//Preparazione area di gioco iniziale
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

//stampa il terreno del gioco
void printMatrix(){
    int i,
        j;
    
    for(i = 0; i < ROWS; i++){

        for(j = 0; j < COLUMNS; j++){
            printf("[%c]", halmaBoard[i][j]);
            if(j == 15) printf("\n");
        }

    }
}