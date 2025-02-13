/* Ariasu Florian-Andrei - 325CB */

#ifndef QUEUE
#define QUEUE

#include <stdio.h>

typedef struct QCell2 {
    char *command;
    struct QCell2 *next;
    struct QCell2 *prev;
} TQCell2, *TQL2;

typedef struct Queue {
    TQL2 first;
    TQL2 last;
} TQueue;

TQueue *InitQ ();
void IntrQ (TQueue *q, char *command);
char *ExtrQ (TQueue *q);
void printQueue (TQueue *q);
void DistrQ (TQueue **q);
TQueue *SWITCH (TQueue *q);

#endif