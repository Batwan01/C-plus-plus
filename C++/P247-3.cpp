#include <iostream>
using namespace std;

class Box {
private:
	int length;
	int width;
	int height;
	int volume = 0;
	int num = 0;
	static int count;
	bool emp = true;
public:
	Box() {
		count++;
		num = count;
		length = 0;
		width = 0;
		height = 0;
		volume = length * width * height;
		empty(volume);
	}

	Box(int leng, int wid, int hei) {
		count++;
		num = count;
		length = leng;
		width = wid;
		height = hei;
		volume = length * width * height;
		empty(volume);
	}

	void empty(int volume) {
		if (volume == 0) emp = true;
		else emp = false;
	}

	void print() {
		cout << "���� #" << num << endl;
		cout << "������ ����: " << length << endl;
		cout << "������ �ʺ�: " << width << endl;
		cout << "������ ����: " << height << endl;
		cout << "������ ����: " << volume << endl;
		if (emp == true) cout << "�������." << endl << endl;
		else cout << "������� ����." << endl << endl;
	}
};
int Box::count = 0;
int main() {
	Box A;
	A.print();

	Box B(3, 2, 4);
	B.print();


	system("pause");
	return 0;
}