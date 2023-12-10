#include <iostream>
using namespace std;

template <class T>
T getSmallest(T arr[], int n) {
	double small = arr[0];
	for (int i = 0; i < n; i++) {
		if (small > arr[i])
			small = arr[i];
	}
	return small;
};

int main() {
	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	cout << "ÃÖ¼Ú°ª: " << getSmallest(list, 5);
}