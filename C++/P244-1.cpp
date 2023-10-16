#include <iostream>
using namespace std;

class Point {
public:
	int x, y;
public:
	Point(int x, int y);
	~Point();
};

Point::Point(int x1=0, int y2=0) :x{ x1 }, y{ y2 } 
{}

Point::~Point() {

}

int main() {
	Point a;
	cout << a.x;
	Point b{ 10,20 };
	cout << b.x;



}