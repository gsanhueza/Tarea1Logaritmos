class RTree
{
public:
    RTree(Rectangle rect);
    RTree* search(Rectangle rect);
    void insert(Rectangle rect);
    void print();

private:
    Rectangle *mbr;
    RTree *left;
    RTree *right;

};
