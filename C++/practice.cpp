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

int main() {
	Rect r1;
	r1.setheight(5);
	r1.setwidth(4);

	cout << r1.getArea() << endl << r1.getPerimeter();

}