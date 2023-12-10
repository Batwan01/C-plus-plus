#include <iostream>
using namespace std;

template <class T>
T getAvg(T arr[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum / 5;
}

int main() {
	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	cout << "ЦђБе: " << getAvg(list, 5);
}