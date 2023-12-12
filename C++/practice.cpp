#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Rect {
	int width, height;
public:
	int getArea() { return width * height; }
	int getPerimeter() { return 2 * width + 2 * height; }
	int getwidth() { return width; }
	int getheight() { return height; }
	void setwidth(int width) { this->width = width; }
	void setheight(int height) { this->height = height; }
};

bool is_equal(Rect &r1, Rect& r2) {
	return (r1.getheight() == r2.getheight() && r1.getwidth() == r2.getwidth());
}

int main() {
	Rect r1, r2;
	r1.setheight(5);
	r1.setwidth(4);
	r2.setheight(5);
	r2.setwidth(4);
	cout << r1.getArea() << endl << r1.getPerimeter() << is_equal(r1,r2);

}