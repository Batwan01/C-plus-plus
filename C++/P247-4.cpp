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
		cout << "영화 #" << num << endl;
		cout << "영화 제목: " << title << endl;
		cout << "영화 감독: " << director << endl;
		cout << "영화 평점: " << rating << endl << endl;
	}
};
int Movie::count = 0;
int main() {
	Movie A{ "타이타닉", "제임스 카메론", 9.5 };
	A.print();

	Movie B{ "지오스톰","딘 데블린", 8.34 };
	B.print();

	system("pause");
	return 0;
}