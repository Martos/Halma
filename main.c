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
                                                                                                                     

Author 			: Mauro Cipriani - Paolo Laddomada
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

    #define PLATFORM "Linux"
#endif

#ifdef _WIN32
    #include "./include/utils.h"
    #include "./src/win_utils.c"

    #define PLATFORM "Windows"
#endif

#ifdef __APPLE__
    #include "./include/utils.h"
    #include "./src/osx_utils.c"

    #define PLATFORM "OSX"
#endif

#ifdef __alpha
    #include "./include/utils.h"
    #include "./src/win_utils.c"

    #define PLATFORM "OpenVMS"
#endif

#include "./include/gameEngine.h"

int main(int argc, char const *argv[]){

    int scelta;

    char icon1 = '*',
         icon2 = '+';

    setIcon(icon1, icon2);

    do {
      screenClear();

      printf("%s====================%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
      printf("%%  %sHalma-Cli V%s%s  %%\n", ANSI_COLOR_YELLOW, PRODUCT_VERSION, ANSI_COLOR_RESET);
      printf("    %s Version       \n", PLATFORM);
      printf("%s====================%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
      printf("\n");
      printf("%s1%s) Inizia il gioco \n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
      printf("%s2%s) Personalizza icone giocatore \n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
      printf("%s3%s) Guida al gioco \n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
      printf("%s4%s) Informazioni \n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
      printf("%s0%s) Chiudi l'applicazione \n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
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
            bool validMove = false;
            bool endGame = false;

            int score1 = 0,
                score2 = 0;

            initializeBoard(playerIcon1, playerIcon2);

            do {
                // Coordinate per lo spostamento della pedina
                int destX = 0,
                    destY = 0,
                    holdX = 0,
                    holdY = 0;

                do {
                    endGame = checkEndGame();
                    screenClear();
                    scoreBoard();
                    printMatrix();
                    printf("\n");
                    printf("Giocatore 1 (%s%c%s)\n", ANSI_COLOR_BLUE, playerIcon1, ANSI_COLOR_RESET);
                    printf("Quale pedina vuoi muovere ? (x y) \n");
                    scanf("%i %i", &holdY, &holdX);
                    printf("Dove la vuoi posizionare ? (x y) \n");
                    scanf("%i %i", &destY, &destX);
                    validMove = move(holdX, holdY, destX, destY, icon1);
                } while(!validMove);

                do {
                    endGame = checkEndGame();
                    screenClear();
                    scoreBoard();
                    printMatrix();
                    printf("\n");
                    printf("Giocatore 2 (%s%c%s)\n",ANSI_COLOR_RED, playerIcon2, ANSI_COLOR_RESET);
                    printf("Quale pedina vuoi muovere ? (x y) \n");
                    scanf("%i %i", &holdY, &holdX);
                    printf("Dove la vuoi posizionare ? (x y) \n");
                    scanf("%i %i", &destY, &destX);
                    validMove = move(holdX, holdY, destX, destY, icon2);
                } while(!validMove);

            } while (!endGame);
            screenClear();
            scoreBoard();
            printMatrix();
            printf("\n\nPartita conclusa !\n");
            consolePause();
            screenClear();
            checkScore();
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
            info();
            consolePause();
            break;
        }

      }

    } while (scelta != 0);

    printf("Halma exiting ...\n");
    consolePause();

    return 0;
}