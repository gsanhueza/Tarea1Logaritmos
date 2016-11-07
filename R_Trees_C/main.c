#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    srand(123);/*Inicializa el random, si no se cambia el parametro lanzara siempre la misma secuencia*/

    Node *header = createTestRectangles(127);
    char *node = writeToDisk(header);
    Rectangle *r = createRectangle(0,0,4,5,-1);
    Rectangle *r2 = createRectangle(0,0,4,5,-2);

    Node *searched;
    searched = search(node, r);
    insert(node,r);

    header = loadFromDisk(node);
    //linearSplit(loadFromDisk(node));
    if (header->size==M){
        //linearSplit(loadFromDisk(node));
        Node *new_father = createNode();
        new_father->rectArray = linearSplit(header);
        new_father->size = 2;
        node = writeToDisk(new_father);
    }
    //linearSplit(header);
    searched = search(node, r2);

}
