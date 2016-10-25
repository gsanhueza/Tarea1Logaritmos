#include "main.h"
#include <stdio.h>


Rectangle createRect(int x, int y, int w, int h) {
    Rectangle rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return rect;
}

RTree* createRTree(Rectangle rect, RTree *rtree) {
    RTree* tree;
    tree->rect = rect;
    RTree** aux = tree->trees;
    while (tree->trees!=NULL)
        (tree->trees)++;
    *(tree->trees) = rtree;
    tree->trees = aux;
    return tree;
    
}

RTree* search(Rectangle rect) {
    return NULL;
}

int* insertar(Rectangle rect) {
    return 0;
}








int main (int argc,char **argv) {
    Rectangle r = createRect(1,2,3,4);
    printf("%i",r.y);
}

