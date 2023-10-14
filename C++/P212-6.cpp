#include <iostream>
using namespace std;

class Employee {
public:
	string name;
	int age;
	int salary;

	void set(string name, int age, int salary) {
		this->name = name;
		this->age = age;
		this->salary = salary;
	}
};

int main() {
	Employee obj;
	obj.set("±èÃ¶¼ö", 38, 200000);
	cout << obj.name << endl << obj.age << endl << obj.salary << endl;

	system("pause");
	return 0;
}