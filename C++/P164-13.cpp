#include <iostream>
#include <string>
using namespace std;

int main() {
	int counter[256] = { 0 }, check{ 0 };
	string s;
	cout << "암호를 입력하시오: ";
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) { //문자열 입력받기
		counter[s[i]]++;
	}

	for (int i = 48; i < 58; i++) { //숫자 확인
		if (counter[i] >= 1) { check++; break; }
	}

	for (int i = 97; i < 123; i++) { //소문자 확인
		if (counter[i] >= 1) { check++; break; }
	}

	for (int i = 65; i < 91; i++) { // 대문자 확인
		if (counter[i] >= 1) { check++; break; }
	}

	if (check == 3) cout << "안전합니다." << endl;
	else cout << "안전하지 않습니다." << endl;

	system("pause");
	return 0;
}