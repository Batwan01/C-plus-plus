#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

class Complex {
private:
	double real, imag;
public:
	Complex(double r, double i) : real(r), imag(i) {}
	Complex operator+(const Complex& v1);
	Complex operator-(const Complex& v1);
	void print() { cout << "(" << real << "+" << imag << "i)"; }
	string print1() { return "("+ to_string(real) + " + " + to_string(imag) + "i)"; }
};

/*Complex Complex::operator+(const Complex& v1) {
	Complex c(0,0);
	c.real = this->real + v1.real;
	c.imag = this->imag + v1.imag;
	return c;
}*/

Complex Complex::operator+(const Complex& v1) {
	Complex c(0, 0);
	c.real = this->real + v1.real;
	c.imag = this->imag + v1.imag;
	return c;
}

int main() {
	Complex a(1.0, 7.0), b(3.0, 8.0);
	Complex c = a + b;
	cout << fixed << setprecision(1) << a.print1() << " + " << b.print1() << " = " << c.print1();

}