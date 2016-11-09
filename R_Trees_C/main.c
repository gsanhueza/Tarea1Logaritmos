#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "rectangle.h"

int main(int argc, char **argv) {

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

    int i = atoi(argv[1]);

    int numRectangles = (int) pow(2, i);
    printf("\nTesting %d (2^%d) rectangles...\n\n", numRectangles, i);

    Rectangle **rectLinear = bateriaRectangulos(numRectangles);
    Rectangle **rectGreene = copy(rectLinear, numRectangles);
    Rectangle **busqueda = bateriaRectangulos(numRectangles / 10);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    time_spent = (finish.tv_sec - start.tv_sec);
    time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("time in create Rects: %f\n", time_spent);

    Node *headerLinear = createNode();
    Node *headerGreene = createNode();

    char *nodeLinear;
    char *nodeGreene;

    Rectangle *r = createRectangle(0, 0, 4, 5, -1);
    Rectangle *r2 = createRectangle(0, 0, 4, 5, -1);

    headerLinear->rectArray[0] = r;
    headerLinear->occupied = 1;
    headerLinear->this_node_filename = "Nodes/HeaderLinear.txt";
    headerGreene->rectArray[0] = r2;
    headerGreene->occupied = 1;
    headerGreene->this_node_filename = "Nodes/HeaderGreene.txt";


    nodeLinear = writeToDisk(headerLinear);
    nodeGreene = writeToDisk(headerGreene);

    /* Insert Linear */
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i < numRectangles; i++) {
        insertToRootLinear(nodeLinear, rectLinear[i]);
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    time_spent = (finish.tv_sec - start.tv_sec);
    time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("time in Insert Linear: %f\n", time_spent);

    /* Search Linear */
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < numRectangles / 10; i++){
        /*Node *LinearSearch = */search(nodeLinear, busqueda[i]);
    }

    clock_gettime(CLOCK_MONOTONIC, &finish);
    time_spent = (finish.tv_sec - start.tv_sec);
    time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("time in Search Linear: %f\n", time_spent);

    /* Cleaning */
    system("rm Nodes/ -rf");
    system("mkdir Nodes");
    nodeLinear = writeToDisk(headerLinear);
    nodeGreene = writeToDisk(headerGreene);

    /* Insert Greene */
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i < numRectangles; i++) {
        insertToRootGreene(nodeGreene,rectGreene[i]);
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    time_spent = (finish.tv_sec - start.tv_sec);
    time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("\ntime in Insert Greene: %f\n", time_spent);

    /* Search Greene */
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < numRectangles / 10; i++){
        /*Node *LinearSearch = */search(nodeGreene, busqueda[i]);
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    time_spent = (finish.tv_sec - start.tv_sec);
    time_spent += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("time in Search Greene: %f\n", time_spent);

    /* Cleaning */
    system("rm Nodes/ -rf");
    system("mkdir Nodes");
    nodeLinear = writeToDisk(headerLinear);
    nodeGreene = writeToDisk(headerGreene);
}
