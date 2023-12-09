#include <iostream>
using namespace std;

int main() {
	cout << "나이를 입력하시오: ";
	int age;
	try {
		cin >> age;
		if (age < 0)
			throw age;
		cout << "나이는 : " << age;
	}
	catch (int e) {
		cout << "오류: 양수를 입력하시오.";
	}
}