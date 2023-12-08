#include <iostream>
using namespace std;

class Box {
private:
	double length;
	double width;
	double height;
	static int count;
public:
	Box(double l = 2.0, double w = 2.0, double h = 2.0) {
		length = l;
		width = w;
		height = h;
		count++;
	}
	double volume() {
		return length * width * height;
	}
	int getcount() {
		return count;
	}
};

int Box::count = 0;

int main() {
	Box box1;
	Box box2;
	cout << "ÀüÃ¼ °´Ã¼ ¼ö : " << box2.getcount();
}