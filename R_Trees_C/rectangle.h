#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#define MAX_SIZE 4096
#define MIN_SIZE 1638
#define TRUE 1
#define FALSE 0
#define M 120
#define m 52
#define NUM_RANDOM_RECTS 1000;

static int count =2;

/**
 * Estructuras
 */

typedef struct rectangle{
    int x;
    int y;
    int h;
    int w;
    char *id;
    char *hijo;
} Rectangle;

typedef struct node {
    Rectangle** rectArray;
    int size;
    char* this_node_filename;
} Node;

/**
 * Funciones
 */

Rectangle* createRectangle(int x, int y, int w, int h, int id);
Node* createNode();
Node * search(char *nodeName, Rectangle *rect);

Node* loadFromDisk(char *filename);
char* writeToDisk(Node *data);

void insertRectToNode(Node *n, Rectangle *r);

int intersect (Rectangle *r1, Rectangle *r2);
void mergeRectangle(Rectangle *r1, Rectangle *r2);
int MBR(Rectangle *r1, Rectangle *r2);
void printRectangle(Rectangle *r, char *s);
void insert( char *nodeName , Rectangle *r );
Rectangle ** linearSplit(Node *header);
#endif
