#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <error.h>

/*****************************************************
 * Inicialización
 *****************************************************/

int count = 1;
int accessToDisk = 0;

void setAccessToDisk(int n) {
    accessToDisk=n;
}
int getAccessToDisk(){
    return accessToDisk;
}

void insertLinear( char *nodeName , Rectangle *r ) ;

void freeMemory(Node *pNode);

Rectangle* createRectangle(int x, int y, int w, int h, int id) {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle));
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    rect->id = id;
    rect->hijo = NULL;
    return rect;
}

Node* createNode() {
    Node* tree = (Node *)malloc(sizeof(Node));
    tree->rectArray = (Rectangle **)malloc(M * sizeof(Rectangle));
    tree->occupied = 0;
    tree->this_node_filename = NULL;

    return tree;
}

/*****************************************************
 * Manejo de archivos
 *****************************************************/
char * writeToDisk(Node * data){
    FILE *fp;
    char *fileName = (char * )malloc(sizeof (char)*30);
    if(data->this_node_filename != NULL) {
        fileName = data->this_node_filename;
    }
    else {
        sprintf(fileName, "Nodes/Node%d.bin", count);
        data->this_node_filename = fileName;
        count++;
    }
    fp = fopen(fileName, "wb");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo %s\n", fileName);
        return NULL;
    }
    fwrite(&(data->occupied), sizeof(int),1,fp);
    for ( int i = 0 ; i < data->occupied; i ++ ){
        Rectangle *r = (data->rectArray[i]);
        /*if(r->hijo == NULL || strcmp(r->hijo, "--"))
            r->hijo = "--";
        fprintf(fp, "%d %d %d %d %d %s\n",r->x,r->y,r->w,r->h,r->id,r->hijo);*/
        int l = sizeof(r->hijo);
        fwrite(&l, sizeof(int),1,fp);
        fwrite(&(r->x), sizeof(int), 1, fp);
        fwrite(&(r->y), sizeof(int), 1, fp);
        fwrite(&(r->w), sizeof(int), 1, fp);
        fwrite(&(r->h), sizeof(int), 1, fp);
        fwrite(&(r->id), sizeof(int), 1, fp);
        fwrite(&(r->hijo), sizeof(r->hijo),1, fp);
        if(r->hijo != NULL){
            free(r->hijo);
        }
        free(data->rectArray[i]);

    }
    accessToDisk++;
    fclose(fp);
    free(data);
    return fileName;
}
Node * loadFromDisk (char * filename){
    FILE *fp;
    Node *nodeFile = createNode();
    fp = fopen(filename,"rb");
    if (fp!=NULL) {
        fread(&(nodeFile->occupied), sizeof(int),1,fp);
        for (int i = 0; i<nodeFile->occupied ; i++) {
            int x, y, h, w, id,namelength;
            fread(&namelength, sizeof(int),1,fp);
            char *hijo =(char *) malloc(namelength* sizeof(char));
            if(namelength == 8) {
                free(hijo);

            }

            fread(&x, sizeof(int), 1, fp);
            fread(&y, sizeof(int), 1, fp);
            fread(&w, sizeof(int), 1, fp);
            fread(&h, sizeof(int), 1, fp);
            fread(&id, sizeof(int), 1, fp);
            fread(&hijo, sizeof(hijo), 1, fp);
            Rectangle *r = createRectangle(x,y,w,h,id);
            /*fscanf(fp,"%d%d%d%d%d%s\n",&x,&y,&w,&h,&id,hijo);
            Rectangle *r = createRectangle(x,y,w,h,id);
            if (hijo!=NULL && '-'==hijo[0]) {
                r->hijo = NULL;
            }
            else{*/
            if(namelength == 8) {
                hijo = NULL;

            }
            r->hijo = hijo;
            //}

            nodeFile->rectArray[i] = r;
        }

        fclose(fp);
    }
    else
        printf("Error: el archivo no se puede abrir -- File: %s", filename);
//     printf("LFD: nodeFile->this_node_filename = %s\n", nodeFile->this_node_filename);
    (*nodeFile).this_node_filename = filename;

    accessToDisk++;
    return nodeFile;
}
/*
Node* loadFromDisk(char *filename) {
    FILE *fp;
    Node *nodeFile =(Node *) malloc(sizeof(Node));

    fp = fopen(filename,"rb");

    if (fp != NULL) {
        fread(nodeFile, sizeof(Node), 1, fp);
        fclose(fp);
    }
    else
        printf("Error: el archivo no se puede abrir -- File: %s", filename);
//     printf("LFD: nodeFile->this_node_filename = %s\n", nodeFile->this_node_filename);
    return nodeFile;
}

char* writeToDisk(Node *data) {
    FILE *fp;
    char *fileName = (char *) malloc(100 * sizeof(char));
    if (data->this_node_filename != NULL) {
        fileName = data->this_node_filename;
    }
    else {
        sprintf(fileName, "Nodes/Node%d.bin", count);
        data->this_node_filename = fileName;
        count++;
    }

    fp = fopen(fileName, "wb");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo %s\n", fileName);
        return NULL;
    }


    char *c = (char*)data;
    fwrite(c, sizeof(Node), 1, fp);

    fclose(fp);
    free(data);
    data = NULL;
//     printf("WTD: filename = %s\n", fileName);
    return fileName;

}*/

