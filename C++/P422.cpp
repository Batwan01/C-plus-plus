#include <iostream>
using namespace std;

class Date {
	int year, month, day;
public:
	Date(int y, int m, int d) : year(y), month(m), day(d) {}
	friend bool equals(Date a, Date b) {
		return a.year == b.year && a.month == b.month && a.day == b.day;
	}
};

int main() {
	Date d1(1960, 5, 23), d2(1960, 5, 23);
	cout << equals(d1, d2);
}