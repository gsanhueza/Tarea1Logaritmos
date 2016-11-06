#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#define MAX_SIZE 4096
#define MIN_SIZE 1638
#define TRUE 1
#define FALSE 0
#define M 120
#define m 52
#define NUM_RANDOM_RECTS 1000;

static int count = 0;

/*****************************************************
 * Estructuras
 *****************************************************/

/**
 * @brief Estructura Rectangle.
 *
 */
typedef struct rectangle{
    int x;
    int y;
    int h;
    int w;
    char *id;
    char *hijo;
} Rectangle;

/**
 * @brief Estructura Node.
 *
 */
typedef struct node {
    Rectangle** rectArray;
    int size;
    char* this_node_filename;
} Node;

/*****************************************************
 * Funciones
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
Rectangle* createRectangle(int x, int y, int w, int h, int id);

/**
 * @brief Crea un nodo con un arreglo de rectángulos como información interna.
 *
 * @return Node* El nodo creado.
 */
Node* createNode();

/**
 * @brief Carga un archivo del disco.
 *
 * @param filename p_filename: Nombre del archivo de disco.
 * @return Node* Nodo representante.
 */
Node* loadFromDisk(char *filename);

/**
 * @brief Escribe los datos de un nodo a disco.
 *
 * @param data p_data: Datos a escribir.
 * @return char* Nombre del archivo escrito a disco.
 */
char* writeToDisk(Node *data);

/**
 * @brief Inserta un rectángulo al nodo dado.
 *
 * @param n p_n: Nodo donde insertar.
 * @param r p_r: Rectángulo a insertar.
 */
void insertRectToNode(Node *n, Rectangle *r);

/**
 * @brief Retorna un "booleano" que dice si los dos rectángulos se intersectan.
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 * @return int TRUE o FALSE
 */
int intersect (Rectangle *r1, Rectangle *r2);

/**
 * @brief Actualiza las coordenadas de r1 al agregarle r2, solo las actualiza no añade r2 a r1.
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 */
void mergeRectangle(Rectangle *r1, Rectangle *r2);

/**
 * @brief Calcula la nueva Area si se agrega r2 a r1.
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 * @return int La diferencia de las Areas.
 */
int MBR(Rectangle *r1, Rectangle *r2);

/**
 * @brief Imprime información de un rectángulo.
 *
 * @param r p_r: Rectángulo recibido.
 */
void printRectangle(Rectangle *r);

/**
 * @brief Inserta un rectángulo al nodo dado.
 *
 * @param nodeName p_nodeName: Nodo donde insertar rectángulo.
 * @param r p_r: Rectángulo a insertar.
 */
void insert( char *nodeName , Rectangle *r );

/**
 * @brief Busca en el nodo todos los rectángulos que intersectan a *rect.
 *
 * @param nodeName p_nodeName: Nodo donde buscar.
 * @param rect p_rect: Rectángulo a buscar.
 * @return Node** Lista de rectángulos que intersectan a *rect.
 */
Node *search(char *nodeName, Rectangle *rect);


/**
 * @brief Control de overflow usando Linear Split.
 *
 * @param header p_header: Nodo a dividir
 * @return Rectangle** Lista de nodos divididos.
 */
Rectangle ** linearSplit(Node *header);

Rectangle ** controlOverFlow(Node *header, Rectangle *r);
int *calculateBounds(Node *pNode);
Rectangle **calculateXRectangles(Node *pNode);
Rectangle **makeRandom(Node pNode);

#endif
