#include <iostream>
using namespace std;

int main() {
	cout << "����, ����, �� �����Դϴ�." << endl;
	string word;
	try {
		cout << "������ ���ðڽ��ϱ�: ";
		cin >> word;
	
		if (word == "����" || word == "����" || word == "��")
			cout << word << "���̽��ϴ�.";
		else
			throw word;
	}
	catch(string e){
		cout << "����: ���� ���� �� �߿����� �����ϼ���.";
	}
}