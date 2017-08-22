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
#endif

#ifdef _WIN32
    #include "./include/utils.h"
#endif

#ifdef __APPLE__
    #include "./include/utils.h"
#endif

#include "./include/gameEngine.h"

int main(int argc, char const *argv[]){

    int scelta;

    char icon1 = '*',
         icon2 = '+';

    do {
      screenClear();

      printf("======================\n");
      printf("%%  Halma-Cli V0.2  %%\n");
      printf("======================\n");
      printf("\n");
      printf("1) Inizia il gioco \n");
      printf("2) Personalizza icone giocatore\n");
      printf("0) Chiudi l'applicazione\n");
      printf("\n");

      do {
        printf("$ ");
        scanf("%d", &scelta);

        if (scelta < 0 || scelta > 2) {
          errorHandler(1);
        }
      } while((scelta < 0 || scelta > 2));

        switch(scelta) {

        case 1 : {
            while(isPlaing){
                int x,
                    y;

                screenClear();
                printf("=====================\n");
                printf("Giocatore 1 (%c) : %d \n", icon1, score1);
                printf("Giocatore 2 (%c) : %d \n", icon2, score2);
                printf("Mosse rimanenti : %d \n", mosse);
                printf("=====================\n");
                initializeBoard(icon1, icon2);
                printMatrix();
                printf("\n");
                printf("Giocatore 1 \n");
                printf("Quale pedina vuoi muovere ? (x,y) \n");
                scanf("%i %i", &x, &y);
                consolePause();
            }

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
            printf("Icone impostate correttamente !\n");

            break;
        }

      }

    } while (scelta != 0);

    printf("Halma exiting ...\n");
    consolePause();

    return 0;
}