#include <iostream>
using namespace std;
#define fibonacci(before, after) before + after; //�Ǻ���ġ ��ũ��

int main() {
	int num{ 0 };
	int before{ 0 };
	int after{ 0 };
	int sum{ 1 };

	cout << "�� �ױ��� ���ұ��: ";
	cin >> num; //�ݺ� Ƚ�� �Է¹ޱ�
	if (num == 0) { cout << num; return 0; }
	for (int i = 0; i < num; i++) {
		if (after == 0) { cout << after++ << " "; }
		else {
			cout << sum << " ";
			sum = fibonacci(before, after); //�Ǻ���ġ ��ũ��
			before = after;
			after = sum;
		}
	}
	return 0;
}