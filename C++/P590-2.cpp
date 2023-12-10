#include <iostream>
using namespace std;

int main() {
	cout << "가위, 바위, 보 게임입니다." << endl;
	string word;
	try {
		cout << "무엇을 내시겠습니까: ";
		cin >> word;
	
		if (word == "가위" || word == "바위" || word == "보")
			cout << word << "내셨습니다.";
		else
			throw word;
	}
	catch(string e){
		cout << "오류: 가위 바위 보 중에서만 선택하세요.";
	}
}