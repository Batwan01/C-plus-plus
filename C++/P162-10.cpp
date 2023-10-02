#include <iostream>
using namespace std;

int flip() {
	return rand() % 2; // 0~1 랜덤 함수
}

int main() {
	int front{ 0 }, back{ 0 };

	srand(time(NULL)); //rand 초기화

	for (int i = 0; i < 100; i++) {
		if (flip() == 0) front++;
		else back++;
	}
	cout << "동전의 앞면:\t" << front << endl;
	cout << "동전의 뒷면:\t" << back << endl;
	
	system("pause");
	return 0;
}