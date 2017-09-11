#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "../include/utils.h"

// Proprieta' del campo da gioco
#define ROWS 8
#define COLUMNS 8

#define PRODUCT_VERSION "0.9"

// Area di gioco
static char halmaBoard[ROWS][COLUMNS] = {' '};

// Flag per indicare se il giocatore è ancora in gioco
static bool isPlaing = true;

// Punteggi giocatori
static int score1 = 0,
           score2 = 0;

// Mosse rimanenti
static int mosse = 30;

// Icone giocatori standard
char playerIcon1,
     playerIcon2;

// Error catcher
void errorHandler(int code);

// Funzione per impostare le icone giocatore
void setIcon(char icon1, char icon2);

// Preparazione area di gioco iniziale
void initializeBoard(char playerIcon1, char playerIcon2);

// Stampa il terreno del gioco
void printMatrix();

// Pannello del punteggio
void scoreBoard();

// Sposta la pedina
bool move(int holdX, int holdY, 
          int destX, int destY, 
          char giocatore);

// Funzione per la guida al gioco
void gameGuide();

// Funzione per il calcolo del punteggio
void checkScore();