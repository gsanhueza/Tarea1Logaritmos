#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*****************************************************
 * Inicialización
 *****************************************************/

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
void insert ( Node *node , Rectangle *r ) {
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
        insert( visitor->hijo, r);
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
