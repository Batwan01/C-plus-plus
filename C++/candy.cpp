#include <iostream>
using namespace std;

int main()
{
	int money{ 1000 }, candy_price{ 300 };
	cout << "현재 가지고 있는 돈: " << money << endl; 
	cout << "캔디의 가격: " << candy_price << endl;
	cout << "최대로 살 수 있는 캔디의 개수=" << money / candy_price << endl;
	cout << "캔디 구입 후 남은 돈=" << money - money / candy_price*candy_price << endl;
	return 0;
}