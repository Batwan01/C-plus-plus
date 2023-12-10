#include <iostream>
#include <vector>
using namespace std;

class Student {
	string name;
public:
	Student(string name = "") :name{ name } {}
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class MyClass {
	string className;
	Student* p;
	int size;
public:
	void setclassname(string n) { this->className = n; }
	MyClass(Student* st, string name, int s) { p = st; className = name; size = s; }
	void print() {
		for (int i = 0; i < size; i++) {
			cout << i + 1 << " : " << p[i].getName() << endl;
		}
	}
};

int main() {
	Student* st = new Student[3]{ Student("jiwan"), Student("jiw"), Student("asd") };
	MyClass clas(st, "specail", 3);
	clas.print();
	delete[] st;
}