#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*****************************************************
 * Inicialización
 *****************************************************/
Rectangle ** controlOverFlow(Node *header, Rectangle *r);
Rectangle * linearSplit(Node *header, Rectangle *r);

int *calculateBounds(Node *pNode);

Rectangle **calculateXRectangles(Node *pNode, int w, int h);

Rectangle **makeRandom(Node pNode);

/**
 * @brief Crea un rectángulo con coordenadas y nombre.
 *
 * @param x p_x: Coordenada X.
 * @param y p_y: Coordenada Y.
 * @param w p_w: Ancho.
 * @param h p_h: Alto.
 * @param id p_id: Identificador.
 * @return Rectangle* El Rectángulo creado.
 */
Rectangle* createRectangle(int x, int y, int w, int h, char *id) {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle *));
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    rect->id = id;
    return rect;
}

/**
 * @brief Crea un nodo con un arreglo de rectángulos como información interna.
 *
 * @return Node* El nodo creado.
 */
Node* createNode() {
    Node* tree = (Node *)malloc(sizeof(Node));
    tree->rectArray = (Rectangle **)malloc(MAX_SIZE * sizeof(Rectangle *));
    tree->size = 0;

    return tree;
}

/*****************************************************
 * Manejo de archivos
 *****************************************************/

/**
 * @brief Carga un archivo del disco.
 *
 * @param filename p_filename: Nombre del archivo de disco.
 * @return Node* Nodo representante.
 */
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

/**
 * @brief Escribe los datos de un nodo a disco.
 *
 * @param data p_data: Datos a escribir.
 * @return char* Nombre del archivo escrito a disco.
 */
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

/*****************************************************
 * Funciones auxiliares
 *****************************************************/


/**
 * @brief Inserta un rectángulo al nodo dado.
 *
 * @param n p_n: Nodo donde insertar.
 * @param r p_r: Rectángulo a insertar.
 */
void insertRectToNode(Node *n, Rectangle *r) {
    int i = 0;
    Rectangle **header = n->rectArray;
    while (i++ < n->size)
        n->rectArray++;
    *(n->rectArray) = r;
    n->size++;
    n->rectArray = header;
}


/**
 * @brief Retorna un "booleano" que dice si los dos rectángulos se intersectan.
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 * @return int TRUE o FALSE
 */
int intersect (Rectangle *r1, Rectangle *r2){
    return r1->x <= r2->x + r2->w && r2->x <= r1->x + r1->w && r1->y <= r2->y + r2->h && r2->y <= r1->y + r1->h;
}

/**
 * @brief Calcula la nueva Area si se agrega r2 a r1.
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 * @return int La diferencia de las Areas.
 */
int MBR(Rectangle *r1, Rectangle *r2) {
    int min_x = r1->x < r2->x ? r1->x : r2->x;
    int max_x = r1->x + r1->w > r2->x + r2->w ? r1->x + r1->w : r2->x + r2->w;
    int min_y = r1->y < r2->y ? r1->y : r2->y;
    int max_y = r1->x + r1->h > r2->x + r2->h ? r1->x + r1->h : r2->x + r2->h;
    int r1_area = ( r1->w ) * ( r1->h );
    int area = (max_x-min_x) * (max_y-min_y);
    return area - r1_area;
}

/**
 * @brief Actualiza las coordenadas de r1 al agregarle r2, solo las actualiza no añade r2 a r1.
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 */
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

/**
 * @brief Busca en el nodo todos los rectángulos que intersectan a *rect.
 *
 * @param node p_node: Nodo donde buscar.
 * @param rect p_rect: Rectángulo a buscar.
 * @return Node** Lista de rectángulos que intersectan a *rect.
 */
Node* search(Node *node, Rectangle *rect) {

    Node *answer = (Node *) malloc(sizeof(Node *));
    answer->rectArray = (Rectangle **)malloc(MAX_SIZE * sizeof(Rectangle **));
    Node *aux = node;

    Rectangle *auxRect = *(aux->rectArray);

    while (auxRect != NULL) {
        // Agregar rectángulo que intersecta
        if (intersect(auxRect, rect))
            *(answer->rectArray) = auxRect;

        // Avanzar en el array
        auxRect = *(aux->rectArray++);
    }

    return answer;
}

/**
 * @brief Inserta un rectángulo al nodo dado.
 *
 * @param node p_node: Nodo donde insertar rectángulo.
 * @param r p_r: Rectángulo a insertar.
 */
