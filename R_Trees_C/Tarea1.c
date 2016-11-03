<limits.h>
/* Return 0 si no intersectan, retorna 1 si intersectan.*/
int intersect (Rectangle *r1, Rectangle *r2){
  return r1->x <= r2->x + r2->w && r2->x <= r1->x + r1->w && r1->y <= r2->y + r2->h && r2->y <= r1->y + r1->h;

/* Calcula la nueva Area si se agrega r2 a r1. 
  Retorna la diferencia de las Areas.*/
int MBR(Rectangle *r1, Rectangle *r2) {
  int min_x = r1->x < r2->x ? r1->x : r2->x;
  int max_x = r1->x + r1->w > r2->x + r2->w ? r1->x + r1->w : r2->x + r2->w;
  int min_y = r1->y < r2->y ? r1->y : r2->y;
  int max_y = r1->x + r1->h > r2->x + r2->h ? r1->x + r1->h : r2->x + r2->h;
  int r1_area = ( r1->w ) * ( r1->h );
  int area = (max_x-min_x) * (max_y-min_y);
  return area - r1_area;
}

/* Actualiza las coordenadas de r1 al agregarle r2, solo las actualiza no añade r2 a r1.*/
void mergeRectangle(Rectangle *r1, Rectangle *r2) {
  int max_x = r1->x + r1->w > r2->x + r2->w ? r1->x + r1->w : r2->x + r2->w
  int max_y = r1->x + r1->h > r2->x + r2->h ? r1->x + r1->h : r2->x + r2->h;
  r1->x = r1->x < r2->x ? r1->x : r2->x;
  r1->y = r1->y < r2->y ? r1->y : r2->y;
  r1->w = max_x - r1->x ;
  r1->h = max_y - r1->y;  
}

void insertar ( Node *node , Rectangle *r ) {
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
    insertar( visitor->hijo, r);
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
