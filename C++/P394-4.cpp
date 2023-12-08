#include <iostream>
using namespace std;

class Point {
private:
	double xval, yval;
public:
	Point(double x = 0.0, double y = 0.0) {
		this->xval = x;
		this->yval = y;
	}
	double getX() { return xval; }
	double getY() { return yval; }

	void swap(Point& p1, Point& p2) {
		int x, y;
		x = p1.xval;
		y = p1.yval;

		p1.xval = p2.xval;
		p1.yval = p2.yval;

		p2.xval = x;
		p2.yval = y;
	}

	void print() {
		cout << "(" << getX() << "," << getY() << ")" << endl;
	}
};

int main() {
	Point p1(1.2, -2.8);
	Point p2(3, 6);
	p1.print();
	p2.print();

	swap(p1, p2);
	p1.print();
	p2.print();
}