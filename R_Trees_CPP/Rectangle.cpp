#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h)
{
    this->posX = x;
    this->posY = y;
    this->width = w;
    this->height = h;
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

