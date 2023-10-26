#include <iostream>
#include <vector>
using namespace std;

class Test {
	int x;
public:
	Test() { x = 0; cout << x << " "; }
	Test(int x): x{x} {}
};


int main() {
	Test a[2];
}