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
    
  
  *asdf = r;
  node->rectArray = asdf;
  writeToDisk(node);
  writeToDisk(node);
    





}
