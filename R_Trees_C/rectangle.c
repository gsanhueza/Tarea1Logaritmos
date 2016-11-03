#include "rectangle.h"
#include <stdlib.h>

Rectangle* createRectangle(int x, int y, int w, int h, char *id) {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle *));
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    rect->id = id;
    return rect;
}

int intersect(Rectangle rect1, Rectangle rect2){
    return 0;
}

Node* createNode(Rectangle *rect, Node *rtree) {
    Node* tree = (Node *)malloc(sizeof(Node));
    tree->rectArray = (Node **)malloc(sizeof(Node*));

    *(tree->rectArray) = rtree;
    return tree;
}

Node** search(Rectangle rect) {
    return NULL;
}

int* insertar(Rectangle rect) {
    return 0;
}
