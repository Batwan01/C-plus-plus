#include <iostream>
using namespace std;
class Shape {
    int x, y;
public:
    virtual double getArea() = 0;
    Shape(int x, int y) :x(x), y(y)
    { }
    Shape()
    { }
    int getX() { return x; }
    int getY() { return y; }
};

class Rect : public Shape {
public:
    Rect(int x, int y) : Shape(x, y)
    { }
    virtual double getArea() {
        return Shape::getX() * Shape::getY();
    }
};

class Circle : public Shape {
public:
    Circle(int x) : Shape(x, x)
    { }
    virtual double getArea() {
        return Shape::getX() * Shape::getX() * 3.14;
    }
};

class Triangle : public Shape {
public:
    Triangle(int x, int y) : Shape(x, y)
    { }
    virtual double getArea() {
        return Shape::getX() * Shape::getY() / 2;
    }
};
int main(void) {
    Shape** pp = new Shape * [3];
    pp[0] = new Rect(4, 5);
    cout << "도형 #0의 면적 : " << pp[0]->getArea() << endl;
    pp[1] = new Circle(4);
    cout << "도형 #1의 면적 : " << pp[1]->getArea() << endl;
    pp[2] = new Triangle(3, 4);
    cout << "도형 #2의 면적 : " << pp[2]->getArea() << endl;
    return 0;
}