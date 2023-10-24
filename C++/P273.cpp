#include <iostream>
#include <vector>
using namespace std;

void push_vector(vector<int> &num,int score) {
	num.push_back(score);
}

int main() {
	int score = 0;
	int sum = 0;
	vector<int> num;

	while (true) {
		cout << "성적을 입력하시오(종료는 -1) : ";
		cin >> score;
		if (score == -1)
			break;
		push_vector(num,score);
		
	}
	int count = 0;
	for (auto& e : num) {
		sum += e;
		count++;
	}
	cout << sum / count;
	
}