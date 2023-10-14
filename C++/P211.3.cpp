#include <iostream>
using namespace std;

class sum {
public:
	int n1, n2;

	void init(int x, int y) {
		this->n1 = x;
		this->n2 = y;
	}
	
	int add() {
		return n1 + n2;
	}
	
};

int main() {
	sum obj;
	int x, y;
	cout << "첫 번째 정수 : ";
	cin >> x;
	cout << "두 번째 정수 : ";
	cin >> y;
	obj.init(x, y);
	cout << "연산 결과:" << obj.add() << endl;
	system("pause");
}