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

int Rect::getPerimeter() {
	const int x = this->height;
	const int y = this->width;
	return (x * 2) + (y * 2);
}
int main() {
	Rect* p = new Rect(30, 40);
	return 0;

}