#include <iostream>
using namespace std;

class Person {
private:
	string name;
	int snumber;
	int age;

public:
	Person();
	Person(string name, int snumber, int age) : name{name}, snumber{snumber}, age{age} {}
	~Person();
};

int main() {
	

	system("pause");
	return 0;
}