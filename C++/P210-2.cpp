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
		cout << "�̸�: " << name << endl;
		cout << "RAM: " << RAM << endl;
		cout << "CPU �ӵ�: " << cpu_speed << endl;
	}
};

int main() {
	Computer obj;
	obj.setComputer("���ǽ� ��ǻ��", 8, 4.2);
	obj.print();
	return 0;
}