#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

class Complex {
private:
	double real, imag;
public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) {}
	//Complex(double r=0, double i=0) : real(r/2), imag(i) {} 5번
	friend Complex operator+(Complex& a, Complex& b); //7번
	//Complex operator+(const Complex& v1);
	Complex operator-(const Complex& v1);
	Complex operator+=(const Complex& v1);
	void print() { cout << "real : " << real << endl << "imag : " << imag << endl;; }
	string print1() { return "("+ to_string((int)real) + " + " + to_string((int)imag) + "i)"; }
	operator double() const;
	friend ostream& operator<<(ostream& os, const Complex& v);
	friend istream& operator>>(istream& in, Complex& v);
};

ostream& operator<<(ostream& os, const Complex& v) {
	os << "( " << v.real << " + " << v.imag << "i )";
	return os;
}

istream& operator>>(istream& in, Complex& v) {
	in >> v.real >> v.imag;
	return in;
}

Complex operator+(Complex& a, Complex& b) {
	return Complex(a.real + b.real, a.imag + b.imag); 
}

Complex::operator double() const {
	return sqrt(real * real + imag * imag);
}

Complex Complex::operator-(Complex const& a) {
	Complex v;
	v.real = this->real - a.real;
	v.imag = this->imag - a.imag;
	return v;
}

/*Complex Complex::operator+(const Complex& v1) {
	Complex c;
	c.real = this->real + v1.real;
	c.imag = this->imag + v1.imag;
	return c;
}*/

Complex Complex::operator+=(const Complex &v1) {
	this->real += v1.real;
	this->imag += v1.imag;
	return *this;
}

int main() {
	Complex a(1.0, 7.0), b(3.0, 8.0);
	Complex c = a + b;
	cout <<  a.print1() << " + " << b.print1() << " = " << c.print1() << endl; //2번
	//a.operator+(b).print(); //3번

	Complex d(2, 3); //4번
	d += a;
	d.print();

	Complex e = 6; //5번
	e.print();
	cout << (double)a;

	cout << a;
	
}