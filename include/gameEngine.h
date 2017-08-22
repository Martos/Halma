#include <stdio.h>
#include <stdbool.h>

//Proprieta' del campo da gioco
#define ROWS 16
#define COLUMNS 16

//Mosse massime possibili
#define MAX_MOVE 25

//Area di gioco
static char halmaBoard[ROWS][COLUMNS] = {' '};

//Flag per indicare se il giocatore è ancora in gioco
static bool isPlaing = true;

//Punteggi giocatori
static int score1 = 0,
           score2 = 0;

//Icone giocatori standard
char playerIcon1;
char playerIcon2;

//Error catcher
void errorHandler(int code);

//Preparazione area di gioco iniziale
void initializeBoard(char playerIcon1, char playerIcon2);

//stampa il terreno del gioco
void printMatrix();

//Sposta la pedina
void move();