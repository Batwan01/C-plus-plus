#include <iostream>
#include <vector>
using namespace std;
void func(int x , int y=100) {
	cout << x << y;
}
int main() {
	func(10);
}