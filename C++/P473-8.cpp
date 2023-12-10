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
		cout << "이름 : " << getname() << endl << "나이 : " << getage() << endl << "전공 : " << major << endl << endl;
	}
};
int main() {
	Student* h = new Student[3]{ Student("춘향", 18,"컴공") , Student("몽룡",21, "간호"), Student("사또", 50, "유교") };
	for (int i = 0; i < 3; i++)
		h[i].print();
}