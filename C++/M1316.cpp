#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	string word;

	for (int i = 0; i < N; i++) {
		cin >> word;
		cout << word[2];
	}

}
