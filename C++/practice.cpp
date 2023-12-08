#include <iostream>
#include <vector>
using namespace std;

int main() {
	int p[3] = { 0,1,2 };
	p[2] = p[1] + 12;
	cout << p[2];
}

