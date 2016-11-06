#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

static const int MAX_SIZE = 4096;
static const int MIN_SIZE = 1638;
static const int PICO = 127;

#include <string>
class Node;

class Rectangle
{
public:
    Rectangle(int x, int y, int w, int h, std::string id);
    ~Rectangle();

public:
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    std::string getId();
    Node *getHijo();

private:
    int posX;
    int posY;
    int width;
    int height;
    std::string id;
    Node *hijo;
};

#endif
