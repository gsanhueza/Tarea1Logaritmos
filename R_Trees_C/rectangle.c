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
