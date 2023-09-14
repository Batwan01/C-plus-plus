#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int cash{ 50 };
	double bets{ 0 }, win{ 0 };
	cout << "초기 금액 $" << cash << endl << "목표 금액 $250" << endl;
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
	cout << "1000 중의 " << win << "번 승리" << endl;
	cout << fixed << setprecision(6);
	cout << "이긴 확률=" << win / 10 << endl << "평균 배팅 횟수 = " << bets / 1000 << endl;
}