/*****************************************************
 * Funciones auxiliares
 *****************************************************/

int intersect (Rectangle *r1, Rectangle *r2){
    return r1->x <= r2->x + r2->w && r2->x <= r1->x + r1->w && r1->y <= r2->y + r2->h && r2->y <= r1->y + r1->h;
}

long MBR(Rectangle *r1, Rectangle *r2) {
    int min_x = r1->x < r2->x ? r1->x : r2->x;
    int max_x = r1->x + r1->w > r2->x + r2->w ? r1->x + r1->w : r2->x + r2->w;
    int min_y = r1->y < r2->y ? r1->y : r2->y;
    int max_y = r1->x + r1->h > r2->x + r2->h ? r1->x + r1->h : r2->x + r2->h;
    long r1_area = (long)( r1->w ) * (long)( r1->h );
    long area =(long) (max_x-min_x) * (long)(max_y-min_y);
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
    int i;

    for (i = 0 ; i < node->occupied  ; i++) {
        Rectangle *auxRect = aux[i];
        // Agregar rectángulo que intersecta
        if (intersect(auxRect, rect)) {


            if (auxRect->hijo != NULL) {
                writeToDisk(node);
                Node* recursive = search(auxRect->hijo,rect);
                for (int j = 0 ; j < recursive->occupied ; j++ ) {
                    answer->rectArray[answer->occupied++] = recursive->rectArray[j];
                }
                writeToDisk(recursive);

            }
            else {
                answer->rectArray[answer->occupied++] = auxRect;
            }
        }

    }
    //     writeToDisk(nodeName);
    writeToDisk(node);
    return answer;

}


void insertToRootLinear(char *nodeName,Rectangle *r) {
    insertLinear(nodeName,r);
    Node *node = loadFromDisk(nodeName);
    if (node->occupied >=M) {
        Rectangle ** aux =linearSplit(node);
        Node *newNode = createNode();
        newNode->rectArray[0] = aux[0];
        newNode->rectArray[1] = aux[1];
        newNode->occupied = 2;
        newNode->this_node_filename = node->this_node_filename;
        free(node);
        writeToDisk(newNode);
    }
    else{
        writeToDisk(node);
    }

}
void insertToRootGreene(char* nodeName, Rectangle *r){
    insertGreene(nodeName,r);
    Node *node= loadFromDisk(nodeName);
    if (node->occupied >=M) {
        Rectangle ** aux = greeneSplit(node);
        Node *newNode = createNode();
        newNode->rectArray[0] = aux[0];
        newNode->rectArray[1] = aux[1];
        newNode->occupied = 2;
        newNode->this_node_filename = (*node).this_node_filename;
        free(node);
        writeToDisk(newNode);
    }
    else{
        writeToDisk(node);
    }
}

void freeMemory(Node *pNode) {
    for(int i = 0; i<pNode->occupied; i ++){
        free(pNode->rectArray[i]);
    }
    free(pNode);

}

void insertGreene(char *nodeName, Rectangle *r) {
    Node *node = loadFromDisk(nodeName);

    if ((node->rectArray)[0]->hijo != NULL && (node->rectArray)[0]->hijo[0]!= 'N') { // Necesito llegar a la hoja
        long minMBR = LONG_MAX;
        Rectangle * aux;

        for(int i = 0; i <= node->occupied - 1 ; i++) {
            long this_mbr = MBR(node->rectArray[i],r);
            if ( this_mbr < minMBR ) {
                minMBR = this_mbr;
                aux = node->rectArray[i];
            }
        }
        if (aux==NULL)
            printf("Error el nodo aux es null!");
        writeToDisk(node);
        //Abrir nodo de aux.
        insertGreene(aux->hijo, r);
        node = loadFromDisk(nodeName);

        /* Control de Overflow */
        Node *auxHijo = loadFromDisk(aux->hijo);

        if (auxHijo->occupied >= M){
            Rectangle ** rects = greeneSplit(auxHijo);
            free(aux);
            aux = rects[0];
            free(auxHijo);
            node->rectArray[node->occupied++] = rects[1];

        }
        else {
            writeToDisk(auxHijo);
        }
    }
    else {
        /* Control de Overflow */
        node->rectArray[node->occupied] = r;
        node->occupied++;
    }
    writeToDisk(node);
}

