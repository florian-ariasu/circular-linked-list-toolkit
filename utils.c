/* Ariasu Florian-Andrei - 325CB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "queue.h"

/*
    Aici am implementat functia care imi va citi comenzile din fisierul de input si o functie
    care extrage cuvantul pentru SEARCH, SEARCH_LEFT si SEARCH_RIGHT.
*/

char *findWord (char *str) {
    char *word = (char *) malloc(MAX_COMMAND_SIZE * sizeof(char));
    char *ptr = strtok(str, " ");
    ptr = strtok(NULL, " ");
    strcpy(word, ptr);
    return word;
}

void ReadCommand (FILE *fpInput, FILE *fpOutput, TTrain myTrain, TQueue *q) {
    int numOfCommands;
    char *command = (char *) malloc(MAX_COMMAND_SIZE * sizeof(char));

    if (command == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }

    fscanf(fpInput, "%d", &numOfCommands); 
    fgets(command, 30, fpInput);

    while (fgets(command, 30, fpInput) != NULL) {
        if (strcmp(command, "MOVE_LEFT\n") == 0) {
            IntrQ(q, command);
        } else if (strcmp(command, "MOVE_RIGHT\n") == 0) {
            IntrQ(q, command);
        } else if (command[0] == 'W') {
            IntrQ(q, command);
        } else if (strcmp(command, "CLEAR_CELL\n") == 0) {
            IntrQ(q, command);
        } else if (strcmp(command, "CLEAR_ALL\n") == 0) {
            IntrQ(q, command);
        } else if (command[0] == 'I' && command[7] == 'L') {
            IntrQ(q, command);
        } else if (command[0] == 'I' && command[7] == 'R') {
            IntrQ(q, command);
        } else if (command[5] == 'H' && command[6] == ' ') {
            IntrQ(q, command);
        } else if (command[5] == 'H' && command[7] == 'L') {
            IntrQ(q, command);
        } else if (command[5] == 'H' && command[7] == 'R') {
            IntrQ(q, command);
        } else if (strcmp(command, "SHOW_CURRENT\n") == 0) {
            SHOW_CURRENT(fpOutput, myTrain);
        } else if (strcmp(command, "SHOW\n") == 0) {
            SHOW(fpOutput, myTrain);
        } else if (strcmp(command, "SWITCH\n") == 0) {
            SWITCH(q);
        } else if (strcmp(command, "EXECUTE\n") == 0) {
            EXECUTE(fpOutput, myTrain, q);
        }
    }
    
    free(command);
}
