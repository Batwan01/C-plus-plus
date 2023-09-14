#include <stdio.h>
#include <iostream>

using namespace std;

int fibo(int number)
{
	if (number == 0) {
		cout << "0 ";
		return 0;
	}
	else if (number == 1) {
		cout << "1 ";
		return 0;
	}
	else {
		cout << fibo(number - 1) + fibo(number - 2) << " ";
		return fibo(number - 1) + fibo(number - 2);
	}
}

int main()
{
	int n, num;

	cin >> n;

	num = fibo(n);
	return 0;
}