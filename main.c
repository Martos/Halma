/*

          _____                    _____                    _____            _____                    _____          
         /\    \                  /\    \                  /\    \          /\    \                  /\    \         
        /::\____\                /::\    \                /::\____\        /::\____\                /::\    \        
       /:::/    /               /::::\    \              /:::/    /       /::::|   |               /::::\    \       
      /:::/    /               /::::::\    \            /:::/    /       /:::::|   |              /::::::\    \      
     /:::/    /               /:::/\:::\    \          /:::/    /       /::::::|   |             /:::/\:::\    \     
    /:::/____/               /:::/__\:::\    \        /:::/    /       /:::/|::|   |            /:::/__\:::\    \    
   /::::\    \              /::::\   \:::\    \      /:::/    /       /:::/ |::|   |           /::::\   \:::\    \   
  /::::::\    \   _____    /::::::\   \:::\    \    /:::/    /       /:::/  |::|___|______    /::::::\   \:::\    \  
 /:::/\:::\    \ /\    \  /:::/\:::\   \:::\    \  /:::/    /       /:::/   |::::::::\    \  /:::/\:::\   \:::\    \ 
/:::/  \:::\    /::\____\/:::/  \:::\   \:::\____\/:::/____/       /:::/    |:::::::::\____\/:::/  \:::\   \:::\____\
\::/    \:::\  /:::/    /\::/    \:::\  /:::/    /\:::\    \       \::/    / ~~~~~/:::/    /\::/    \:::\  /:::/    /
 \/____/ \:::\/:::/    /  \/____/ \:::\/:::/    /  \:::\    \       \/____/      /:::/    /  \/____/ \:::\/:::/    / 
          \::::::/    /            \::::::/    /    \:::\    \                  /:::/    /            \::::::/    /  
           \::::/    /              \::::/    /      \:::\    \                /:::/    /              \::::/    /   
           /:::/    /               /:::/    /        \:::\    \              /:::/    /               /:::/    /    
          /:::/    /               /:::/    /          \:::\    \            /:::/    /               /:::/    /     
         /:::/    /               /:::/    /            \:::\    \          /:::/    /               /:::/    /      
        /:::/    /               /:::/    /              \:::\____\        /:::/    /               /:::/    /       
        \::/    /                \::/    /                \::/    /        \::/    /                \::/    /        
         \/____/                  \/____/                  \/____/          \/____/                  \/____/         
                                                                                                                     

Author 			: Mauro Cipriani - Paolo Laddomada - Ivonne Ciocia
Corso 			: ITPS [A-L]
Nome progetto	: Halma
Git             : https://github.com/Martos/Halma.git
Branch          : master
WebSite         : www.galaxyserver.ovh/consoleHalma

*/
#include <stdio.h>
#include <stdlib.h>

#ifdef linux
    #include "./include/utils.h"
    #include "./src/linux_utils.c"
#endif

#ifdef _WIN32
    #include "./include/utils.h"
    #include "./src/win_utils.c"
#endif

#ifdef __APPLE__
    #include "./include/utils.h"
    #include "./src/osx_utils.c"
#endif

#ifdef __alpha
    #include "./include/utils.h"
    #include "./src/win_utils.c"
#endif

#include "./include/gameEngine.h"

int main(int argc, char const *argv[]){

    int scelta;

    char icon1 = '*',
         icon2 = '+';

    setIcon(icon1, icon2);

    do {
      screenClear();

      printf("%s=====================%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
      printf("%%  Halma-Cli V0.2  %%\n");
      printf("%s=====================%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
      printf("\n");
      printf("1) Inizia il gioco \n");
      printf("2) Personalizza icone giocatore \n");
      printf("3) Guida al gioco \n");
      printf("4) Informazioni \n");
      printf("0) Chiudi l'applicazione \n");
      printf("\n");

      do {
        printf("$ ");
        scanf("%d", &scelta);

        if (scelta < 0 || scelta > 4) {
          errorHandler(1);
        }
      } while((scelta < 0 || scelta > 4));

        switch(scelta) {

        case 1 : {
            initializeBoard(playerIcon1, playerIcon2);
            while(isPlaing && mosse >= 0){
                // Coordinate per lo spostamento della pedina
                int destX = 0,
                    destY = 0,
                    holdX = 0,
                    holdY = 0;

                bool validMove;

                do {
                    screenClear();
                    scoreBoard();
                    printMatrix();
                    printf("\n");
                    printf("Giocatore 1 \n");
                    printf("Quale pedina vuoi muovere ? (x y) \n");
                    scanf("%i %i", &holdY, &holdX);
                    printf("Dove la vuoi posizionare ? (x y) \n");
                    scanf("%i %i", &destY, &destX);
                    validMove = move(holdX, holdY, destX, destY, icon1);
                } while (validMove == false);

                do {
                    screenClear();
                    scoreBoard();
                    printMatrix();
                    printf("\n");
                    printf("Giocatore 2 \n");
                    printf("Quale pedina vuoi muovere ? (x y) \n");
                    scanf("%i %i", &holdY, &holdX);
                    printf("Dove la vuoi posizionare ? (x y) \n");
                    scanf("%i %i", &destY, &destX);
                    validMove = move(holdX, holdY, destX, destY, icon2);
                } while (validMove == false);
                //consolePause();
                mosse--;
            }
            printf("\nPartita conclusa !\n");
            consolePause();
            break;
        }

        case 2 : {
            screenClear();
            printf("Inserisci il carattere da usare per il giocatore1 : ");
            scanf(" %c",&icon1);
            getchar();
            printf("\nInserisci il carattere da usare per il giocatore2 : ");
            scanf(" %c",&icon2);
            getchar();
            printf("\nGiocatore1 : %c - Giocatore2: %c \n", icon1, icon2);
            setIcon(icon1, icon2);
            printf("Icone impostate correttamente !\n");
            consolePause();
            break;
        }

        case 3 : {
            screenClear();
            gameGuide();
            consolePause();
            break;
        }

        case 4 : {
            screenClear();
            printf("HALMA-CLI V0.4");
            printf("\n");
            printf("Videogioco OpenSource realizzato da Mauro Cipriani, Paolo Laddomada, Ivone Ciocia\n");
            printf("Visita la pagina web di github per maggiori informazioni !\n");
            printf("\n");
            printf("PIATTAFORME SUPPORTATE\n");
            printf("-Windows : XPSP3, 7, 8.1, 10 (32/64)\n");
            printf("-OSX : 10.6 or earlier (64)\n");
            printf("-Linux : Ubuntu 14.04LTS or earlier, Centos7, Ubuntu Server 14.04LTS, ArchLinux (32/64)\n");
            printf("-OpenVMS : OpenVMS Alpha v8.4, OpenVMS VAX v7.3, OpenVMS IA64 v8.4\n");
            printf("\n");
            printf("PIATTAFORME ATTUALMENTE TESTATE\n");
            printf("-Windows 10 (64) \n");
            printf("-OSX 10.13 (64) \n");
            printf("-Ubuntu Server 16.04 \n");
            printf("-OpenVMS Alpha v8.4 (REQUIRED GNV-PACKAGE - DOWNLOAD FROM http://h41379.www4.hpe.com/openvms/freeware/index.html)\n");
            printf("\n");
            printf("REQUISITI RICHIESTI\n");
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
            printf("COMPILA UNA NUOVA VERSIONE\n");
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
            consolePause();
            break;
        }

      }

    } while (scelta != 0);

    printf("Halma exiting ...\n");
    consolePause();

    return 0;
}