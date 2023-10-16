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
		cout << "상자 #" << num << endl;
		cout << "상자의 길이: " << length << endl;
		cout << "상자의 너비: " << width << endl;
		cout << "상자의 높이: " << height << endl;
		cout << "상자의 부피: " << volume << endl;
		if (emp == true) cout << "비어있음." << endl << endl;
		else cout << "비어있지 않음." << endl << endl;
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