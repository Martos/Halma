#include "../include/gameEngine.h"
#include "../include/utils.h"

void errorHandler(int code) {

    switch(code) {
        case 1 : { printf("Error code [%d] : Errore input \n", code); break; }
        case 2 : { printf("Error code [%d] : Mossa invalida \n", code); break; }
        case 3 : { printf("Error code [%d] : Impossibile impostare le icone per i giocatori uguali \n", code); break; }
        default : { printf("Errore sconosciuto \n"); break; }
    }

}

void setIcon(char icon1, char icon2) {
    playerIcon1 = icon1;
    playerIcon2 = icon2;

    if(icon1 == icon2){
        errorHandler(3);
        playerIcon1 = '*';
        playerIcon2 = '+';
        printf("Impostate icone di default \n");
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

void scoreBoard() {
    printf("=====================\n");
    printf("Giocatore 1 (%s%c%s) : %d \n", ANSI_COLOR_BLUE, playerIcon1, ANSI_COLOR_RESET, score1);
    printf("Giocatore 2 (%s%c%s) : %d \n", ANSI_COLOR_RED, playerIcon2, ANSI_COLOR_RESET, score2);
    printf("Mosse rimanenti : %d \n", mosse);
    printf("=====================\n");
}

void printMatrix() {
    int i = 0,
        j = 0;
    
    printf("%s\n     0  1  2  3  4  5  6  7 %s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
    printf("\n");
    for(i = 0; i < ROWS; i++){
        printf("%s %d  %s", ANSI_COLOR_YELLOW ,i , ANSI_COLOR_RESET);
        for(j = 0; j < COLUMNS; j++){
            char app = halmaBoard[i][j];
            if( app == playerIcon1 ){
                printf("[%s%c%s]", ANSI_COLOR_BLUE, halmaBoard[i][j], ANSI_COLOR_RESET);
            } else {
                printf("[%s%c%s]", ANSI_COLOR_RED, halmaBoard[i][j], ANSI_COLOR_RESET);
            }
            if(j == COLUMNS - 1) printf(" \n");
        }
    }
}

bool move(int holdX, int holdY, int destX, int destY, char giocatore) {
    char app = halmaBoard[holdX][holdY];

    if (app == giocatore) {
        halmaBoard[holdX][holdY] = ' ';
        halmaBoard[destX][destY] = app;
        return true;
    } else {
        errorHandler(2);
        consolePause();
        return false;
    }

}

void gameGuide() {
   printf("Il gioco della Halma e' un gioco per due persone.\n");
   printf("Il tavoliere e' costituito da 8x8 caselle.\n \n");
   printf("Lo scopo del gioco e' di muovere le proprie pedine dentro tutte le caselle nella zona di partenza dell'avversario.\n");
   printf("Il giocatore che realizza questo per primo, vince.\n");
   printf("Al proprio turno ciascun giocatore puo'muovere solo una pedina. \n"); 
   printf("La pedina puo' muovere di uno spazio in qualsiasi direzione purche' la casella di arrivo sia vuota.\n \n");
   printf("Le pedine possono anche saltare pedine dell'avversario.\n");
   printf("Il salto non e' obbligatorio e puo' essere effettuato in tutte le direzioni.\n");
   printf("La pedina puo' solo saltare sopra un'altra pedina verso una casella vuota sulla quale atterrera'.\n"); 
   printf("Se la posizione di arrivo lo permette e' possibile eseguire ulteriori salti.\n \n");
   printf("Le pedine saltate non vengono rimosse ma tutte rimangono sulla tavola di gioco fino alla fine della partita.\n \n");
   printf("La partita finisce quando viene soddisfatta una delle seguenti condizioni: \n \n");
   printf(" -Uno dei giocatori ha mosso tutte le pedine nella zona di partenza dell'avversario.\n  Questo giocatore vince la partita.\n\n");
   printf(" -Uno dei giocatori ha ancora una o piu' pedine nella propria zona di partenza dopo la 30esima mossa. Questo giocatore perde la partita.\n\n");
   printf(" -Il giocatore che ritorna su una delle sue caselle di partenza dopo la 30esima mossa ha altresì perso la partita.\n"); 
   printf("  Questa regola punisce quei giocatori che lasciano e(o) ritornano nelle caselle della propria zona di partenza impedendone l'accesso all'avversario.\n\n\n");
}

