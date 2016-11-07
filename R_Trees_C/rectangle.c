#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

/*****************************************************
 * Inicialización
 *****************************************************/

Rectangle* createRectangle(int x, int y, int w, int h, int id) {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle *));

    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    rect->id = (char *)malloc(sizeof(char));
    sprintf(rect->id, "rectangle%d", id);
    rect->hijo = NULL;
    return rect;
}

Node* createNode() {
    Node* tree = (Node *)malloc(sizeof(Node));
    tree->rectArray = (Rectangle **)malloc(BLOCK_SIZE);
    tree->size = 0;

    return tree;
}

/*****************************************************
 * Manejo de archivos
 *****************************************************/

Node* loadFromDisk(char *filename) {
    FILE *fp;
    Node *nodeFile = malloc(sizeof(Node));

    fp = fopen(filename,"rb");

    if (fp != NULL) {
        fread(nodeFile, sizeof(Node), 1, fp);
        fclose(fp);
    }
    else
        printf("Error: el archivo no se puede abrir -- File: %s", filename);
    return nodeFile;
}

char* writeToDisk(Node *data) {
    FILE *fp;
    char *fileName;

    if (data->this_node_filename!=NULL) {
        fileName = data->this_node_filename;
    }
    else {
        fileName = (char *) malloc(sizeof(char));
        sprintf(fileName,"Nodes/Node%d.bin", count);
        data->this_node_filename = fileName;
        count++;
    }
    fp = fopen(fileName,"wb");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo %s",fileName);
        return NULL;
    }
    char *c = (char*)data;
    fwrite(c, sizeof(Node), 1, fp);

    fclose(fp);
    free(data);
    data = NULL;
    return fileName;

}

/*****************************************************
 * Funciones auxiliares
 *****************************************************/

int intersect (Rectangle *r1, Rectangle *r2){
    return r1->x <= r2->x + r2->w && r2->x <= r1->x + r1->w && r1->y <= r2->y + r2->h && r2->y <= r1->y + r1->h;
}

int MBR(Rectangle *r1, Rectangle *r2) {
    int min_x = r1->x < r2->x ? r1->x : r2->x;
    int max_x = r1->x + r1->w > r2->x + r2->w ? r1->x + r1->w : r2->x + r2->w;
    int min_y = r1->y < r2->y ? r1->y : r2->y;
    int max_y = r1->x + r1->h > r2->x + r2->h ? r1->x + r1->h : r2->x + r2->h;
    int r1_area = ( r1->w ) * ( r1->h );
    int area = (max_x-min_x) * (max_y-min_y);
    return area - r1_area;
}

void mergeRectangle(Rectangle *r1, Rectangle *r2) {
    int max_x = r1->x + r1->w > r2->x + r2->w ? r1->x + r1->w : r2->x + r2->w;
    int max_y = r1->x + r1->h > r2->x + r2->h ? r1->x + r1->h : r2->x + r2->h;
    r1->x = r1->x < r2->x ? r1->x : r2->x;
    r1->y = r1->y < r2->y ? r1->y : r2->y;
    r1->w = max_x - r1->x ;
    r1->h = max_y - r1->y;
}

/*****************************************************
 * Implementación de la tarea
 *****************************************************/

Node* search(char *nodeName, Rectangle *rect) {
    Node *node = loadFromDisk(nodeName);
    Node * answer = createNode();
    Rectangle **aux = node->rectArray;
    int close = 0;
    int i;
    for ( i = 0 ; i <= node->size-1 ; i++ ) {
        Rectangle *auxRect = aux[i];
        // Agregar rectángulo que intersecta
        if (intersect(auxRect, rect)) {


            if (auxRect->hijo != NULL) {
                Node* recursive = search(auxRect->hijo,rect);
                for (int j = 0 ; j < recursive->size ; j++ ) {
                    answer->rectArray[answer->size] = recursive->rectArray[i];
                    answer->size++;
                }
                free(recursive);

            }
            if (auxRect->hijo == NULL) {
                answer->rectArray[answer->size] = auxRect;
                answer->size++;
                printf("intersect ");
                printRectangle(auxRect);
            }
        }

    }
    //     writeToDisk(nodeName);
    free(node);
    return answer;

}

void insert( char *nodeName , Rectangle *r ) {
    Node* node = loadFromDisk(nodeName);

    if ((node->rectArray)[0]->hijo != NULL) {
        int minMBR = INT_MAX;
        Rectangle * aux;
        for(int i = 0; i <= node->size-1 ; i++) {
            int this_mbr = MBR(node->rectArray[i],r);
            if ( this_mbr < minMBR ) {
                minMBR = this_mbr;
                aux = node->rectArray[i];
            }

        }
        writeToDisk(node);//cerrar Nodo;
        if (aux==NULL)
            printf("Error el nodo aux es null!");
        //Abrir nodo de aux.
        Node *auxHijo = loadFromDisk(aux->hijo);
        insert(auxHijo->this_node_filename, r);
        if (auxHijo->size == M){
            node = loadFromDisk(nodeName);
            Rectangle **rects = linearSplit(node);
            node->rectArray[node->size++]=rects[0];
            node->rectArray[node->size++] =rects[1];
            free(rects);
        }
        else
            return;
    }
    else {
        node->rectArray[node->size] = r;
        node->size++;
    }
    writeToDisk(node);

}

