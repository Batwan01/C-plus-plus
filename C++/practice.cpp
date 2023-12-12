#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
/*int main() {
	int n;
	cin >> n;
	int* p = new int[n];

	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < n; i++)
		cout << p[i];
}*/
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

class Line {
public:
	int getLength(void);
	Line(int len);
	Line(Line& a);
	~Line() {
		cout << "家戈磊 积己" << endl;
	}
private:
	int* ptr;
};

Line::Line(int len) { 
	cout << "老馆 积己磊" << endl;
	ptr = new int;
	*ptr = len; 
}

Line::Line(Line& a) {
	cout << "汗荤 积己磊" << endl;

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
}