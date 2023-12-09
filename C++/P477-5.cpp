#include <iostream>
using namespace std;

class Shape {
	int x, y;
	string color;
	double getArea();
public:
	Shape(int x, int y, string color): x{x}, y{y}, color{color} {}
	void setx(int xx) { x = xx; }
	void sety(int yy) { y = yy; }
};

class Circle :public Shape {
	int length;
public:
	Circle(int x, int y, string color, int length) : Shape(x, y, color), length{ length } {} 

	int getArea() {
		return length * length * 3.14;
	}
};

int main() {
	Circle c(5, 4, "blue", 5);
	cout << "원의 면적: " << c.getArea();
}