/* Ariasu Florian-Andrei - 325CB */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "queue.h"

int main() {

    FILE *fpInput, *fpOutput;

    fpInput = fopen("tema1.in", "r");
    fpOutput = fopen("tema1.out", "w+");

    if (fpInput == NULL || fpOutput == NULL) {
        printf("Error: fopen failed\n");
        exit(1);
    }

    TTrain myTrain = InitTrain();
    TQueue *q = InitQ();

    ReadCommand(fpInput, fpOutput, myTrain, q);

    CLEAR_ALL(myTrain);
    free(myTrain->head->next);
    free(myTrain->head);
    free(myTrain);

    DistrQ(&q);

    fclose(fpInput);
    fclose(fpOutput);
    
    return 0;
}
