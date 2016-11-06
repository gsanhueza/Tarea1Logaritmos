#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(void) {
    Rectangle r(1, 2, 3, 4, "r");

    cout << r.getX() << endl;
    cout << r.getY() << endl;
    cout << r.getWidth() << endl;
    cout << r.getHeight() << endl;
    cout << endl;

    return 0;
}
