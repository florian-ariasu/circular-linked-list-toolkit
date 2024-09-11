/* Ariasu Florian-Andrei - 325CB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "train.h"

/*
    Aici am implementat functiile care ma ajuta sa manipulez trenul, adica lista dublu inlantuita circulara cu santinela.
    Toate functiile de adaugat in coada, inclusiv cele care se executa direct, adica SHOW si SHOW_CURRENT, sunt prezente
    in acest fisier.
*/

TTrain InitTrain () {
    TTrain train = (TTrain) malloc(sizeof(struct Train));

    if (train == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }

    train->head = (TRL2) malloc(sizeof(TRCell2));
    train->head->next = (TRL2) malloc(sizeof(TRCell2));

    train->head->prev = NULL;
    train->head->next->next = train->head->next;
    train->head->next->prev = train->head->next; 
    train->mechanic = train->head->next;
    train->mechanic->data = '#';

    return train;
}

TRL2 AllocateCell2 () {
    TRL2 aux = (TRL2) malloc(sizeof(TRCell2));

    if (aux != NULL) {
        aux->data = '#';
        aux->prev = NULL;
        aux->next = NULL;
    } else {
        printf("Error: malloc failed\n");
        exit(1);
    }

    return aux;
}

void INSERT_LEFT (FILE *fpOutput, TTrain train, char c) {
    if (train->mechanic == train->head->next) {
        fprintf(fpOutput, "ERROR\n");
        return;
    }

    TRL2 newCell = AllocateCell2();

    if (newCell == NULL) {
        printf("Error: malloc failed\n");
    }

    newCell->data = c;
    newCell->next = train->mechanic;
    newCell->prev = train->mechanic->prev;

    train->mechanic->prev->next = newCell;
    newCell->next->prev = newCell;
    train->mechanic = newCell;
}

void INSERT_RIGHT (TTrain train, char c) {
    TRL2 newCell = AllocateCell2();

    newCell->data = c;
    newCell->next = train->mechanic->next;
    newCell->prev = train->mechanic;

    train->mechanic->next = newCell;
    newCell->next->prev = newCell;
    train->mechanic = newCell;
}

void MOVE_LEFT (TTrain train) {
    if (train->mechanic == train->head->next) {
        train->mechanic = train->head->next->prev;
        return;
    }

    train->mechanic = train->mechanic->prev;
}

void MOVE_RIGHT (TTrain train) {
    if (train->mechanic->next == train->head->next) {
        train->mechanic->next = AllocateCell2();

        train->mechanic->next->prev = train->mechanic;
        train->mechanic->next->next = train->head->next;
        train->head->next->prev = train->mechanic->next;
        train->mechanic = train->mechanic->next;
    } else {
        train->mechanic = train->mechanic->next;
    }
}

void WRITE (TTrain train, char c) {
    train->mechanic->data = c;
}

void SHOW_CURRENT (FILE *fpOutput, TTrain train) {
    fprintf(fpOutput, "%c\n", train->mechanic->data);
}

void SHOW (FILE *fpOutput, TTrain train) {
    TRL2 aux;
    int ok = 0;

    for (aux = train->head->next; aux != train->head->next || !ok; aux = aux->next) {
        ok = 1;
        if (aux == train->mechanic) {
            fprintf(fpOutput, "|%c|", aux->data);
        } else {
            fprintf(fpOutput, "%c", aux->data);
        }
    }

    fprintf(fpOutput, "\n");
}

void CLEAR_CELL (TTrain train) {

    /* Acesta este cazul in care trenul are doar vagonul 1. */

    if (train->mechanic == train->head->next) {
        train->mechanic->prev->next = train->mechanic->next;
        train->mechanic->next->prev = train->mechanic->prev;
        train->head->next = train->head->next->next;
        train->mechanic = train->mechanic->prev;
    } else {
        train->mechanic->prev->next = train->mechanic->next;
        train->mechanic->next->prev = train->mechanic->prev;
        train->mechanic = train->mechanic->prev;
    }   

    /* Pe else am cazul de baza. */
}

