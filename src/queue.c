/* Ariasu Florian-Andrei - 325CB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"
#include "utils.h"

/* 
    Aici am implementat functiile care ma ajuta atat sa adaug comenzile citite din fisier
    in coada, cat si sa implementez operatia SWITCH, folosindu-ma de o stiva si de o coada.
    Tot aici am implementat si functia care imi executa comenzile din coada.
*/

TQueue *InitQ () {
    TQueue *q = (TQueue *) malloc(sizeof(TQueue));

    if (q == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }
    q->first = NULL;
    q->last = NULL;

    return q;
} 

void IntrQ (TQueue *q, char *command) {
    TQL2 temp = (TQL2) malloc(sizeof(TQCell2));

    if (temp == NULL) {
        printf("Error: malloc failed\n");
        free(temp);
        return;
    }

    temp->command = (char *) malloc(strlen(command) + 1);

    if (temp->command == NULL) {
        printf("Error: malloc failed\n");
        free(temp->command);
        free(temp);
        return;
    }

    strcpy(temp->command, command);
    temp->next = NULL;

    if (q->first == NULL) {
        q->first = temp;
    } else {
        q->last->next = temp;
        temp->prev = q->last;
    }

    q->last = temp;
}

char *ExtrQ (TQueue *q) {
    if (q->first == NULL) {
        printf("Error: queue is empty\n");
        return 0;
    }

    TQL2 temp = q->first;
    char *command = (char *) malloc(strlen(temp->command) + 1);
    strcpy(command, temp->command);

    if (q->first == q->last) {
        q->first = NULL;
        q->last = NULL;
    } else {
        q->first = q->first->next;
        q->first->prev = NULL;
    }

    free(temp);

    return command;
}

TQueue *SWITCH (TQueue *q) {
    TStack s = InitS();

    while (q->first != NULL) {
        Push(s, ExtrQ(q));
    }

    q->first = NULL;
    q->last = NULL;

    while (s->next != NULL) {
        IntrQ(q, Pop(s));
    }

    free(s);

    return q;
}

void EXECUTE (FILE *fpOutput, TTrain myTrain, TQueue *q) {
    char *command = (char *) malloc(MAX_COMMAND_SIZE * sizeof(char));

    if (command == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }

    if (q->first != NULL) {
        strcpy(command, ExtrQ(q));

        if (strcmp(command, "MOVE_LEFT\n") == 0) {
            MOVE_LEFT(myTrain);
        } else if (strcmp(command, "MOVE_RIGHT\n") == 0) {
            MOVE_RIGHT(myTrain);
        } else if (command[0] == 'W') {
            WRITE(myTrain, command[6]);
        } else if (strcmp(command, "CLEAR_CELL\n") == 0) {
            CLEAR_CELL(myTrain);
        } else if (strcmp(command, "CLEAR_ALL\n") == 0) {
            CLEAR_ALL(myTrain);
        } else if (command[0] == 'I' && command[7] == 'L') {
            INSERT_LEFT(fpOutput, myTrain, command[12]);
        } else if (command[0] == 'I' && command[7] == 'R') {
            INSERT_RIGHT(myTrain, command[13]);
        } else if (command[5] == 'H' && command[6] == ' ') {
            char *word = findWord(command);
            SEARCH(fpOutput, myTrain, word);
        } else if (command[5] == 'H' && command[7] == 'L') {
            char *word = findWord(command);
            SEARCH_LEFT(fpOutput, myTrain, word);
        } else if (command[5] == 'H' && command[7] == 'R') {
            char *word = findWord(command);
            SEARCH_RIGHT(fpOutput, myTrain, word);
        } else {
            return;
        }
    }
}

void DistrQ (TQueue **q) {
    TQL2 temp, aux;

    if ((*q)->first == NULL) {
        return;
    }

    temp = (*q)->first;
    (*q)->first = NULL;

    while (temp != NULL) {
        aux = temp;
        temp = temp->next;
        free(aux);
    }

    free(*q);
    *q = NULL;
}
