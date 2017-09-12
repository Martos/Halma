#include "../include/gameEngine.h"

void errorHandler(int code) {

    switch(code) {
        case 1 : { printf("%sError code [%d] %s: Errore input \n", ANSI_COLOR_RED, code, ANSI_COLOR_RESET); break; }
        case 2 : { printf("%sError code [%d] %s: Mossa invalida \n", ANSI_COLOR_RED, code, ANSI_COLOR_RESET); break; }
        case 3 : { printf("%sError code [%d] %s: Impossibile impostare le icone per i giocatori uguali \n", ANSI_COLOR_RED, code, ANSI_COLOR_RESET); break; }
        default : { printf("%sErrore sconosciuto%s \n", ANSI_COLOR_RED, ANSI_COLOR_RESET); break; }
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

    mosse = 30;

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
    int distance = fabs( sqrt( pow(holdX-destX, 2) + pow(holdY-destY, 2) ) );

    bool validMove = false;

    if (distance == 1 && app == giocatore) {

        if (halmaBoard[destX][destY] != ' ') {
            
            validMove = false;
            errorHandler(2);
            consolePause();
            

        } else {

            validMove = true;
            halmaBoard[holdX][holdY] = ' ';
            halmaBoard[destX][destY] = app;
    
            mosse--;
            
        }

    } else if (distance == 2 && app == giocatore) {

        if (halmaBoard[destX][destY] == ' ' && ((halmaBoard[destX - 1][destY] != ' ' || halmaBoard[destX + 1][destY] != ' ') 
            || (halmaBoard[destX][destY - 1] != ' ' || halmaBoard[destX][destY + 1] != ' ') 
                || (halmaBoard[destX+1][destY+1] != ' ' || halmaBoard[destX - 1][destY - 1] != ' '))) {

                    if (halmaBoard[destX][destY] != ' ') {

                        validMove = false;
                        errorHandler(2);
                        consolePause();
                        
                    } else {

                        validMove = true;
                        halmaBoard[holdX][holdY] = ' ';
                        halmaBoard[destX][destY] = app;
    
                        mosse--;

                    }

        } else {

            validMove = false;
            errorHandler(2);
            consolePause();

        }

    } else {

        validMove = false;
        errorHandler(2);
        consolePause();

    }

    return validMove;

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

void info() {
    screenClear();
    printf("HALMA-CLI V%s", PRODUCT_VERSION);
    printf("\n");
    printf("Videogioco OpenSource realizzato da Mauro Cipriani, Paolo Laddomada\n");
    printf("Visita la pagina web di github per maggiori informazioni !\n");
    printf("\n");
    printf("%sPIATTAFORME SUPPORTATE%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("-Windows : XPSP3, 7, 8.1, 10 (32/64)\n");
    printf("-OSX : 10.6 or earlier (64)\n");
    printf("-Linux : Ubuntu 14.04LTS or earlier, Centos7, Ubuntu Server 14.04LTS, ArchLinux (32/64)\n");
    printf("-OpenVMS : OpenVMS Alpha v8.4, OpenVMS VAX v7.3, OpenVMS IA64 v8.4\n");
    printf("\n");
    printf("%sPIATTAFORME ATTUALMENTE TESTATE%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("-Windows 10 (64) \n");
    printf("-OSX 10.13 (64) \n");
    printf("-Ubuntu Server 16.04 \n");
    printf("-OpenVMS Alpha v8.4 (REQUIRED GNV-PACKAGE - DOWNLOAD FROM http://h41379.www4.hpe.com/openvms/freeware/index.html)\n");
    printf("\n");
    printf("%sREQUISITI RICHIESTI%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("    Windows\n");
    printf("        -CPU : x86 con 1ghz o superiore\n");
    printf("        -RAM : 1GB o superiore\n");
    printf("        -GPU : supporto per OpenCL\n");
    printf("        -Connessione internet : Richiesta solo per aggiornare il prodotto\n");
    printf("    Linux/RHL\n");
    printf("        -CPU : x86 con 1ghz o superiore\n");
    printf("        -RAM : 128MB o superiore\n");
    printf("        -GPU : supporto per OpenCL\n");
    printf("        -Connessione internet : Richiesta solo per aggiornare il prodotto\n");
    printf("    OSX\n");
    printf("        -OS  : 10.6 o superiore a 64 bit");
    printf("        -CPU : Intel x64 con 1ghz o superiore\n");
    printf("        -RAM : 4GB o superiore\n");
    printf("        -GPU : supporto per OpenCL\n");
    printf("        -Connessione internet : Richiesta solo per aggiornare il prodotto\n");
    printf("    OpenVMS\n");
    printf("        -OS  : VAX 7.3 - Alpha 8.4 - IA64 8.4\n");
    printf("        -CPU : DECAlpha AXP 666mhz - VAX CPU 333mhz - Intel Itanium 733mhz\n");
    printf("        -RAM : 32MB\n");
    printf("        -Connessione internet : Richiesta solo per aggiornare il prodotto\n");
    printf("        -License richieste : TCP/IP - HP C - GNV\n");
    printf("\n");
    printf("%sCOMPILA UNA NUOVA VERSIONE%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("    Windows\n");
    printf("        -Esegui il file compiler.bat\n");
    printf("        -Segui le istruzioni a schermo\n");
    printf("        -Enjoy !\n");
    printf("    Linux / RHL / OSX\n");
    printf("        -Esegui il file compiler-linux.sh");
    printf("        -Segui le istruzioni a schermo\n");
    printf("        -Enjoy !\n");
    printf("    OpenVMS for Alpha\n");
    printf("        -Scarica il file zip dal sito di github o clona il repository (GIT REQUIRED AND TCP$IP PRODUCT INSTALLED)\n");
    printf("        -Scompatta il file zip con il comando UNZIP :== $dka100:[sys0]UNZIP.EXE Halma.ZIP\n");
    printf("        -Recati nella cartella estratta con SET DEFAULT [.Halma]\n");
    printf("        -Compila il sorgente con il comando CC/LIST MAIN.C, [.src]GAMEENGINE.C, [.src]WIN_UTILS.C /INCLUDE [.include]GAMEENGINE.h, [.include]UTILS.H\n");
    printf("        -Compila i file OBJ con il comando LINK MAIN.OBJ\n");
    printf("        -Esegui con RUN HALMA.EXE\n");
    printf("        -Enjoy !\n");
    printf("        *Se vuoi rendere globale l'utilizzo del gioco a tutti gli utenti, sposta il file exe nella cartella $dka100:[sys0] e imposta l'alias HALMA :== $DKA100:[sys0]HALMA:EXE. Puoi anche impostare i permessi con SET PROC/ALL HALMA.EXE\n");
    printf("        **VAX/IA64 la procedura di compilazione e' equivalente con delle accortezze, ovvero sostituire i dischi con DUA100\n");
    printf("\nGrazie per aver provato Halma-Cli ! Il videogioco open-source che non ha bisogno di troppe risorse per divertire ;)\n");
    printf("\n%sCOMMENTI DEGLI UTENTI CHE LO HANNO PROVATO%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    printf("%s-%s Utile per rilassarsi dopo il lavoro (Andrea Gargiulo on Centos7)\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("%s-%s Un buon prodotto per chi non ha esigenze particolari (Kevin Tafuro on OpenVMS)\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("%sTECNOLOGIE IMPIEGATE%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    printf("Solo ANSI C, nient'altro ! Garantendo efficenza su macchine con risorse ridotte e facilita' di installazione\n\n");
    printf("%sSVILUPPATORI\n%s", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    printf("%s-%s Mauro Cipriani \n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("%s-%s Paolo Laddomada \n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("\n%sLICENZE%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    printf("%s-%s Il software gode di licenza GPL (General Public License)\n ", ANSI_COLOR_RED, ANSI_COLOR_RESET);
}

void checkScore() {

    int i = 0,
        j = 0,
        score1 = 0,
        score2 = 0,
        pedineRimosse1 = 0,
        pedineRimosse2 = 0,
        pedineRimaste1 = 0,
        pedineRimaste2 = 0,
        pedineZonaAvversario1 = 0,
        pedineZonaAvversario2 = 0;


    for (i = 0; i < ROWS; i++) {

        for (j = 0; j < COLUMNS; j++) {

            // Giocatore 1 ha rimosso tutte le pedine nella zona di partenza, questo incrementa il punteggio
            if ( i == 0 && j < 4 && halmaBoard[i][j] != playerIcon1 ) { pedineRimosse1++; score1++; } 
            else if ( i == 1 && j < 3 && halmaBoard[i][j] != playerIcon1 ) { pedineRimosse1++; score1++; } 
            else if ( i == 2 && j < 2 && halmaBoard[i][j] != playerIcon1) { pedineRimosse1++; score1++; } 
            else if ( i == 3 && j < 1 && halmaBoard[i][j] != playerIcon1 ) { pedineRimosse1++; score1++; }

            // Giocatore 2 ha rimosso tutte le pedine nella zona di partenza, questo incrementa il punteggio
            if(i == 7 && j > 3 && halmaBoard[i][j] != playerIcon2) { pedineRimosse2++; score2++; }
            else if(i == 6 && j > 4 && halmaBoard[i][j] != playerIcon2) { pedineRimosse2++; score2++; }
            else if(i == 5 && j > 5 && halmaBoard[i][j] != playerIcon2) { pedineRimosse2++; score2++; }
            else if(i == 4 && j > 6 && halmaBoard[i][j] != playerIcon2) { pedineRimosse2++; score2++; }
            
            // Il giocatore 1 ha ancora pedine nel punto di partenza, questo decrementa il punteggio
            if ( i == 0 && j < 4 && halmaBoard[i][j] == playerIcon1 ) { pedineRimaste1++; score1--; } 
            else if ( i == 1 && j < 3 && halmaBoard[i][j] == playerIcon1 ) { pedineRimaste1++; score1--; } 
            else if ( i == 2 && j < 2 && halmaBoard[i][j] == playerIcon1) { pedineRimaste1++; score1--; } 
            else if ( i == 3 && j < 1 && halmaBoard[i][j] == playerIcon1 ) { pedineRimaste1++; score1--; }

            // Il giocatore 2 ha ancora pedine nel punto di partenza, questo decrementa il punteggio
            if(i == 7 && j > 3 && halmaBoard[i][j] == playerIcon2) { pedineRimaste2++; score2--; }
            else if(i == 6 && j > 4 && halmaBoard[i][j] == playerIcon2) { pedineRimaste2++; score2--; }
            else if(i == 5 && j > 5 && halmaBoard[i][j] == playerIcon2) { pedineRimaste2++; score2--; }
            else if(i == 4 && j > 6 && halmaBoard[i][j] == playerIcon2) { pedineRimaste2++; score2--; }

            // Il giocatore 1 ha mosso le pedine nella zona di partenza dell'avversario, questo incrementa il punteggio
            if(i == 7 && j > 3 && halmaBoard[i][j] == playerIcon1) { pedineZonaAvversario1++; score1++; }
            else if(i == 6 && j > 4 && halmaBoard[i][j] == playerIcon1) { pedineZonaAvversario1++; score1++; }
            else if(i == 5 && j > 5 && halmaBoard[i][j] == playerIcon1) { pedineZonaAvversario1++; score1++; }
            else if(i == 4 && j > 6 && halmaBoard[i][j] == playerIcon1) { pedineZonaAvversario1++; score1++; }

            // Il giocatore 2 ha mosso le pedine nella zona di partenza dell'avversario, questo incrementa il punteggio
            if ( i == 0 && j < 4 && halmaBoard[i][j] == playerIcon2 ) { pedineZonaAvversario2++; score2++; } 
            else if ( i == 1 && j < 3 && halmaBoard[i][j] == playerIcon2 ) { pedineZonaAvversario2++; score2++; } 
            else if ( i == 2 && j < 2 && halmaBoard[i][j] == playerIcon2 ) { pedineZonaAvversario2++; score2++; } 
            else if ( i == 3 && j < 1 && halmaBoard[i][j] == playerIcon2 ) { pedineZonaAvversario2++; score2++; }
        }

    }

    printf("\n======PUNTEGGIO TOTALE======\n");
    printf("Giocatore %s1%s : %d", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, score1);
    printf("\nGiocatore %s2%s : %d", ANSI_COLOR_RED, ANSI_COLOR_RESET, score2);

    printf("\n\n======PUNTEGGIO DETTAGLIATO======\n");
    printf("Pedine giocatore 1 rimosse dalla zona di partenza : %s+%d%s", ANSI_COLOR_BLUE, pedineRimosse1, ANSI_COLOR_RESET);
    printf("\nPedine giocatore 2 rimosse dalla zona di partenza : %s+%d%s", ANSI_COLOR_RED, pedineRimosse2, ANSI_COLOR_RESET);
    printf("\nPedine giocatore 1 non mosse : %s-%d%s", ANSI_COLOR_BLUE, pedineRimaste1, ANSI_COLOR_RESET);
    printf("\nPedine giocatore 2 non mosse : %s-%d%s", ANSI_COLOR_RED, pedineRimaste2, ANSI_COLOR_RESET);
    printf("\nPedine giocatore 1 in zona avversaria : %s+%d%s", ANSI_COLOR_BLUE, pedineZonaAvversario1, ANSI_COLOR_RESET);
    printf("\nPedine giocatore 2 in zona avversaria : %s+%d%s", ANSI_COLOR_RED, pedineZonaAvversario2, ANSI_COLOR_RESET);

    if (score1 > score2) {
        printf("\n\nVince il giocatore 1 ! \n");
    } else if (score2 > score1) {
        printf("\n\nVince il giocatore 2 ! \n");
    } else 
        printf("\n\nPareggio ! \n");

}

bool checkEndGame() {

    if (mosse <= 0) 
        return true;
     else 
        return false;

}