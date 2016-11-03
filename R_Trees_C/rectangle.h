#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#define MAX_SIZE 4096
#define MIN_SIZE 1638

/**
 * Estructuras
 */

typedef struct rectangle{
    int x;
    int y;
    int h;
    int w;
    char *id;
    struct node* hijo;
} Rectangle;

typedef struct node {
    Rectangle** rectArray;
} Node;

/**
 * Funciones
 */

Rectangle* createRectangle(int x, int y, int w, int h, char *id);
Node* createNode(Rectangle *rect, Node *node);
Node** search(Rectangle rect);
int insert(Rectangle rect);

#endif
