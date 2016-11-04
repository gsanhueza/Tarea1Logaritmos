#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    Rectangle *r = createRectangle(1, 2, 3, 4, "R");
    Rectangle *q = createRectangle(5,6,7,8,"Q");

    Node *node = createNode();
    Rectangle **asdf = (Rectangle **)malloc(sizeof(Rectangle*));

    //printf("X = %d\nY = %d\nAncho = %d\nAlto = %d\nId = %s\n\n", r->x, r->y, r->w, r->h, r->id);

    insertRectToNode(node,r);
    insertRectToNode(node,q);
    printf("Nodo: %s\n",(*(node->rectArray))->id);
    //(node->rectArray)++;
    //printf("Nodo: %s\n",(*(node->rectArray))->id);

    //*asdf = r;
    //node->rectArray = asdf;
    writeToDisk(node);
    writeToDisk(node);

    FILE *fp;
    char *c = (char *)r;
    fp = fopen("test.tree", "wb+");
    fwrite(r, sizeof(Rectangle), 1, fp);

    fclose(fp);

    Rectangle *rfile = malloc(sizeof(Rectangle));
    fp = fopen("test.tree","rb");
     if (fp != NULL) {
        fread(rfile, sizeof(Rectangle), 1, fp);
        fclose(fp);
    }
    //printf("Desde disco: %d\n", rfile->w);

    /**
     *        [1,      2,      N]
     *        /         \
     *     [3, 4, N]   [5, 6, 7]
     *      |  |        |  |  |
     *      N  N        N  N  N
     */

    Rectangle *r1 = createRectangle(1, 2, 3, 4, "R1");
    Rectangle *r2 = createRectangle(1, 2, 3, 4, "R2");
    Rectangle *r3 = createRectangle(1, 2, 3, 4, "R3");
    Rectangle *r4 = createRectangle(1, 2, 3, 4, "R4");
    Rectangle *r5 = createRectangle(1, 2, 3, 4, "R5");
    Rectangle *r6 = createRectangle(1, 2, 3, 4, "R6");
    Rectangle *r7 = createRectangle(1, 2, 3, 4, "R7");

    Node *n1 = createNode();
    Node *n2 = createNode();
    Node *header = createNode();

    insertRectToNode(n1, r3);
    insertRectToNode(n1, r4);

    insertRectToNode(n2, r5);
    insertRectToNode(n2, r6);
    insertRectToNode(n2, r7);

    r1->hijo = n1;
    r2->hijo = n2;

    insertRectToNode(header, r1);
    insertRectToNode(header, r2);

    Node* resultados = search(header, r2);
    Rectangle *iterator;

    while ((iterator = *(resultados->rectArray++)) != NULL) {
        printf("Encontrado = %s\n", iterator->id);
    }

}
