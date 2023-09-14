#include <iostream>
using namespace std;
#define fibonacci(before, after) before + after; //피보나치 매크로

int main() {
	int num{ 0 };
	int before{ 0 };
	int after{ 0 };
	int sum{ 1 };

	cout << "몇 항까지 구할까요: ";
	cin >> num; //반복 횟수 입력받기
	if (num == 0) { cout << num; return 0; }
	for (int i = 0; i < num; i++) {
		if (after == 0) { cout << after++ << " "; }
		else {
			cout << sum << " ";
			sum = fibonacci(before, after); //피보나치 매크로
			before = after;
			after = sum;
		}
	}
	return 0;
}