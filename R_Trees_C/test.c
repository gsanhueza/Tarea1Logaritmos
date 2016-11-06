//
// Created by rodrigo on 11/5/16.
//
#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *createTestRectangles(int n) ;

int main(void) {
    Node *header = createTestRectangles(119);
    char *name_header = writeToDisk(header);
    Rectangle *r = createRectangle(0,0,4,5,-1);
    Node *searched;
    insert(header,r,"Node0.bin");
    if (header->size==M){
        Node *new_father = createNode();
        new_father->rectArray = linearSplit(header);
        name_header = writeToDisk(new_father);
    }
    searched = search(loadFromDisk(name_header), r);

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