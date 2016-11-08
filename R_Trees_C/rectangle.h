#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#define BLOCK_SIZE 512

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
    int id;
    char *hijo;
} Rectangle;

/**
 * @brief Estructura Node.
 *
 */
typedef struct node {
    Rectangle** rectArray;
    int occupied;
    char *this_node_filename;
} Node;

/*****************************************************
 * Constantes dependientes
 *****************************************************/

#define M BLOCK_SIZE / sizeof(Rectangle)
#define m (40 * M / 100)

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
 * @brief Escribe los datos de un nodo a disco.
 *
 * @param data p_data: Datos a escribir.
 * @return char* Nombre del archivo escrito a disco.
 */
char* writeToDisk(Node *data);

/**
 * @brief Carga un archivo del disco.
 *
 * @param filename p_filename: Nombre del archivo de disco.
 * @return Node* Nodo representante.
 */
Node* loadFromDisk(char *filename);

/**
 * @brief Retorna un "booleano" que dice si los dos rectángulos se intersectan.
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 * @return int TRUE o FALSE
 */
int intersect (Rectangle *r1, Rectangle *r2);

/**
 * @brief Calcula la nueva Area si se agrega r2 a r1.
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 * @return int La diferencia de las Areas.
 */
int MBR(Rectangle *r1, Rectangle *r2);

/**
 * @brief Actualiza las coordenadas de r1 al agregarle r2. (Solo las actualiza, no añade r2 a r1).
 *
 * @param r1 p_r1: Rectángulo 1.
 * @param r2 p_r2: Rectángulo 2.
 */
void mergeRectangle(Rectangle *r1, Rectangle *r2);

/**
 * @brief Funcion auxiliar para quicksort, eje X.
 *
 * @param header p_header: Nodo recibido
 * @param inicio p_inicio: Número, puntero al inicio
 * @param final p_final: Número, puntero al final
 * @return int Pivote.
 */
int partitionX(Node *header,int inicio,int final);

/**
 * @brief Funcion auxiliar para quicksort, eje Y.
 *
 * @param header p_header: Nodo recibido
 * @param inicio p_inicio: Número, puntero al inicio
 * @param final p_final: Número, puntero al final
 * @return int Pivote.
 */
int partitionY(Node *header,int inicio,int final);

/**
 * @brief Quicksort para rectángulos.
 *
 * @param header p_header: Nodo recibido.
 * @param inicio p_inicio: Número, puntero al inicio.
 * @param final p_final: Número, puntero al inicio.
 * @param d p_d: Flag: 0 = Eje X, 1 = Eje Y.
 */
void quicksort(Node *header,int inicio,int final,int d);

/**
 * @brief Desordena el orden de los rectángulos de un nodo para aleatorizar el split.
 *
 * @param pNode p_pNode: Nodo con rectángulos.
 * @return Rectangle** El nodo con rectángulos desordenados.
 */
Rectangle **makeRandom(Node pNode);

/**
 * @brief Imprime información de un rectángulo.
 *
 * @param r p_r: Rectángulo recibido.
 */
void printRectangle(Rectangle *r);

/**
 * @brief Calcula los rectangulos con mayor bajo y menor alto en un arreglo para el eje X e Y.
 *
 * @param pNode p_pNode: Nodo con rectángulos.
 * @return Rectangle** Lista de los 4 rectángulos calculados.
 */
Rectangle **calculateXRectangles(Node *pNode);

/**
 * @brief Calcula el rectángulo más grande de todos los que están en el nodo.
 *
 * @param pNode p_pNode: Nodo con rectángulos.
 * @return int* Arreglo con alto y ancho del rectángulo más grande.
 */
int *calculateBounds(Node *pNode);

/**
 * @brief Retorna un número aleatorio acotado.
 *
 * @param max p_max: Cota superior del número aleatorio.
 * @return int El número aleatorio calculado.
 */
int randomNum(int max);

/**
 * @brief Crea n rectángulos distintos para experimentación.
 *
 * @param n p_n: Número de rectángulos a crear.
 * @return Rectangle** Arreglo de rectángulos creados.
 */
Rectangle ** bateriaRectangulos(int n);

/**
 * @brief Copia un arreglo de n elementos.
 *
 * @param pRectangle p_pRectangle: Arreglo de rectángulos
 * @param n p_n: Número de rectángulos a copiar
 * @return Rectangle** Copia del arreglo.
 */
Rectangle **copy(Rectangle **pRectangle, int n);

/**
 * @brief Busca en el nodo todos los rectángulos que intersectan a *rect.
 *
 * @param nodeName p_nodeName: Nodo donde buscar.
 * @param rect p_rect: Rectángulo a buscar.
 * @return Node* Nodo con rectángulos que intersectan a *rect.
 */
Node *search(char *nodeName, Rectangle *rect);

/**
 * @brief Inserción Linear Split con control de Overflow en Root.
 *
 * @param nodeName p_nodeName Nodo Root
 * @param r p_r: Rectángulo a insertar.
 */
void insertToRootLinear(char *nodeName, Rectangle *r);

/**
 * @brief Inserción Greene Split con control de Overflow en Root.
 *
 * @param nodeName p_nodeName: odo Root
 * @param r p_r: Rectángulo a insertar.
 */
void insertToRootGreene(char* nodeName, Rectangle *r);

/**
 * @brief Inserción Linear Split con control de Overflow en el resto de los nodos.
 *
 * @param nodeName p_nodeName Nodo
 * @param r p_r: Rectángulo a insertar.
 */
void insertLinear(char *nodeName , Rectangle *r);

/**
 * @brief Inserción Greene Split con control de Overflow en el resto de los nodos.
 *
 * @param nodeName p_nodeName Nodo
 * @param r p_r: Rectángulo a insertar.
 */
void insertGreene(char *nodeName, Rectangle *r);

/**
 * @brief Control de overflow usando Linear Split.
 *
 * @param header p_header: Nodo a dividir.
 */
Rectangle ** linearSplit(Node *header);

/**
 * @brief Control de overflow usando Greene Split.
 *
 * @param header p_header: Nodo a dividir.
 */
Rectangle ** greeneSplit(Node *header);

#endif

