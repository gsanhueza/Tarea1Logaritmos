#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void) {
    srand(123);/*Inicializa el random, si no se cambia el parametro lanzara siempre la misma secuencia*/
    Node *header = createNode();
    Rectangle ** rects = bateriaRectangulos(262144);
    header->rectArray[0] = rects[0];
    header->size++;


    Rectangle *r = createRectangle(0,0,4,5,-1);
    Rectangle *r2 = createRectangle(0,0,4,5,-2);
    char* node = writeToDisk(header);
    for( int i = 1; i < 262144; i++ ){
        insert(node,rects[i]);
        header = loadFromDisk(node);
        if (header->size==M){

            Node *new_father = createNode();
            new_father->rectArray = linearSplit(header);
            new_father->size = 2;
            node = writeToDisk(new_father);

        }
    }
    header = loadFromDisk(node);


    //linearSplit(header);
    Node * buscar = search(node, r);

}