Rectangle ** linearSplit(Node *header) {
    int w, h;
    int *bounds = calculateBounds(header);
    w = bounds[0];
    h = bounds[1];
    Rectangle *rectangle1;
    Rectangle *rectangle2;

    Rectangle ** rectangles = calculateXRectangles(header);
    float width = (rectangles[1]-rectangles[0])/w;
    float heigth = (rectangles[3]-rectangles[2])/h;
    rectangle1 = width < heigth ? rectangles[3] : rectangles[1];
    rectangle2 = width < heigth ? rectangles[2] : rectangles[0];

    Rectangle **arrayRect = makeRandom(*header);
    Node *noder1 = createNode();
    Node *noder2 = createNode();
    for ( int i = 0; i < header->size ; i++) {
        if(arrayRect[i] != rectangle1 && arrayRect[i] != rectangle2) {
            if (header->size - i + noder1->size == m) {
                noder1->rectArray[noder1->size] = arrayRect[i];
                noder1->size++;
                printf("The rectangle, ");
                printRectangle(arrayRect[i]);
                mergeRectangle(rectangle1,arrayRect[i]);
                printf("inside rectangle %s \n", rectangle1->id);
                continue;
            }
            if (header->size - i + noder2->size == m) {
                noder2->rectArray[noder2->size] = arrayRect[i];
                noder2->size++;
                mergeRectangle(rectangle2,arrayRect[i]);
                printf("The rectangle, ");
                printRectangle(arrayRect[i]);
                printf("inside rectangle %s \n", rectangle2->id);
                continue;
            }
            if(MBR(rectangle1, arrayRect[i])<MBR(rectangle2, arrayRect[i])){
                noder1->rectArray[noder1->size] = arrayRect[i];
                noder1->size++;
                mergeRectangle(rectangle1,arrayRect[i]);
                printf("The rectangle, ");
                printRectangle(arrayRect[i]);
                printf("inside rectangle %s \n", rectangle1->id);
            }
            else{
                noder2->rectArray[noder2->size] = arrayRect[i];
                noder2->size++;
                mergeRectangle(rectangle2,arrayRect[i]);
                printf("The rectangle, ");
                printRectangle(arrayRect[i]);
                printf("inside rectangle %s \n", rectangle2->id);
            }

        }
    }
    rectangle1->hijo = writeToDisk(noder1);
    rectangle2->hijo = writeToDisk(noder2);
    free(header);
    Rectangle **rectarray = (Rectangle **) malloc(M*sizeof(Rectangle *));

    rectarray[0]=rectangle1;
    rectarray[1] = rectangle2;
    for (int i = 2; i < M ; i ++ )
        rectarray[i] = NULL;


    return rectarray;
    
}

Rectangle ** GreeneSplit(Node *header) {
    return NULL;
}

Rectangle **makeRandom(Node pNode) {
    int times = pNode.size * 5;
    int r1,r2;
    while (times > 0){
        r1 = rand() % pNode.size;
        r2 = rand() % pNode.size;
        Rectangle *r = pNode.rectArray[r1];
        pNode.rectArray[r1] = pNode.rectArray[r2];
        pNode.rectArray[r2] = r;
        times--;
    }
    return pNode.rectArray;
}

void printRectangle(Rectangle* auxRect) {
    printf("%s, have x = %d, y = %d, w = %d, h = %d.\n ", auxRect->id, auxRect->x, auxRect->y, auxRect->w, auxRect->h);

}

Rectangle **calculateXRectangles(Node *pNode) {
    int min_x = 0;
    int max_x = INT_MAX;
    int min_y = 0;
    int max_y = INT_MAX;
    Rectangle *minX, *maxX, *minY, *maxY;

    for (int i = 0 ; i < pNode->size ; i++) {
        Rectangle *rectangle1 = pNode->rectArray[i];
        if(min_x < rectangle1->x) {
            min_x = rectangle1->x;
            minX = rectangle1;
        }
        if(max_x > rectangle1->x + rectangle1->w) {
            max_x = rectangle1->x + rectangle1->w;
            maxX = rectangle1;
        }
        if(min_y < rectangle1->y) {
            min_y = rectangle1->y;
            minY = rectangle1;
        }
        if(max_y > rectangle1->y + rectangle1->h) {
            max_y = rectangle1->y + rectangle1->h;
            maxY = rectangle1;
        }
    }

    Rectangle **array = (Rectangle**)malloc(M *sizeof(Rectangle*));

    array[0] = minX;
    array[1] = maxX;
    array[2] = minY;
    array[3] = maxY;
    return array;
}

int *calculateBounds(Node *pNode) {
    int max_x = 0;
    int min_x = INT_MAX;
    int max_y = 0;
    int min_y = INT_MAX;

    for ( int i = 0; i < pNode->size; i++ ){
        Rectangle *r = pNode->rectArray[i];
        max_x = max_x > r->x + r->w ? max_x : r->x + r->w;
        min_x = min_x < r->x ? min_x : r->x;
        max_y = max_y > r->y + r->h ? max_y : r->y + r->h;
        min_y = min_y < r->y ? min_y : r->y;
    }
    int *array = (int*)malloc(sizeof(int*));
    array[0] = max_x - min_x;
    array[1] = max_y - min_y;
    return array;
}

int randomNum(int max) {
    return rand() % max;
}

Node *createTestRectangles(int n) {
    Node *node = createNode();
    char name[200];
    for (int i = 0; i < n ; i ++){
        sprintf(name, "Rectangle%d", i);
        //puts(id);
        Rectangle *rect = createRectangle(randomNum(100), randomNum(100), randomNum(100), randomNum(100), i);
        printRectangle(rect);
        node->rectArray[i] = rect;
        node->size++;
    }
    return node;
}
