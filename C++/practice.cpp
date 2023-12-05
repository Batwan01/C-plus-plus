#include <iostream>
#include <vector>
using namespace std;

void up(Pizza& p) {

}
int main() {
	Pizza obj(10);
	up(obj);


	const int* p1;
	int* const p2=0;
	const int* const p3=0;
	int a = 50;

	//*p1 = 5;
	*p1 = &a;
	cout << *p1;

	*p2 = 50;
	//*p2 = &a;

	*p3 = 50;
	*p3 = &a;
}