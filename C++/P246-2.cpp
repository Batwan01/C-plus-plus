#include <iostream>
using namespace std;

class Airplane {
private:
	string name;
	int capacity;
	int speed;
	static int num;
	int id;
public:
	void print() {
		cout << "비행기 #" << id << endl;
		cout << "비행기의 이름: " << name << endl;
		cout << "비행기의 용량: " << capacity << endl;
		cout << "비행기의 속도: " << speed << " Km/h" << endl << endl;
	}

	Airplane() {
		num++;
		id = num;
		name = "";
		capacity = 0;
		speed = 0;
	}

	Airplane(string input_name, int input_capacity, int input_speed) {
		name = input_name;
		capacity = input_capacity;
		speed = input_speed;
		num++;
		id = num;
	}
};

int Airplane::num = 0;

int main() {
	Airplane num1{ "보잉 787", 900, 300 };
	Airplane num2{ "에어버스 350", 400, 1000 };
	num1.print();
	num2.print();


	system("pause");
	return 0;
}