void insertLinear( char *nodeName , Rectangle *r ) {
    Node *node = loadFromDisk(nodeName);

    if ((node->rectArray)[0]->hijo != NULL  ) { // Necesito llegar a la hoja
        long minMBR = LONG_MAX;
        Rectangle * aux;

        for(int i = 0; i <= node->occupied - 1 ; i++) {
            long this_mbr = MBR(node->rectArray[i],r);
            if ( this_mbr < minMBR ) {
                minMBR = this_mbr;
                aux = node->rectArray[i];
            }
        }
        writeToDisk(node);
        //Abrir nodo de aux.
        insertLinear(aux->hijo, r);
        node = loadFromDisk(nodeName);

        /* Control de Overflow */
        Node *auxHijo = loadFromDisk(aux->hijo);

        if (auxHijo->occupied >= M){
            Rectangle ** rects = linearSplit(auxHijo);
            free(aux);
            aux = rects[0];
            free(auxHijo);
            node->rectArray[node->occupied++] =rects[1];
            free(rects);
        }
        else {
            writeToDisk(auxHijo);
        }

    }
    else {
        /* Control de Overflow */
        node->rectArray[node->occupied++] = r;
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

    makeRandom(header);

    Node *noder1 = createNode();
    Node *noder2 = createNode();

    for ( int i = 0; i < header->occupied ; i++) {
        if(header->rectArray[i] != rectangle1 && header->rectArray[i] != rectangle2) {
            if (header->occupied - i + noder1->occupied == m) {
                noder1->rectArray[noder1->occupied] = header->rectArray[i];
                noder1->occupied++;
                mergeRectangle(rectangle1, header->rectArray[i]);
                continue;
            }
            if (header->occupied - i + noder2->occupied == m) {
                noder2->rectArray[noder2->occupied] = header->rectArray[i];
                noder2->occupied++;

                mergeRectangle(rectangle2, header->rectArray[i]);

                continue;
            }
            if(MBR(rectangle1, header->rectArray[i])<MBR(rectangle2, header->rectArray[i])){
                noder1->rectArray[noder1->occupied] = header->rectArray[i];
                noder1->occupied++;
                mergeRectangle(rectangle1,header->rectArray[i]);

            }
            else{
                noder2->rectArray[noder2->occupied] = header->rectArray[i];
                noder2->occupied++;
                mergeRectangle(rectangle2,header->rectArray[i]);

            }

        }
    }

    rectangle1->hijo = writeToDisk(noder1);
    rectangle2->hijo = writeToDisk(noder2);

    Rectangle **rectarray = (Rectangle **) malloc(2 * sizeof(Rectangle *));

    rectarray[0] = rectangle1;
    rectarray[1] = rectangle2;
    free(rectangles);

    return rectarray;

}
int partitionX(Node *header,int inicio,int final) {
    int pivot,i,j;
    Rectangle *t;
    Rectangle ** aux = header->rectArray;
    pivot = inicio;
    i = inicio;
    j = final-1;
    while (i<j) {
        while((aux[i]->x) <=(aux[pivot]->x) && i<final-1)
            i++;
        while ((aux[j]->x)>(aux[pivot]->x))
            j--;
        if (i<j) {
            t = aux[i];
            aux[i] = aux[j];
            aux[j] = t;
        }
    }
    t = aux[pivot];
    aux[pivot] = aux[j];
    aux[j] = t;

    return j;
}

int partitionY(Node *header,int inicio,int final) {
    int pivot,i,j;
    Rectangle *t;
    Rectangle ** aux = header->rectArray;
    pivot = inicio;
    i = inicio;
    j = final-1;
    while (i<j) {
        while((aux[i]->y) <=(aux[pivot]->y) && i<final-1)
            i++;
        while ((aux[j]->y)>(aux[pivot]->y))
            j--;
        if (i<j) {
            t = aux[i];
            aux[i] = aux[j];
            aux[j] = t;
        }
    }
    t = aux[pivot];
    aux[pivot] = aux[j];
    aux[j] = t;

    return j;


}

void quicksort(Node *header,int inicio,int final,int d){
    int j;
    if (inicio < final) {
        if (d == 0)
            j = partitionX(header,inicio,final);
        else
            j = partitionY(header,inicio,final);
        quicksort(header,inicio, j, d);
        quicksort(header,j + 1, final, d);

    }
}

Rectangle ** greeneSplit(Node *header) {
    Rectangle *min;
    Rectangle *max;
    int w, h;
    int *bounds = calculateBounds(header);
    w = bounds[0];
    h = bounds[1];
    int direccionCorte = 0;
    Rectangle **rectangles = calculateXRectangles(header);
    float width = (rectangles[1]-rectangles[0])/w;
    float heigth = (rectangles[3]-rectangles[2])/h;
    max = width < heigth ? rectangles[3] : rectangles[1];
    min = width < heigth ? rectangles[2] : rectangles[0];
    direccionCorte = width < heigth ? 0:1;/*0 si es el eje x, 1 si es el eje 1*/
    /*Calcular los rectangulos mas distantes con los pasos de linear split*/
    //pasosLinear(min,max,header);
    quicksort(header,0,header->occupied,direccionCorte);
    free(bounds);
    Node *noder1 = createNode();
    Node *noder2 = createNode();
    for(int i = 0 ; i < header->occupied  ; i++) {
        if(header->rectArray[i] != min && header->rectArray[i] != max && noder1->occupied < M/2 + 1 ) {
            noder1->rectArray[noder1->occupied++] = header->rectArray[i];
            mergeRectangle(min,header->rectArray[i]);
        }
        else if(header->rectArray[i] != min && header->rectArray[i] != max) {
            noder2->rectArray[noder2->occupied++] = header->rectArray[i];
            mergeRectangle(max,header->rectArray[i]);

        }
    }
    min->hijo = writeToDisk(noder1);
    max->hijo = writeToDisk(noder2);
    Rectangle **rectarray = (Rectangle **) malloc(2 * sizeof(Rectangle *));

    rectarray[0] = createRectangle(min->x,min->y,min->w,min->h,min->id);
    rectarray[0]->hijo = (*min).hijo;
    free(min);
    rectarray[1] = createRectangle(max->x,max->y,max->w,max->h,max->id);
    rectarray[1]->hijo = (*max).hijo;
    free(max);
    free(rectangles);
    return rectarray;

    /*Ahora el nodo esta ordenado, hay que mover los primeros M/2 -1 rectangulos al primer nodo y los otros al segundo*/

}

void makeRandom(Node *pNode) {
    int times = pNode->occupied * 5;
    int r1,r2;
    while (times > 0){
        r1 = rand() % pNode->occupied;
        r2 = rand() % pNode->occupied;
        Rectangle *r = pNode->rectArray[r1];
        pNode->rectArray[r1] = pNode->rectArray[r2];
        pNode->rectArray[r2] = r;
        times--;
    }
}

void printRectangle(Rectangle* auxRect) {
//      printf("Rectangle %d, have x = %d, y = %d, w = %d, h = %d.\n ", auxRect->id, auxRect->x, auxRect->y, auxRect->w, auxRect->h);

}

Rectangle **calculateXRectangles(Node *pNode) {
    int min_x = 0;
    int max_x = INT_MAX;
    int min_y = 0;
    int max_y = INT_MAX;
    Rectangle *minX, *maxX, *minY, *maxY;

    for (int i = 0 ; i < pNode->occupied ; i++) {
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

    Rectangle **array = (Rectangle**)malloc(4 *sizeof(Rectangle*));

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

    for ( int i = 0; i < pNode->occupied; i++ ){
        Rectangle *r = pNode->rectArray[i];
        max_x = max_x > r->x + r->w ? max_x : r->x + r->w;
        min_x = min_x < r->x ? min_x : r->x;
        max_y = max_y > r->y + r->h ? max_y : r->y + r->h;
        min_y = min_y < r->y ? min_y : r->y;
    }
    int *array = (int*)malloc(sizeof(int)*2);
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
        Rectangle *rect = createRectangle(randomNum(499900), randomNum(499900),1 + randomNum(99), 1 + randomNum(99), i);
        printRectangle(rect);
        node->rectArray[i] = rect;
        node->occupied++;
    }
    return node;
}

Rectangle * bateriaRectangulos(int i){
    Rectangle *rect = createRectangle(randomNum(499900), randomNum(499900),1 + randomNum(99), 1 + randomNum(99), i);
    return rect;
}
Rectangle *copy(Rectangle r, int n){
    Rectangle *rect = createRectangle(r.x,r.y,r.w, r.h, r.id);
    return rect;
}
