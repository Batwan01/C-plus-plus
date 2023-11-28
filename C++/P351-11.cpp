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

bool is_equal(Rect &r1, Rect &r2) {
	return r1.getArea() == r2.getArea(); 
}

int main() {
	Rect* p1 = new Rect(5, 4);
	Rect* p2 = new Rect(4, 5);
	p1->print();
	if (is_equal(*p1, *p2) == 1)
		cout << "°°À½";
	delete p1;
	return 0;

}