#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int randomNum(int max) {
    return rand() % max;
}

Node *createTestRectangles(int n) {
    Node *node = createNode();
    char name[200];
    for (int i = 0; i < n ; i ++ ){
        sprintf(name, "Rectangle%d", i);
        //puts(id);
        Rectangle *rect = createRectangle(randomNum(10),randomNum(10),randomNum(10),randomNum(10),i);
        printRectangle(rect);
        node->rectArray[i]=rect;
        node->size++;
    }
    return node;
}

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
