#include <iostream>
using namespace std;

int fibonacci(int n) {
	if (n == 0) {
		cout << "0";
		return 0;
	}
	else if (n == 1) {
		cout << "1";
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	int num{ 0 };
	cout << "몇 항까지 구할까요: ";
	cin >> num; //반복 횟수 입력받기
	fibonacci(num);
	system("pause");
	return 0;
}