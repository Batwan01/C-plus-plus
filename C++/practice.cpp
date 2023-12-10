#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Complex {
private:
	double real, imag;
public:
	Complex(double r=0, double i=0):real(r), imag(i) {}
	//friend Complex operator+(const Complex &p1, const Complex& p2);
	//friend Complex operator-(const Complex &p1, const Complex& p2);

	Complex operator+(const Complex& p);
	Complex operator-(const Complex& p);
	void set(double r, double i) { real = r; imag = i; }

	void print() {
		cout << "real : " << real << endl << "imag : " << imag << endl;
	}

	string printi() {
		return "(" + to_string((int)real) + "+" + to_string((int)imag) + "i)";
	}

	Complex &operator+=(const Complex &p) {
		this->real += p.real;
		this->imag += p.imag;
		return *this;
	}
	Complex& operator-=(const Complex& p);
	operator double();

	friend ostream& operator<<(ostream& os, const Complex& p) {
		os << "real : " << p.real << endl << "imag : " << p.imag << endl;
		return os;
	}

	friend istream& operator>>(istream& in, Complex& p) {
		in >> p.real >> p.imag;
		return in;
	}
	bool operator==(Complex& p) {
		return (this->real == p.real && this->imag == p.imag);
	}
	bool operator!=(Complex& p);
};

bool Complex::operator!=(Complex& p) {
	return !(*this == p);
}

Complex::operator double() {
	return sqrt(real * real + imag * imag);
}

Complex &Complex::operator-=(const Complex& p) {
	this->real -= p.real;
	this->imag -= p.imag;
	return *this;
}
Complex Complex::operator+(const Complex& p) {
	Complex a;
	a.real = this->real + p.real;
	a.imag = this->imag + p.imag;
	return a;
}

/*Complex operator+(const Complex& p1, const Complex &p2) {
	Complex a;
	a.real = p1.real + p2.real;
	a.imag = p1.imag + p2.imag;
	return a;
}*/

/*Complex operator+(const Complex& p1, const Complex &p2) {
	Complex a;
	a.real = p1.real - p2.real;
	a.imag = p1.imag - p2.imag;
	return a;
}*/

Complex Complex::operator-(const Complex& p) {
	Complex a;
	a.real = this->real - p.real;
	a.imag = this->imag - p.imag;
	return a;
}

int main() {
	Complex a(10, 20), b(20, 10);
	Complex c = a + b;
	c.print();

	a.set(1.0, 7.0);
	b.set(3.0, 8.0);
	cout << a.printi() << " + " << b.printi() << " = " << (a + b).printi() << endl;
	
	cout << "3번 : " << endl;
	a.operator+(b).print();

	cout << "4번 : " << endl;
	(a += b).print();
	(a -= b).print();

	cout << endl << "5번" << endl;
	a.print();
	b.print();

	cout << (double)a << endl; //6번

	cout << a;
	cin >> a;
	cout << a;

	cout << (a == b);
	cout << (a != b);

}