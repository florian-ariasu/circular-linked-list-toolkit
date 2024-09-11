/* Ariasu Florian-Andrei - 325CB */

#ifndef STACK
#define STACK

#include <stdio.h>

typedef struct CellStack {
    char *data;
    struct CellStack *next;
} TCellStack, *TStack;

TStack InitS ();
void Push (TStack s, char *command);
char *Pop (TStack s);

#endif