void insert ( Node *node , Rectangle *r, Node* header ) {

    if ((node->rectArray)[0]->hijo != NULL) {
        int minMBR = INT_MAX;
        Rectangle * aux;
        for(int i = 0; i < node->size ; i++) {
            int this_mbr = MBR(node->rectArray[i],r);
            if ( this_mbr < minMBR ) {
                minMBR = this_mbr;
                aux = node->rectArray[i];
            }

        }
        //cerrar Nodo;
        //Abrir nodo de aux.
        // insert( nodo de aux, r, header);
    }
    else {
        node->size++;
        node->rectArray[node->size] = r;
        if (node->size == PICO) {
            header->rectArray=controlOverFlow(header, r);
        }
    }
}
Rectangle **controlOverFlow(Node *header, Rectangle * r) {

}
Rectangle ** linearSplit(Node *header, Rectangle *r){
    if ((header->rectArray)[0]->hijo != NULL) {
        int minMBR = INT_MAX;
        Rectangle * aux;
        for(int i = 0; i < header->size ; i++) {
            int this_mbr = MBR(header->rectArray[i],r);
            if ( this_mbr < minMBR ) {
                minMBR = this_mbr;
                aux = header->rectArray[i];
            }

        }
        //cerrar Nodo;
        //Abrir nodo de aux.
        // Rectangle **newRectangles = linearSplit( nodo de aux, r);
        /*while (*newRectangles!=Null){
         *  header->rectArray[header->size++] = *newRectangles;
         *
        */
    }
    if ( header -> size == PICO ){
        int w, h;
        int *bounds = calculateBounds(header);
        w = bounds[0];
        h = bounds[1];
        Rectangle *rectangle1;
        Rectangle *rectangle2;
        Rectangle ** rectangles = calculateXRectangles(header,w,h);
        float width = (rectangles[1]-rectangles[0])/w;
        float heigth = (rectangles[3]-rectangles[2])/h;
        rectangle1 = width < heigth ? rectangles[3] : rectangles[1];
        rectangle2 = width < heigth ? rectangles[2] : rectangles[0];
        Rectangle **arrayRect = makeRandom(*header);
        Node *noder1 = createNode();
        Node *noder2 = createNode();
        for ( int i = 0; i < header->size ; i++) {
            if (arrayRect[i] != rectangle1 || arrayRect[i] != rectangle2) {
                if (header->size - i + noder1->size == m) {
                    noder1->rectArray[noder1->size] = arrayRect[i];
                    noder1->size++;
                    continue;
                }
                if (header->size - i + noder2->size == m) {
                    noder2->rectArray[noder2->size] = arrayRect[i];
                    noder2->size++;
                    continue;
                }
                if(MBR(rectangle1, arrayRect[i])<MBR(rectangle2, arrayRect[i])){
                    noder1->rectArray[noder1->size] = arrayRect[i];
                    noder1->size++;
                    mergeRectangle(rectangle1,arrayRect[i]);
                }
                else{
                    noder2->rectArray[noder2->size] = arrayRect[i];
                    noder2->size++;
                    mergeRectangle(rectangle2,arrayRect[i]);
                }

            }
        }
        rectangle1->hijo = noder1;
        rectangle2->hijo = noder2;
        free(header);
        return {rectangle1,rectangle2}[2];



    }
    return header->rectArray;
}

Rectangle **makeRandom(Node pNode) {
    int times = pNode.size * 5;
    int r1,r2;
    while (times > 0){
        r1 = rand()%pNode.size;
        r2 = rand()%pNode.size;
        Rectangle * r = pNode.rectArray[r1];
        pNode.rectArray[r1] = pNode.rectArray[r2];
        pNode.rectArray[r2] = r;
        times--;
    }
    return pNode.rectArray;
}

Rectangle **calculateXRectangles(Node *pNode, int w, int h) {
    int min_x = 0, max_x = INT_MAX, min_y = 0, max_y = INT_MAX;
    Rectangle* minX,*maxX,*minY,*maxY;
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
    Rectangle * array[4] = {minX,maxX,minY,maxY};
    return array;
}

int *calculateBounds(Node *pNode) {
    int max_x = 0, min_x = INT_MAX, min_y = INT_MAX, max_y = 0;
    for ( int i = 0; i < pNode->size; i++ ){
        Rectangle *r = pNode->rectArray[i];
        max_x = max_x > r->x + r->w ? max_x : r->x + r->w;
        min_x = min_x < r->x ? min_x : r->x;
        max_y = max_y > r->y + r->h ? max_y : r->y + r->h;
        min_y = min_y < r->y ? min_y : r->y;
    }
    int array[2] = {max_x-min_x, max_y-min_y};
    return array;
}

