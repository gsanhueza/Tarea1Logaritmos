#include "rectangle.h"
#include <stdio.h>

int main (int argc,char **argv) {
    printf("Hello World!\n");
    Rectangle *r = createRectangle(1, 2, 3, 4, "R");

    printf("X = %d\nY = %d\nAncho = %d\nAlto = %d\nId = %s\n\n", r->x, r->y, r->w, r->h, r->id);
    /*

    printf("%i\n",r.y);
    RTree *t = (RTree *)malloc(sizeof(RTree));
    t->rect = r;
    t->trees = NULL;
    RTree *tree = createRTree(&r,NULL);
    FILE *fp;
    char *c = (char *)&r;
    fp = fopen("test.tree","wb+");
    int x = fputs(c, fp );//fputs((char *) r,fp);
    fclose(fp);

    printf("%i\n",(t->rect).y);
    printf("%i\n", (tree->rect.x));
    */
}
