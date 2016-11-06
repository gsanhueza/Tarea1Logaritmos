#ifndef _NODE_H_
#define _NODE_H_

#include <string>
class Rectangle;

class Node
{
public:
    Node();
    ~Node();

public:
    Node *search(Rectangle *rect);
    void insert(Rectangle *rect);

    void loadFromDisk(std::string filename);
    std::string writeToDisk(Node *data);

    void insertRectToNode(Rectangle *r);
    bool intersect(Rectangle *r1, Rectangle *r2);
    int MBR(Rectangle *r1, Rectangle *r2);

    Rectangle** getRectArray();
    int getSize();

private:
    Rectangle **rectArray;
    int size;
};

#endif
