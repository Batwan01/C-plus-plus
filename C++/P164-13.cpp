#include <iostream>
#include <string>
using namespace std;

int main() {
	int counter[256] = { 0 }, check{ 0 };
	string s;
	cout << "��ȣ�� �Է��Ͻÿ�: ";
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) { //���ڿ� �Է¹ޱ�
		counter[s[i]]++;
	}

	for (int i = 48; i < 58; i++) { //���� Ȯ��
		if (counter[i] >= 1) { check++; break; }
	}

	for (int i = 97; i < 123; i++) { //�ҹ��� Ȯ��
		if (counter[i] >= 1) { check++; break; }
	}

	for (int i = 65; i < 91; i++) { // �빮�� Ȯ��
		if (counter[i] >= 1) { check++; break; }
	}

	if (check == 3) cout << "�����մϴ�." << endl;
	else cout << "�������� �ʽ��ϴ�." << endl;

	system("pause");
	return 0;
}