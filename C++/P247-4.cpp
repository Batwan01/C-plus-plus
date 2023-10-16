#include <iostream>
using namespace std;
class Movie {
private:
	string title;
	string director;
	double rating;
	static int count;
	int num;
public:
	Movie() {
		count++;
		num = count;
		title = "";
		director = "";
		rating = 0;
	}

	Movie(string title, string director, double rating) : title{ title }, director{ director }, rating{ rating } { count++; num = count; }

	void print() {
		cout << "��ȭ #" << num << endl;
		cout << "��ȭ ����: " << title << endl;
		cout << "��ȭ ����: " << director << endl;
		cout << "��ȭ ����: " << rating << endl << endl;
	}
};
int Movie::count = 0;
int main() {
	Movie A{ "Ÿ��Ÿ��", "���ӽ� ī�޷�", 9.5 };
	A.print();

	Movie B{ "��������","�� ����", 8.34 };
	B.print();

	system("pause");
	return 0;
}