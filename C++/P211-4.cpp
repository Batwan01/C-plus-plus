#include <iostream>
using namespace std;

class Book {
public:
	string title;
	string author;


};

int main() {
	Book obj;
	obj.title = "Great C++";
	obj.author = "Bob";

	cout << "å �̸�: " << obj.title << endl;
	cout << "å ����: " << obj.author << endl;
	system("pause");
	return 0;
}