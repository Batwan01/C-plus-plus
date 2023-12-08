#include <iostream>
using namespace std;

class Box {
private:
	double length;
	double width;
	double height;
	int num;
	static int count;
public:
	Box(int l = 0, int w = 0, int h = 0) : length(l), width(w), height(h) { count++; num = count; }

	double getVolume(void) {
		return length * width * height;
	}

	Box operator+(const Box& a);

	bool operator==(const Box& a) {
		return getVolume() == (a.height*a.length*a.width);
	}

	void print() {
		cout << "���� #" << num << endl << "������ ����: " << length << endl << "������ �ʺ�: " << width << endl << "������ ����: " << height << endl << "������ ����: " << getVolume() << endl << endl;
	}
};

int Box::count = 0;

Box Box::operator+(const Box& a) {
	return Box(this->length + a.length, this->height + a.height, this->width + a.width);
}

int main() {
	Box a(10, 10, 10), b(20, 20, 20);
	a.print(); b.print();

	cout << (a == b);
}