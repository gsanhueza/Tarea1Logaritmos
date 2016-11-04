#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#define MAX_SIZE 4096
#define MIN_SIZE 1638
#define TRUE 1
#define FALSE 0

static int count =0;

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
    int size;
} Node;

/**
 * Funciones
 */

Rectangle* createRectangle(int x, int y, int w, int h, char *id);
Node* createNode();
Node* search(Node *node, Rectangle *rect);
void insertar (Node *node , Rectangle *r );

Node* loadFromDisk(char *filename);
char* writeToDisk(Node *data);

void insertRectToNode(Node *n, Rectangle *r);

int intersect (Rectangle *r1, Rectangle *r2);
void mergeRectangle(Rectangle *r1, Rectangle *r2);
int MBR(Rectangle *r1, Rectangle *r2);

#endif
