#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc,char **argv) {
    printf("Hello World!\n");
    Rectangle *r = createRectangle(1, 2, 3, 4, "R");

    Node *node = (Node * )malloc(sizeof(Node));
    Rectangle **asdf = (Rectangle **)malloc(sizeof(Rectangle*));

    printf("X = %d\nY = %d\nAncho = %d\nAlto = %d\nId = %s\n\n", r->x, r->y, r->w, r->h, r->id);


  /*  printf("%i\n",r.y);
    RTree *t = (RTree *)malloc(sizeof(RTree));
    t->rect = r;
    t->trees = NULL;
    RTree *tree = createRTree(&r,NULL);*/
    FILE *fp;
    char *c = (char *)r;
    fp = fopen("test.tree","wb+");
    fwrite(r, sizeof(Rectangle), 1, fp);
    //int x = fputs(c, fp );//fputs((char *) r,fp);
    fclose(fp);
    Rectangle *rfile = malloc(sizeof(Rectangle));
    fp = fopen("test.tree","rb");
     if (fp != NULL) {
        fread(rfile, sizeof(Rectangle), 1, fp);
        fclose(fp);
    }
    printf("Desde disco: %d",rfile->w);

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

    insertRectToNode(n1, r3);
    insertRectToNode(n1, r4);

    insertRectToNode(n2, r5);
    insertRectToNode(n2, r6);
    insertRectToNode(n2, r7);

}
