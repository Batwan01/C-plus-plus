#include <iostream>
using namespace std;

class Computer{
public:
	string name;
	int RAM;
	double cpu_speed;

	void setComputer(string name, int RAM,double cpu_speed) {
		this->name = name;
		this->RAM = RAM;
		this->cpu_speed = cpu_speed;
	}

	void print() {
		cout << "이름: " << name << endl;
		cout << "RAM: " << RAM << endl;
		cout << "CPU 속도: " << cpu_speed << endl;
	}
};

int main() {
	Computer obj;
	obj.setComputer("오피스 컴퓨터", 8, 4.2);
	obj.print();
	return 0;
}