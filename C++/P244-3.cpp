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
	system("pause");
	return 0;
	BankAccount bank2;
	BankAccount *p = new BankAccount[10]{ bank, bank2, BankAccount(2,3)};

	BankAccount p[10]{ BankAccount(2,3)};
}
