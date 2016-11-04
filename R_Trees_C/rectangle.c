#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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

=======
>>>>>>> a4537e7eca710b142a44be7b203b4243d7180bd8
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

void insertRectToNode(Node *n, Rectangle *r) {
    int i = 0;
    Node *header = n;
    while (i++ < n->size)
        n->rectArray++;
    *(n->rectArray) = r;

    n = header;
}

int intersect (Rectangle *r1, Rectangle *r2){
    return r1->x <= r2->x + r2->w && r2->x <= r1->x + r1->w && r1->y <= r2->y + r2->h && r2->y <= r1->y + r1->h;
}
/* Calcula la nueva Area si se agrega r2 a r1.
 *Retorna la diferencia de las Areas.*/
int MBR(Rectangle *r1, Rectangle *r2) {
    int min_x = r1->x < r2->x ? r1->x : r2->x;
    int max_x = r1->x + r1->w > r2->x + r2->w ? r1->x + r1->w : r2->x + r2->w;
    int min_y = r1->y < r2->y ? r1->y : r2->y;
    int max_y = r1->x + r1->h > r2->x + r2->h ? r1->x + r1->h : r2->x + r2->h;
    int r1_area = ( r1->w ) * ( r1->h );
    int area = (max_x-min_x) * (max_y-min_y);
    return area - r1_area;
}

/* Actualiza las coordenadas de r1 al agregarle r2, solo las actualiza no añade r2 a r1.*/
void mergeRectangle(Rectangle *r1, Rectangle *r2) {
    int max_x = r1->x + r1->w > r2->x + r2->w ? r1->x + r1->w : r2->x + r2->w;
    int max_y = r1->x + r1->h > r2->x + r2->h ? r1->x + r1->h : r2->x + r2->h;
    r1->x = r1->x < r2->x ? r1->x : r2->x;
    r1->y = r1->y < r2->y ? r1->y : r2->y;
    r1->w = max_x - r1->x ;
    r1->h = max_y - r1->y;
}

void insertar ( Node *node , Rectangle *r ) {
    if ( (node->rectArray)[0]->hijo != NULL ){
        int minMBR = INT_MAX;
        Rectangle *visitor;
        for (int i = 0; i < node->size; i++ ) {
            if( (node->rectArray)[i] == NULL )
                break;
            if ( MBR ( r, (node->rectArray)[i] ) < minMBR ){
                minMBR = MBR ( r, (node->rectArray)[i] );
                visitor = (node->rectArray)[i];

            }
        }
        insertar( visitor->hijo, r);
    }
    else {

        for (int i = 0; i< node->size; i ++ ){
            if((node->rectArray)[i] == NULL){
                (node->rectArray)[i] = r;
                break;
            }
        }
    }
}
