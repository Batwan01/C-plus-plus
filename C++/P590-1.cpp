#include <iostream>
using namespace std;

int main() {
	cout << "���̸� �Է��Ͻÿ�: ";
	int age;
	try {
		cin >> age;
		if (age < 0)
			throw age;
		cout << "���̴� : " << age;
	}
	catch (int e) {
		cout << "����: ����� �Է��Ͻÿ�.";
	}
}