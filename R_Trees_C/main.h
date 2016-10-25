 
typedef struct rectangle{
    int x;
    int y;
    int h;
    int w;
} Rectangle;
 
typedef struct rtree{
    Rectangle rect;
    struct rtree **trees;
}RTree;

RTree* search(Rectangle rect);
int insert(Rectangle rect);
