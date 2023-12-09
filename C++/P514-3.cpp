#include <iostream>
using namespace std;

class HomeApplicance {
	int price;
	virtual double getPrice() = 0;
public:
	HomeApplicance(int price):price{price} {}
};

class Television :public HomeApplicance {
	int Tv_price;
public:
	Television(int price) :HomeApplicance(price), Tv_price{ price } {}
	double getPrice() { return Tv_price*0.9; }
};

class Refrigerator :public HomeApplicance {
	int Re_price;
public:
	Refrigerator(int price): HomeApplicance(price), Re_price{price} {}
	double getPrice() { return Re_price*0.95; }
};

int main() {
	Television *t = new Television(100000);
	Refrigerator* r = new Refrigerator(200000);
	Television* t1 = new Television(360000);
	cout << t->getPrice() << endl;
	cout << r->getPrice() << endl;
	cout << t1->getPrice();
}