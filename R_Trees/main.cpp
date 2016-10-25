#include <iostream>
#include "Rectangle.h"
#include "RTree.h"

using namespace std;

int main(int argc, char **argv) {
    Rectangle r(1, 2, 3, 4);
    RTree *rtree;

    cout << r.getX() << endl;
    cout << r.getY() << endl;
    cout << r.getWidth() << endl;
    cout << r.getHeight() << endl;
    cout << endl;
    rtree->insert(r);
    rtree->search(r);

    return 0;
}
