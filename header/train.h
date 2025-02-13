/* Ariasu Florian-Andrei - 325CB */

#ifndef TRAIN
#define TRAIN

#include <stdio.h>

typedef struct TrCell2 {
    char data;
    struct TrCell2 *next;
    struct TrCell2 *prev;
} TRCell2, *TRL2;

typedef struct Train {
    TRL2 head;
    TRL2 mechanic;
} *TTrain;

TTrain InitTrain();

TRL2 AllocateCell2();
void INSERT_LEFT (FILE *fpOutput, TTrain train, char c);
void INSERT_RIGHT (TTrain train, char c);
void MOVE_LEFT (TTrain train);
void MOVE_RIGHT (TTrain train);
void SEARCH (FILE *fpOutput, TTrain train, char *string);
void SEARCH_LEFT (FILE *fpOutput, TTrain train, char *string);
void SEARCH_RIGHT (FILE *fpOutput, TTrain train, char *string);

void WRITE (TTrain train, char c);
void SHOW_CURRENT (FILE *fpOutput, TTrain train);
void SHOW (FILE *fpOutput, TTrain train);
void CLEAR_CELL (TTrain train);
void CLEAR_ALL (TTrain train);

#endif