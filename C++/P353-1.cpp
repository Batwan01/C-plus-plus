#include <iostream>
#include <string>
using namespace std;

int main() {
	int* p;
	int N;
	cout << "�";
	cin >> N;
	p = new int[N];
	for (int i = 0; i < N; i++) {
		cout << "�Է�";
		cin >> p[i];
	}
	cout << "�迭 �� :";
	for (int i = 0; i < N; i++) {
		cout << " " << p[i] ;
	}
	delete[] p;
}