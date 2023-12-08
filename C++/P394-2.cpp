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
	cout << "일반 생성자" << endl;
	ptr = new int;
	*ptr = len;
}

Line::Line(Line& p) {
	ptr = new int;
	*ptr = *(p.ptr);
	cout << "복사 생성자" << endl;
}


int main(void) {
	Line line1(10);
	Line line2(line1);
	Line line3(line1);
	cout << "선의 길이: " << line1.getLength() << endl;
	Line line4(line1);
	cout << "선의 길이: " << line2.getLength() << endl;


}