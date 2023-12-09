#include <iostream>
using namespace std;

class Shape {
	int x, y;
	virtual double getArea() = 0;
	static int count;
public:
	Shape(int x, int y) :x{ x }, y{ y } { count++; }
	virtual void print() = 0;
	int getcount() { return count; }
};
int Shape::count = 0;

class Rect :public Shape {
	int width, height;
	int num;
public:
	Rect(int x, int y, int w, int h) :Shape(x, y), width{ w }, height{ h } { num = getcount(); }
	double getArea() { return width * height; }
	void print() { cout << "도형 #" << num << "의 면적:" << getArea() << endl; }
};

class Circle : public Shape {
	int radius;
	int num;
public:
	Circle(int x, int y, int r) :Shape(x, y), radius{ r } { num = getcount(); }
	double getArea() { return radius * radius * 3.14; }
	void print() { cout << "도형 #" << num << "의 면적:" << getArea() << endl; }
};

class Triangle : public Shape {
	int width, height;
	int num;
public:
	Triangle(int x, int y, int w, int h) :Shape(x, y), width{ w }, height{ h } { num = getcount(); }
	double getArea() { return width* height / 2; }
	void print() { cout << "도형 #" << num << "의 면적:" << getArea() << endl; }
};

int main() {
	Shape* rect = new Rect(10,20, 10, 20);
	Shape* circle = new Circle(10,30, 15);
	Shape* triangle = new Triangle(10,40, 10, 40);
	rect->print();
	circle->print();
	triangle->print();
}