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

#ifdef __linux__ 
        #include "./src/gameEngines.h"
    #elif _WIN32
        #include "./src/gameEngines.h"
        #include "./src/win_utils.h"
    #elif __APPLE__
        #include "./src/gameEngines.h"
        #include "./src/osx_utils.h"
#endif

int main(int argc, char const *argv[]){

    initializeBoard('*', '+');
    printMatrix();

    return 0;
}
