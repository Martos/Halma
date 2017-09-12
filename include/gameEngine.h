#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "../include/utils.h"

// Proprieta' del campo da gioco
#define ROWS 8
#define COLUMNS 8

#define PRODUCT_VERSION "1.0"

// Area di gioco
static char halmaBoard[ROWS][COLUMNS] = {' '};

// Flag per indicare se il giocatore è ancora in gioco
static bool isPlaing = true;

// Mosse del gioco
static int mosse;

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

// Funzione per consultare le informazioni di gioco
void info();

// Funzione per il calcolo del punteggio
void checkScore();

// Funzione per terminare la partita
bool checkEndGame();