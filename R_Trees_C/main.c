#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "rectangle.h"

int main(void) {

    /* Si no existe directorio, crearlo */
    struct stat st = {0};

    if (stat("Nodes", &st) == -1) {
        printf("Creando carpeta Nodes...\n");
        mkdir("Nodes", 0700);
    }

    srand(123); /* Inicializa el random, si no se cambia el parametro lanzara siempre la misma secuencia */

    /* Timer */
    struct timespec start, finish;
    double time_spent;

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 9; i <= 15; i++) {
        int numRectangles = (int) pow(2, i);
        printf("\nTesting %d rectangles...\n\n", numRectangles);

        Rectangle **rectLinear = bateriaRectangulos(numRectangles);
        Rectangle **rectGreene = copy(rectLinear, numRectangles);

        clock_gettime(CLOCK_MONOTONIC, &finish);
        time_spent = (finish.tv_sec - start.tv_sec);
        time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

        printf("time in create Rects: %f\n", time_spent);

        Node *headerLinear = createNode();
        Node *headerGreene = createNode();

        Rectangle *r = createRectangle(0, 0, 4, 5, -1);
        Rectangle *r2 = createRectangle(0, 0, 4, 5, -1);

        headerLinear->rectArray[0] = r;
        headerLinear->occupied = 1;
        headerLinear->this_node_filename = "Nodes/HeaderLinear.txt";
        headerGreene->rectArray[0] = r2;
        headerGreene->occupied = 1;
        headerGreene->this_node_filename = "Nodes/HeaderGreene.txt";


        char *node = writeToDisk(headerLinear);
        char *nodeGreene = writeToDisk(headerGreene);
        clock_gettime(CLOCK_MONOTONIC, &start);
        for(int i = 0; i < numRectangles; i++) {
            insertToRootLinear(node, rectLinear[i]);
        }
        clock_gettime(CLOCK_MONOTONIC, &finish);
        time_spent = (finish.tv_sec - start.tv_sec);
        time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("time in Insert Linear: %f\n", time_spent);

        clock_gettime(CLOCK_MONOTONIC, &start);
        for(int i = 0; i < numRectangles; i++) {
            insertToRootGreene(nodeGreene,rectGreene[i]);
        }
        clock_gettime(CLOCK_MONOTONIC, &finish);
        time_spent = (finish.tv_sec - start.tv_sec);
        time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("time in Insert Greene: %f\n", time_spent);

        clock_gettime(CLOCK_MONOTONIC, &start);
        /*Node *LinearSearch = */search(node, r);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        time_spent = (finish.tv_sec - start.tv_sec);
        time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("time in Search Linear: %f\n", time_spent);

        clock_gettime(CLOCK_MONOTONIC, &start);
        /*Node *GreeneSearch = */search(nodeGreene, r2);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        time_spent = (finish.tv_sec - start.tv_sec);
        time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("time in Search Greene: %f\n", time_spent);
    }
}
