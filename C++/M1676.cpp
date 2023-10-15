#include <iostream>
using namespace std;

class Factorial {
public:
	int N;
	Factorial(int N) {
		this->N = N;
	}
	long long sum(long long N);
};

long long Factorial::sum(long long N) {
	if (N <= 1) return 1;

	return N * sum(N - 1);
}

int main() {

	int N;
	long long result;
	cin >> N;
	Factorial obj(N);
	result = obj.sum(N);
	cout << result;
}