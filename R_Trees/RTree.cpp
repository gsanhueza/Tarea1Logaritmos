#include <iostream>
#include "Rectangle.h"
#include "RTree.h"

using namespace std;

RTree::RTree()
{
    mbr = new Rectangle(25, 25, 25, 25);
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
