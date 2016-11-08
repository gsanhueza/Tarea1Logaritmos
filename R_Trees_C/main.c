#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void) {
    srand(123); /* Inicializa el random, si no se cambia el parametro lanzara siempre la misma secuencia */


    clock_t begin = clock();
    int numRectangles = 2000; // 262144
    Rectangle **rects = bateriaRectangulos(numRectangles);


    Rectangle **rectLinear = bateriaRectangulos(numRectangles);
    Rectangle **rectGreene = copy(rectLinear, numRectangles);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time in create Rects: %f \n ", time_spent);

    Node *headerLinear = createNode();
    Node *headerGreene = createNode();
    Rectangle *r = createRectangle(0, 0, 4, 5, -1);

    Rectangle *r2 = createRectangle(0, 0, 4, 5, -1);
    headerLinear->rectArray[0] = r;
    headerLinear->occupied = 1;
    headerLinear->this_node_filename = "Nodes/HeaderLinear.bin";
    headerGreene->rectArray[0] = r2;
    headerGreene->occupied = 1;
    headerGreene->this_node_filename = "Nodes/HeaderGreene.bin";


    char *node = writeToDisk(headerLinear);
    char *nodeGreene = writeToDisk(headerGreene);
    begin = clock();
    for(int i = 0; i < numRectangles; i++) {
        insertToRootLinear(node, rectLinear[i]);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time in Insert Linear: %f", time_spent);

    begin = clock();
    for(int i = 0; i < numRectangles; i++) {
        insertToRootGreene(nodeGreene,rectGreene[i]);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time in Insert Greene: %f", time_spent);

  /*  begin = clock();
    Node *LinearSearch = search(node,r);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time in Search Linear: %f", time_spent);

    begin = clock();
    Node *GreeneSearch = search(nodeGreene, r2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time in Search Greene: %f", time_spent);
*/


}
