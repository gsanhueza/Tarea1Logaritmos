#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    srand(123); /* Inicializa el random, si no se cambia el parametro lanzara siempre la misma secuencia */

    int numRectangles = 2000; // 262144
    Rectangle **rects = bateriaRectangulos(numRectangles);

    Node *header = createNode();
    Rectangle *r = createRectangle(0, 0, 4, 5, -1);
    header->rectArray[0] = r;
    header->occupied = 1;
    header->this_node_filename = "Nodes/Node0.bin"; // WHAT

    char *node = writeToDisk(header);

    for(int i = 0; i < numRectangles; i++) {
         insertToRoot(node, rects[i]);
//         TODO usar insertToRoot() para chequear overflow del header
    }

}
