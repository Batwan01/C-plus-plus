#include <iostream>
using namespace std;

int flip() {
	return rand() % 2; // 0~1 ���� �Լ�
}

int main() {
	int front{ 0 }, back{ 0 };

	srand(time(NULL)); //rand �ʱ�ȭ

	for (int i = 0; i < 100; i++) {
		if (flip() == 0) front++;
		else back++;
	}
	cout << "������ �ո�:\t" << front << endl;
	cout << "������ �޸�:\t" << back << endl;
	
	system("pause");
	return 0;
}