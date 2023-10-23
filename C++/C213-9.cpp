#include <iostream>
using namespace std;

class Triangle {
	int b, h;
public:
	Triangle(int x = 0, int y = 0) :b{ x }, h{y} {
	}

	int area() {
		return b * h / 2;
	}

	void print() {
		cout << "밑변이 " << b << "이고 높이가 " << h << "인 삼각형의 면적: " << area();
	}
};

int main() {
	Triangle obj(3, 4);
	obj.print();
}