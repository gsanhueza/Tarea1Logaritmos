#include <iostream>
#include "Rectangle.h"
#include "RTree.h"

using namespace std;


RTree :: RTree(Rectangle rect) {
    mbr = new Rectangle(rect.getX(), rect.getY(), rect.getHeight(), rect.getWidth());

}

void RTree::insert(Rectangle rect)
{
    cout << "Insert no implementado" << endl;
}

RTree *RTree::search(Rectangle rect)
{
    cout << "Search no implementado" << endl;
    return NULL;
}

void RTree::print()
{
    cout << mbr->getHeight() << endl;
}
