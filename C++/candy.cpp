#include <iostream>
using namespace std;

int main()
{
	int money{ 1000 }, candy_price{ 300 };
	cout << "���� ������ �ִ� ��: " << money << endl; 
	cout << "ĵ���� ����: " << candy_price << endl;
	cout << "�ִ�� �� �� �ִ� ĵ���� ����=" << money / candy_price << endl;
	cout << "ĵ�� ���� �� ���� ��=" << money - money / candy_price*candy_price << endl;
	return 0;
}