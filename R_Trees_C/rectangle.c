#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>

Rectangle* createRectangle(int x, int y, int w, int h, char *id) {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle *));
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    rect->id = id;
    return rect;
}

<<<<<<< HEAD
Node* loadFromDisk(char *filename) {
    
    FILE *fp;
    Node *nodeFile = malloc(sizeof(Node));
    fp = fopen(filename,"rb");
     if (fp != NULL) {
        fread(nodeFile, sizeof(Node), 1, fp);
        fclose(fp);
    }
    else
        printf("Error: el archivo no se puede abrir -- File: %s",filename);
    return nodeFile;
}

char* writeToDisk(Node *data) {
    char *fileName = (char *)malloc(sizeof(char));
    FILE *fp;
    sprintf(fileName, "Nodes/Node%d.bin", count);
    count++;
    fp = fopen(fileName,"wb+");
    char *c = (char*)data;
    fwrite(c, sizeof(Node), 1, fp);
    fclose(fp);
    return fileName;
    
}

int intersect(Rectangle rect1, Rectangle rect2){
=======
int intersect(Rectangle *rect1, Rectangle *rect2){
>>>>>>> master
    return 0;
}

Node* createNode() {
    Node* tree = (Node *)malloc(sizeof(Node));
    tree->rectArray = (Rectangle **)malloc(MAX_SIZE * sizeof(Rectangle **));
    tree->size = 0;

    return tree;
}

Node** search(Node *node, Rectangle *rect) {

    Node **answer = (Node **) malloc(sizeof(Node **));
    Node *aux = node;

    Rectangle *auxRect = *(aux->rectArray);

    while (auxRect != NULL) {
        if (intersect(auxRect, rect)) {
            printf("TODO: Agregar a answer\n");
        } else {
            printf("TODO: Omitir\n");
        }
        auxRect = *(aux->rectArray++);
    }

    return answer;
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
