#include <iostream>
using namespace std;

class Human {
protected:
	string name;
	int age;
public:
	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}

	void setname(string name) {
		this->name = name;
	}

	void setage(int age) {
		this->age = age;
	}

	void print() {
		cout << "이름 : " << name << endl << "나이 : " << age << endl << endl;
	}
};

class Student:public Human {
	string major;
public:
	void print() {
		cout << "이름 : " << name << endl << "나이 : " << age << endl << "전공 : " << major << endl << endl;
	}
	Student(string name, int age, string major) :Human(name, age), major{ major } {}
};

int main() {
	Student h1("춘향", 18, "컴"), h2("몽룡", 21, "소"), h3("사또", 50, "멀");
	h1.print();
	h1.Human::print();
	h2.print();
	h3.print();
}