#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int cash{ 50 };
	double bets{ 0 }, win{ 0 };
	cout << "�ʱ� �ݾ� $" << cash << endl << "��ǥ �ݾ� $250" << endl;
	for(int i=0; i<1000; i++) {
		cash = 50;
		while (cash != 250 && cash != 0) {
			bets++;
			if ((double)rand() / RAND_MAX < 0.5) {
				cash++;
			}
			else cash--;
		}
		if (cash == 250) win++;
	}
	cout << "1000 ���� " << win << "�� �¸�" << endl;
	cout << fixed << setprecision(6);
	cout << "�̱� Ȯ��=" << win / 10 << endl << "��� ���� Ƚ�� = " << bets / 1000 << endl;
}