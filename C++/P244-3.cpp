#include <iostream>
using namespace std;

class BankAccount {
private:
	int balance;
	double rate;
public:
	BankAccount(int balances = 0, double rates = 0.05) : balance{ balances }, rate{ rates } {};
	void deposit(int money);
	void withdraw(int money);
};

void BankAccount::deposit(int money) {
	balance += money;
	cout << "���� �ܾ� : " << balance << endl;
}

void BankAccount::withdraw(int money) {
	if (money > balance) cout << "�ܾ��� �����մϴ�." << endl;
	balance -= money;
	cout << "���� �ܾ� : " << balance << endl;
}

int main() {
	BankAccount bank;
	bank.deposit(10000);
	bank.withdraw(5000);
}