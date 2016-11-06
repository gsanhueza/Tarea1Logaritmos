//
// Created by rodrigo on 11/5/16.
//
#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *createTestRectangles(int n) ;

int randomNum(int max) {
    return rand()%max;
}

int main(int argc,char **argv) {
    srand(123);/*Inicializa el random, si no se cambia el parametro lanzara siempre la misma secuencia*/
    Node *header = createTestRectangles(50);
    Rectangle *r = createRectangle(0,0,4,5,"hola");
    Node *searched;

    insert(header,r);
    searched = search(header, r);

}

Node *createTestRectangles(int n) {
    Node *node = createNode();
    char *id;
    for (int i = 0; i < n ; i ++ ){
        sprintf(id, "Rectangle%d", i);
        Rectangle *rect = createRectangle(randomNum(10),randomNum(10),randomNum(10),randomNum(10),id);
        printRectangle(rect,"the rectangle");
        node->rectArray[i]=rect;
        node->size++;
    }
    return node;



}