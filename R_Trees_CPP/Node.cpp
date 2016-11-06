#include "Node.h"
#include <fstream>

Node::Node()
{
    this->size = 0;
    this->rectArray = (Rectangle **)malloc(sizeof(Rectangle **));
}

Node::~Node()
{
}

void Node::loadFromDisk(std::string filename)
{
    // TODO loadFromDisk
}

std::string Node::writeToDisk(Node* data)
{
    // TODO writeToDisk
    return NULL;
}

void Node::insertRectToNode(Rectangle* r)
{
    int i = 0;
    Rectangle **header = this->rectArray;

    while (i++ < this->size)
        this->rectArray++;

    *(this->rectArray) = r;
    this->size++;
    this->rectArray = header;
}

bool Node::intersect(Rectangle* r1, Rectangle* r2)
{
    // TODO intersect
    return false;
}

int Node::MBR(Rectangle* r1, Rectangle* r2)
{
    // TODO MBR
    return -1;
}

int Node::getSize()
{
    return this->size;
}

Rectangle ** Node::getRectArray()
{
    return this->rectArray;
}

void Node::insert(Rectangle* rect)
{
    // TODO insert
}

Node * Node::search(Rectangle* rect)
{
    // TODO search
    return NULL;
}
