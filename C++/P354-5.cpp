#include <iostream>
#include <string>
using namespace std;

class Student {
	string name;
public:
	Student(string name = "") : name(name) {};
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class Myclass {
	string className;
	Student* p;
	int size;
public:
	Myclass(string n, Student *pp, int s) { className = n; p = pp; size = s; }
	int getsize() { return size; }
	string getclassName() { return this->className; }

};
int main() {
	Student *student = new Student[3];
	student[0].setName("홍길동");
	student[1].setName("김철수");
	student[2].setName("최자영");

	Myclass* special = new Myclass("special", student, 3);
	cout << "학급 " << special->getclassName() << "의 학생들은 다음과 같다." << endl;
	for (int i = 0; i < special->getsize(); i++) {
		cout << "학생 #" << i+1 << ": " << student[i].getName() << endl;
	}

	delete[] student;
}