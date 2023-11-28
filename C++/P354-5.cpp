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
	student[0].setName("ȫ�浿");
	student[1].setName("��ö��");
	student[2].setName("���ڿ�");

	Myclass* special = new Myclass("special", student, 3);
	cout << "�б� " << special->getclassName() << "�� �л����� ������ ����." << endl;
	for (int i = 0; i < special->getsize(); i++) {
		cout << "�л� #" << i+1 << ": " << student[i].getName() << endl;
	}

	delete[] student;
}