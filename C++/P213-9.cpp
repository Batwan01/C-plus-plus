#include <iostream>
using namespace std;

class Triangle {
	int b, h;
public:
	void set(int a, int b);
	int area();
	void print();
};

void Triangle::set(int a, int b) {
	this->b = a;
	this->h = b;
}

int Triangle::area() {
	return b * h / 2;
}

void Triangle::print() {
	cout << "밑변이 " << b << "이고 높이가 " << h << "인 삼각현의 면적: " << area() << endl;
}

int main() {
	Triangle obj;
	obj.set(3, 4);
	obj.print();

	system("pause");
	return 0;
}