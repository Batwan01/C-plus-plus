#include <iostream>
using namespace std;

class Employee {
	string name;
	int salary;
public:
	Employee(string name, int salary):name{name}, salary{salary} {}
	
	void setname(string name) { this->name = name; }
	void setsalary(int salary) { this->salary = salary; }
	int getsalary() { return salary; }
	string getname() { return name; }
	void computeSalary() {
		cout << "월급" << salary << endl;
	}
};

class Manager :public Employee {
	int bonus;
public:
	Manager(string name, int salary, int bonus): Employee(name, salary), bonus{bonus} {}

	void setbonus(int bonus) { this->bonus = bonus; }

	void computeSalary() {
		cout << "이름: " << getname() << endl << "월급: " << getsalary() << endl << "보너스: " << bonus << endl << "전체 급여: " << getsalary() + bonus << endl;
	}
};

int main() {
	Manager m("김철수", 200, 100);
	m.computeSalary();
}