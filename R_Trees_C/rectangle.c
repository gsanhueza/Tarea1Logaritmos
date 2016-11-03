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

Node* createNode() {
    Node* tree = (Node *)malloc(sizeof(Node));
    tree->rectArray = (Rectangle **)malloc(MAX_SIZE * sizeof(Rectangle **));
    tree->size = 0;

    return tree;
}

Node** search(Node *node, Rectangle *rect) {
    return NULL;
}

int* insertar(Rectangle rect) {
    return 0;
}

void insertRectToNode(Node *n, Rectangle *r) {
    int i = 0;
    Node *header = n;
    while (i++ < n->size)
        n->rectArray++;
    *(n->rectArray) = r;

    n = header;
}
