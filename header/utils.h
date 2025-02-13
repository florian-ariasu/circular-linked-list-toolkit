/* Ariasu Florian-Andrei - 325CB */

#ifndef UTILS
#define UTILS

#include <stdio.h>
#include "train.h"
#include "queue.h"
#define MAX_COMMAND_SIZE 30

char *findWord (char *str);
void ReadCommand (FILE *fpInput, FILE *fpOutput, TTrain myTrain, TQueue *q);
void EXECUTE (FILE *fpOutput, TTrain myTrain, TQueue *q);

#endif