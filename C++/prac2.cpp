#include <iostream>
using namespace std;

template <class T>
T getSmallest(T list[], int n) {
	T small = list[0];
	for (int i = 0; i < n; i++)
		if (small > list[i]) small = list[i];
	return small;
}

int main() {
	double list[] = { 1.2,1.3,1.4,1.5 };
	cout << getSmallest(list, 4);
}