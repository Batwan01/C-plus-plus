#include <iostream>
using namespace std;

class Complex {
private:
	double r;
	double i;
public:
	Complex() { r = 0; i = 0; }

	Complex(double _r, double _i) {
		r = _r;
		i = _i;
	}
	void print() {
		if(i<0) cout << "(" << r << i << "i" << ")";
		else cout << "(" << r << "+" << i  << "i" << ")";
	}
	int get_r() { return r; }
	int get_i() { return i; }
};

void add(Complex A, Complex B) {
	cout << "=(" << A.get_r() + B.get_r() << A.get_i() + B.get_i() << "i)"<< endl;
}
int main() {
	Complex A{ 5, 3 };
	A.print();
	Complex B{ 3, -4 };
	cout << "+";
	B.print();
	add(A, B);

	system("pause");
	return 0;
}