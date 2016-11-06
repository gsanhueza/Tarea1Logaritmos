#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h, std::string id)
{
    this->posX = x;
    this->posY = y;
    this->width = w;
    this->height = h;
    this->id = id;
}

Rectangle::~Rectangle()
{
}

int Rectangle::getX()
{
    return this->posX;
}

int Rectangle::getY()
{
    return this->posY;
}

int Rectangle::getHeight()
{
    return this->height;
}

int Rectangle::getWidth()
{
    return this->width;
}

std::string Rectangle::getId()
{
    return this->id;
}

Node * Rectangle::getHijo()
{
    return this->hijo;
}


