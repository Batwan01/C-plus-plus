#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Human {
	string name;
	int age;
public:
	Human(string name, int age) :name(name), age(age) {}
	void setname(string name) { this->name = name; }
	void srtage(int age) { this->age = age; }
	string getname() { return name; }
	int getage() { return age; }
};

class Student :public Human {
	string major;
public:
	Student(string name, int age, string major) : Human(name, age), major(major) {}
	void print() {
		cout << "�̸� : " << getname() << endl << "���� : " << getage() << endl << "���� : " << major << endl << endl;
	}
};
int main() {
	Student* h = new Student[3]{ Student("����", 18,"�İ�") , Student("����",21, "��ȣ"), Student("���", 50, "����") };
	for (int i = 0; i < 3; i++)
		h[i].print();
}