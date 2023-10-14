#include <iostream>
#include <ctime>
using namespace std;

class Dice {
public:
	int face;

	int roll();
};

int Dice::roll() {
	face = (rand() % 6 + 1);
	return face;
}

int main() {
	Dice obj;
	srand((unsigned int)time(NULL));

	cout << "주사위 값=" << obj.roll() << endl;

	cout << "주사위 값=" << obj.roll() << endl;
	return 0;
}