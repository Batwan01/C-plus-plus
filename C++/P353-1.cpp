#include <iostream>
#include <string>
using namespace std;

int main() {
	int* p;
	int N;
	cout << "몇개";
	cin >> N;
	p = new int[N];
	for (int i = 0; i < N; i++) {
		cout << "입력";
		cin >> p[i];
	}
	cout << "배열 값 :";
	for (int i = 0; i < N; i++) {
		cout << " " << p[i] ;
	}
	delete[] p;
}