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
		cout << "�̸� : " << name << endl << "���� : " << age << endl << endl;
	}
};

class Student:public Human {
	string major;
public:
	void print() {
		cout << "�̸� : " << name << endl << "���� : " << age << endl << "���� : " << major << endl << endl;
	}
	Student(string name, int age, string major) :Human(name, age), major{ major } {}
};

int main() {
	Student h1("����", 18, "��"), h2("����", 21, "��"), h3("���", 50, "��");
	h1.print();
	h1.Human::print();
	h2.print();
	h3.print();
}