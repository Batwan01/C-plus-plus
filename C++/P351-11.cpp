#include <iostream>
#include <string>
using namespace std;

class Rect {
	int width, height;
public:
	Rect(int x, int y);
	double getArea();
	int getPerimeter();
	void print();
};

Rect::Rect(const int x, const int y) {
	this->width = x;
	this->height = y;
}

double Rect::getArea() {
	const int x = this->height;
	const int y = this->width;
	return x * y / 2;
}

void Rect::print() {
	cout << getArea() << endl;
	cout << getPerimeter();
}

int Rect::getPerimeter() {
	const int x = this->height;
	const int y = this->width;
	return (x * 2) + (y * 2);
}
int main() {
	Rect* p = new Rect(3, 4);
	(*p).print();
	return 0;

}