class RTree
{
public:
    RTree* search(Rectangle rect);
    void insert(Rectangle rect);

private:
    Rectangle mbr;
    RTree *left;
    RTree *right;

};
