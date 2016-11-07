#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    srand(123);/*Inicializa el random, si no se cambia el parametro lanzara siempre la misma secuencia*/

    Node *header = createTestRectangles(50);
    char *node = writeToDisk(header);
    Rectangle *r = createRectangle(0,0,4,5,-1);

    Node *searched;
    insert(node,r);
    /*if (header->size==M){
        Node *new_father = createNode();
        new_father->rectArray = linearSplit(header);
        node = writeToDisk(new_father);
    }*/
    searched = search(node, r);

}
