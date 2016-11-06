//
// Created by rodrigo on 11/5/16.
//
#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *createTestRectangles(int n) ;

int main(void) {
    Node *header = createTestRectangles(50);
    Rectangle *r = createRectangle(0,0,4,5,"hola");
    Node *searched;

    insert(header,r);
    searched = search(header, r);

}

Node *createTestRectangles(int n) {
    Node *node = createNode();
    for (int i = 0; i < n ; i ++ ){
        int x = rand()%10;
        int y = rand()%10;
        int w = rand()%10;
        int h = rand()%10;
        Rectangle *rectangle1 = createRectangle(x,y,w,h,i);
        printRectangle(rectangle1,"the rectangle");
        node->rectArray[i]=rectangle1;
        node->size++;
    }
    return node;



}