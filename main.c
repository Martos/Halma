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

    scelta = mainMenu();

    switch(scelta) {

        case 1 : {
            while(isPlaing){
                screenClear();
                printf("================\n");
                printf("Giocatore 1 (*) : %d \n", score1);
                printf("Giocatore 2 (+) : %d \n", score2);
                printf("================\n");
                initializeBoard(icon1, icon2);
                printMatrix();
                consolePause();
            }

            break;
        }

        case 2 : {
            screenClear();
            printf("Inserisci il carattere da usare per il giocatore1 : ");
            scanf(" %c", &icon1);
            printf("\nInserisci il carattere da usare per il giocatore2 : ");
            scanf(" %c", &icon2);
            printf("\nGiocatore1 : %c - Giocatore2: %c \n", icon1, icon2);
            printf("Icone impostate correttamente !");

            break;
        }

        default : {
            printf("Grazie per aver giocato ! \n");
            break;
        }
    }

    consolePause();

    return 0;
}