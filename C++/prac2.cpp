#include <iostream>
using namespace std;

class HomeAppliance {
	int price;
	virtual double getPrice() = 0;
public:
	HomeAppliance(int price) :price(price) {}
	int get_price() { return price; }
	virtual void print() = 0;
};

class Television :public HomeAppliance {
public:
	Television(int price) : HomeAppliance(price) {}
	double getPrice() { return get_price() * 0.9; }
	void print() { cout << "Tv : " << getPrice() << endl; }
};

class Refrigerator :public HomeAppliance {
public:
	Refrigerator(int price) : HomeAppliance(price) {}
	double getPrice() { return get_price() * 0.95; }
	void print() { cout << "Refi : " << getPrice() << endl; }
};

int main() {
	HomeAppliance* home[4];
	home[0] = new Television(1000000);
	home[1] = new Refrigerator(1000000);
	home[2] = new Television(200000);
	home[3] = new Refrigerator(20000);

	for (int i = 0; i < 4; i++) {
		home[i]->print();
	}
	
	HomeAppliance* nhome = new HomeAppliance(123);

}