#include <iostream>
using namespace std;

class Complex {
public:
	double r;
	double i;
	void print();
};

void Complex::print() {
	if (i < 0)
		cout << r << " - " << i * -1 << "i" << endl;
	else
		cout << r << " + " << i << "i" << endl;
}

int main() {
	Complex obj1, obj2;
	obj1.r = 5;
	obj1.i = 3;
	obj1.print();
	obj2.r = 3;
	obj2.i = -4;
	obj2.print();
}