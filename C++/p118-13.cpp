#include <iostream>
using namespace std;

#define fibonacci(before, after) before + after;

int main() {
	int num{ 0 };
	int before{ 0 };
	int after{ 1 };

	cout << "�� �ױ��� ���ұ��: ";
	cin >> num;
	for (int i = 0; i < num; i++) {
		after = fibonacci(before, after);
		cout << after << " ";
		before = after;
	}

	return 0;
}