void CLEAR_ALL (TTrain train) {
    TRL2 aux, temp;

    for (temp = train->head->next->next; temp != train->head->next;) {
        aux = temp;
        temp = temp->next;
        free(aux);
    }

    /* Readucerea trenului la forma initiala. */

    train->head->next->next = train->head->next;
    train->head->next->prev = train->head->next; 
    train->head->next->data = '#';
    train->mechanic = train->head->next;
}

void SEARCH (FILE *fpOutput, TTrain train, char *string) {
    TRL2 tempStart = train->mechanic;
    TRL2 tempEnd;
    int match, stringLength = strlen(string);

    while (tempStart->next != train->mechanic->prev) {
        if (tempStart->data == string[0]) {
            tempEnd = tempStart;
            match = 1;

            int i;
            for (i = 0; i < stringLength - 1 && match != 0; i++) {
                if (tempEnd->data == string[i]) {
                    tempEnd = tempEnd->next;
                } else {
                    match = 0;
                }
            }

            if (match != 0) {
                train->mechanic = tempStart;
                return;
            }
        }

        tempStart = tempStart->next;
    }

    /* Cazurile pentru cuvinte de lungime 2 sau 3 le-am tratat separat */

    if (stringLength == 3) {
        if (tempStart->data == string[0] && tempStart->next->data == string[1]) {
            train->mechanic = tempStart;
            return;
        }
    } else if (stringLength == 2) {
        if (tempStart->data == string[0]) {
            train->mechanic = tempStart;
            return;
        } else if (tempStart->next->data == string[0]) {
            train->mechanic = tempStart->next;
            return;
        }
    }

    fprintf(fpOutput, "ERROR\n");
}

void SEARCH_LEFT (FILE *fpOutput, TTrain train, char *string) {
    TRL2 tempStart = train->mechanic;
    TRL2 tempEnd;
    int match, stringLength = strlen(string);

    while (tempStart->prev != train->head->next) {
        if (tempStart->data == string[0]) {
            tempEnd = tempStart;
            match = 1;

            int i;
            for (i = 0; i < stringLength - 1 && match != 0; i++) {
                if (tempEnd->data == string[i]) {
                    tempEnd = tempEnd->prev;
                } else {
                    match = 0;
                }
            }

            if (match != 0) {
                train->mechanic = tempEnd->next;
                return;
            }
        }

        tempStart = tempStart->prev;
    }

    /* Cazurile pentru cuvinte de lungime 2 sau 3 le-am tratat separat */

    if (stringLength == 3) {
        if (tempStart->data == string[0] && tempStart->prev->data == string[1]) {
            train->mechanic = tempStart->prev;
            return;
        }
    } else if (stringLength == 2) {
        if (tempStart->data == string[0]) {
            train->mechanic = tempStart->prev;
            return;
        } else if (tempStart->prev->data == string[0]) {
            train->mechanic = tempStart->prev;
            return;
        }
    }

    fprintf(fpOutput, "ERROR\n");
}

void SEARCH_RIGHT (FILE *fpOutput, TTrain train, char *string) {
    TRL2 tempStart = train->mechanic;
    TRL2 tempEnd;
    int match = 0, stringLength = strlen(string);

    while (tempStart->next != train->head->next) {
        if (tempStart->data == string[0]) {
            tempEnd = tempStart;
            match = 1;

            int i;
            for (i = 0; i < stringLength - 1 && match != 0; i++) {
                if (tempEnd->data == string[i]) {
                    tempEnd = tempEnd->next;
                } else {
                    match = 0;
                }
            }

            if (match != 0) {
                train->mechanic = tempStart->next;
                return;
            }
        }
        
        tempStart = tempStart->next;
    }

    /* Cazurile pentru cuvinte de lungime 2 sau 3 le-am tratat separat */

    if (stringLength == 3) {
        if (tempStart->data == string[0] && tempStart->next->data == string[1]) {
            train->mechanic = tempStart->next;
            return;
        }
    } else if (stringLength == 2) {
        if (tempStart->data == string[0]) {
            train->mechanic = tempStart;
            return;
        } else if (tempStart->next->data == string[0]) {
            train->mechanic = tempStart->next;
            return;
        }
    }

    fprintf(fpOutput, "ERROR\n");
}
