#include <iostream>
using namespace std;

class Line {
public:
	int getLength(void) { return *ptr; };
	Line(int len);
	Line(Line& p);
	~Line();

private:
	int* ptr;
};

Line::~Line() {
	delete ptr;
}

Line::Line(int len) {
	cout << "�Ϲ� ������" << endl;
	ptr = new int;
	*ptr = len;
}

Line::Line(Line& p) {
	ptr = new int;
	*ptr = *(p.ptr);
	cout << "���� ������" << endl;
}


int main(void) {
	Line line1(10);
	Line line2(line1);
	Line line3(line1);
	cout << "���� ����: " << line1.getLength() << endl;
	Line line4(line1);
	cout << "���� ����: " << line2.getLength() << endl;


}