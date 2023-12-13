#include <iostream>
#include <vector>
#include <string>
using namespace std;
//P351-11
/*class Rect {
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

}*/
//P353-1
/*int main() {
	int n;
	cin >> n;
	int* p = new int[n];

	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < n; i++)
		cout << p[i];
}*/
//P354-5
/*class Student {
	string name;
public:
	Student(string name = "") : name(name) {}
	string getname() { return name; }
	void setName(string name) { this->name = name; }
};

class MyClass {
	string className;
	Student* p;
	int size;
public:
	void setStudent(Student* s) { p = s; }
	MyClass(string name) : className(name) {}
	string studentname(int i) {	return p[i].getname();	}
};

int main() {
	Student* student = new Student[3]{Student("jiwan"), Student("jiho"), Student("jiwoo")};

	MyClass *name= new MyClass("special");
	name->setStudent(student);

	cout << name->studentname(0) << endl << name->studentname(1) << endl << name->studentname(2);
}*/
//P393-2
/*class Line {
public:
	int getLength(void);
	Line(int len);
	Line(Line& a);
	~Line() {
		cout << "�Ҹ��� ����" << endl;
	}
private:
	int* ptr;
};

Line::Line(int len) { 
	cout << "�Ϲ� ������" << endl;
	ptr = new int;
	*ptr = len; 
}

Line::Line(Line& a) {
	cout << "���� ������" << endl;

	ptr = new int;
	*ptr = a.getLength();
}

int Line::getLength() {
	return *ptr;
}


int main() {
	Line l(10);
	Line l1(l);

	cout << l.getLength() << endl << l1.getLength();
}*/
//P394-4
/*class Point {
private:
	double xval, yval;
public:
	Point(double x = 0.0, double y = 0.0) :xval(x), yval(y) {}
	double getX() { return xval; }
	double getY() { return yval; }
	void setX(double x) { xval = x; }
	void setY(double y) { yval = y; }
	void print() { cout << xval << "," << yval << endl; }
};

void swap(Point& p1, Point& p2) {
	double x = p1.getX(), y = p1.getY();

	p1.setX(p2.getX());
	p1.setY(p2.getY());

	p2.setX(x);
	p2.setY(y);
}

int main() {
	Point p1(1.2, -2.8), p2(3, 6);
	p1.print(); p2.print();
	swap(p1, p2);
	p1.print(); p2.print();
}*/
//P395-5
/*class Box {
private:
	double length;
	double width;
	double height;
	static int count;
public:
	Box(double l = 2.0, double w = 2.0, double h = 2.0) {
		count++;
		length = l;
		width = w;
		height = h;
	}
	double Volume() {
		return length * width * height;
	}
	int getCount() { return count; }
};

int Box::count = 0;

int main() {
	Box(5, 5, 5);
	cout << Box(5, 5, 5).getCount();
}*/
//P431-8
/*class Complex {
private:
	double real, imag;
public:
	Complex(double r=0, double i=0):real(r), imag(i) {}
	
	Complex operator+(const Complex &p) {
		Complex n;
		n.real = this->real + p.real;
		n.imag = this->imag + p.imag;
		return n;
	}
	Complex operator-(const Complex& p);
	
	void clear() { real = 0; imag = 0; }
	void print() { cout << "real : " << real << endl << "imag : " << imag << endl; }
	string printi() { return "(" + to_string((int)real) + "+" + to_string((int)imag) + "i)"; }

	Complex& operator+=(const Complex& p) {
		this->real += p.real;
		this->imag += p.imag;
		return *this;
	}
	Complex operator-=(const Complex& p);
	operator double();
	friend istream& operator>>(istream &in, Complex& p) {
		in >> p.real >> p.imag;
		return in;
	}

	friend ostream& operator<<(ostream& os, Complex& p);
	bool operator==(const Complex& p);
	bool operator!=(const Complex& p) { return !(*this != p); }
};

bool Complex::operator==(const Complex& p) {
	return (this->real == p.real && this->imag == p.imag);
}
ostream& operator<<(ostream& os, Complex& p) {
	os << "real : " << p.real << endl << "imag : " << p.imag << endl;
	return os;
}
Complex operator-(const Complex& p) {
	friend
}

Complex::operator double() {
	return 0;
}

Complex Complex::operator-=(const Complex& p) {
	this->real -= p.real;
	this->imag -= p.imag;
	return *this;
}

Complex Complex::operator-(const Complex& p) {
	Complex n;
	n.real = this->real - p.real;
	n.imag = this->imag - p.imag;
	return n;
}


int main() {
	Complex a(1.0, 7.0), b(3.0, 8.0);
	cout << "���� ��" << endl << "a-------------" << endl;
	a.print();
	cout << "b-------------" << endl;
	b.print();
	Complex c = a + b;
	cout << "-------------" << endl << a.printi() << "+" << b.printi() << "=" << c.printi() << endl;
	c.clear();
	c = a.operator+(b);
	c.print();
	a += b;
	a.print();
	a -= b;
	a.print();
	cin >> a >> b;
	cout << "a-------------" << endl << a << "b-------------" << endl <<  b << "-------------" << endl;
	if (a == b)
		cout << "True";
	else
		cout << "False";

}*/
//P433-1
/*class Box {
private:
	double length;
	double width;
	double height;
	static int count;
	int num;
public:
	Box(int l = 0, int w = 0, int h = 0) :length(l), width(w), height(h) { count++; num = count; }
	double getVolume(void) { return length * width * height; }

	Box operator+(const Box& p) {
		Box n;
		n.length = this->length + p.length;
		n.width = this->width + p.width;
		n.height = this->height + p.height;
		return n;
	}
	void print();

	bool operator==(const Box& p) {
		return (this->length == p.length && this->width == width && this->height == p.height);
	}
	bool operator<(const Box& p);

};

bool Box::operator<(const Box& p) {
	return this->getVolume() < (p.length * p.height * p.width);
}

void Box::print() {
	cout << "���� #" << num << endl;
	cout << "������ ����: " << length << endl;
	cout << "������ �ʺ�: " << width << endl;
	cout << "������ ����: " << height << endl;
	cout << "������ ����: " << getVolume() << endl << endl;
}

int Box::count = 0;

int main() {
	Box a(10, 10, 10), b(20, 20, 20), c, d(10, 10, 10);
	c = a + b;
	a.print(); b.print(); c.print();
	if (a == d)
		cout << "True";
	else
		cout << "False";

	if (a < b)
		cout << "True";
	else
		cout << "False";

}*/
//P473-8
/*class Human {
	string name;
	int age;
public:
	Human(string name, int age):name(name), age(age) {}
	string getname() { return name; }
	int getage() { return age; }
	void setname(string name) { this->name = name; }
	void setage(int age) { this->age = age; }
	void print() { cout << "name : " << name << endl << "age : " << age << endl; }

};

class Student : public Human {
	string major;
public:
	Student(string name, int age, string major): Human(name, age), major(major) {}
	void print() {
		cout << "name : " << getname() << endl << "age : " << getage() << endl << "���� : " << major << endl;
	}
};
int main() {
	Human* human = new Human[3]{ Human("����",18), Human("����", 21), Human("���", 50) };
	Human* hu[3];
	hu[0] = new Human("���", 12);
	hu[1] = new Human("����", 23);
	hu[2] = new Human("���", 23);
	for (int i = 0; i < 3; i++)
		human[i].print();

	for (int i = 0; i < 3; i++)
		hu[i]->print();

	Student st("��", 2, "�İ�");
	st.print();
}*/
class Employee {
protected:
	string name;
	int salary;
public:
	Employee(string name, int salary) :name(name), salary(salary) { cout << "Sad"; }
	int computSalarys() { return salary; }
};

class Manager : public Employee {
	int bonus;
public:
	Manager(string name, int salary, int bonus) : Employee(name, salary), bonus(bonus) { cout << "sad"; }
	int computSalary() { return computSalarys() + bonus; }
	void print() { cout << "�̸�: " << this->name << endl << "����: " << this->salary << endl << "���ʽ�: " << bonus << endl << "��ü �޿�: " << computSalary() << endl; }
};

int main() {
	Manager m("��ö��", 200, 100);
	m.print();
}