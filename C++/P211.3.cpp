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
	cout << "ù ��° ���� : ";
	cin >> x;
	cout << "�� ��° ���� : ";
	cin >> y;
	obj.init(x, y);
	cout << "���� ���:" << obj.add() << endl;
	system("pause");
}