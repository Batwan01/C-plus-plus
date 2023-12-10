#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
	string name;
	int salary;
public:
	Employee(string name, int salary):name(name), salary(salary) {}
	void setname(string name) { this->name = name; }
	void setsalary(int salary) { this->salary = salary; }
	string getname() { return name; }
	int getsalary() { return salary; }
	int computeSalary() {
		return salary;
	}
};

class Manager :public Employee {
	int bonus;
public:
	Manager(string name, int salary, int bonus):Employee(name, salary), bonus(bonus) {}
	void setbonus(int bonus) { this->bonus = bonus; }
	int getbonus() { return bonus; }
	int computeSalary() {
		return getsalary() + bonus;
	}
};

int main() {
	Manager m1("±èÃ¶¼ö", 200, 100);
	cout << "ÀüÃ¼ ¿ù±Ş: " << m1.computeSalary();
}
