#include <stdio.h>
#include <iostream>

using namespace std;

int fibo(int number)
{
	if (number == 0) {
		return 0;
	}
	else if (number == 1) {
		return 0;
	}
	else {
		cout << number << " ";
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