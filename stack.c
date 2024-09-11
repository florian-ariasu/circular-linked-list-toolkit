/* Ariasu Florian-Andrei - 325CB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/* 
    Aici am implementat functiile necesare pentru operatia switch, alegand sa folosesc o stiva 
*/

TStack InitS () {
    TStack s = (TStack) malloc(sizeof(TStack));

    if (s == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }

    s->next = NULL;

    return s;
}

void Push (TStack s, char *command) {
    TStack temp = (TStack) malloc(sizeof(TCellStack));

    if (temp == NULL) {
        printf("Error: malloc failed\n");
        free(temp);
        return;
    }

    temp->data = (char *) malloc(strlen(command) + 1);

    if (temp->data == NULL) {
        printf("Error: malloc failed\n");
        free(temp->data);
        free(temp);
       return;
    }

    strcpy(temp->data, command);
    temp->next = s->next;
    s->next = temp;
}

char *Pop (TStack s) {
    if (s->next == NULL) {
        printf("Error: stack is empty\n");
        return 0;
    }

    TStack temp = s->next;
    char *command = (char *) malloc(strlen(s->next->data) + 1);
    strcpy(command, temp->data);

    s->next = s->next->next;
    free(temp->data);
    free(temp);

    return command;
}
