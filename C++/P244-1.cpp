#include <iostream>
using namespace std;

class Point {
public:
	int x, y;
public:
	Point(int x, int y);
	~Point();
	void print();
};

Point::Point(int x1=0, int y2=0) :x{ x1 }, y{ y2 } 
{}

Point::~Point() {

}

void Point::print() {
	cout << x << endl;
	cout << y << endl;
}

int main() {
	Point a;
	a.print();
	Point b{ 100,200 };
	b.print();

	system("pause");
	return 0;
}