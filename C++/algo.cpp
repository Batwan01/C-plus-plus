

#include <iostream>
#include <stdlib.h> 
#include<vector>

using namespace std;
struct adj_mat {
	int u, v, weight;  // ����ü  ����u,����v,����ġweight�� ����
};
struct cycle {
	vector<int> v;
};
vector<cycle>::iterator it;
int gan;
vector<cycle> cycles;

adj_mat graph[20][20]; // �ִ�ũ�⸦ 20*20 �� ����
int parent[20];//union_set�Ҷ� �ʿ�
adj_mat pir[210]; //qsort
int find_set(int u, int v);
/*adj_mat graph[9][9] = {
**�Է�**

����ġ 0�� �ڱ��ڽ� 20�� ���Ѵ�
{0 , 4, 20, 20, 20, 20, 20, 8,  20,
{4 , 0, 8 , 20, 20, 20, 20, 11, 20},
{20, 8 , 0, 7 , 20, 4 , 20, 20, 2 },            //20�� ���Ѵ�
{20, 20, 7 ,0, 9 , 14, 20, 20, 20},            // ����������
{20, 20, 20, 9 ,0, 10, 20, 20 ,20},
{20, 20, 4 , 14, 10,0, 2 , 20 ,20},
{20, 20, 20, 20, 20, 2 , 0, 1 , 6 },
{8 , 11, 20, 20, 20, 20, 1 , 0, 7 },
{20, 20, 2 , 20, 20, 20, 6 , 7 , 0} };


 ���� �Է� 0 1 4 , 0 7 8 , 1 2 8 ,1 7 11 , 7 8 7 , 7 6 1 , 8 6 6 , 8 2 2 , 6 5 2, 2 5 4, 2 3 7 , 3 4 9 , 3 5 14, 4 5 10                    */
void init_graph() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			graph[i][j].u = i;
			graph[i][j].v = j;
			if (i == j) {
				graph[i][j].weight = 0;
			}
			else {
				graph[i][j].weight = 20;
			}


		}
	}
}
void make_graph(int n) {
	int  u, v, weight;
	cout << "������ ������ " << endl;
	cin >> gan;

	for (int i = 0; i < gan; i++) {
		cout << "U   V    Weight" << endl;
		cin >> u >> v >> weight;
		graph[u][v].weight = weight;
		graph[v][u].weight = weight;
	}


}
void init_set(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}

}
int compare(const void* A, const void* B) {
	adj_mat* ptrA = (adj_mat*)A;
	adj_mat* ptrB = (adj_mat*)B;

	if (ptrA->weight < ptrB->weight) return -1;
	else if (ptrA->weight > ptrB->weight) return 1;
	else return 0;
}



int union_set(int u, int v) {
	if ((parent[u] < 0) && (parent[v] < 0)) {    //�ΰ��� �����϶� 
		if (parent[u] <= parent[v]) { // U �� �������� U�� �պ����Ѷ� 
			parent[u] = parent[u] + parent[v];
			parent[v] = u;


			return 1;
		}
		else {                       // V �� �������� V�� �պ����Ѷ� .
			parent[v] = parent[v] + parent[u];
			parent[u] = v;


			return 1;
		}
	}
	if ((parent[u] >= 0) && (parent[v] >= 0)) { //�ΰ���  ����̸� 

		if (parent[u] == parent[v]) {  //���� ������ �պ���Ű������ .

			return 0;
		}
		if (parent[parent[u]] <= parent[parent[v]]) {  //U �� ��Ʈ����  V�� ��Ʈ����߿� U�� �������ÿ� U�� �պ����Ѷ�
			parent[parent[u]] = parent[parent[u]] + parent[parent[v]];  // U�� ��Ʈ��忡 V�� ��Ʈ��� ���� ���Ѵ�. 
			parent[parent[v]] = parent[u]; // V�Ƿ�Ʈ��忡 U�� ���� �ִ´�. 




			return 1;
		}


		else {
			parent[parent[v]] = parent[parent[v]] + parent[parent[u]];  // U�� ��Ʈ��忡 V�� ��Ʈ��� ���� ���Ѵ�. 
			parent[parent[u]] = parent[v]; // V�Ƿ�Ʈ��忡 U�� ���� �ִ´�. 

			return 1;
		}

	}
	/*������   ��� ����     ,  ���� ��� �ۿ� ���� .*/
	if (parent[u] > parent[v]) {  // U�� ��� V �� ���� �϶�
		if (parent[parent[u]] <= parent[v]) { // U�� ��Ʈ����� ���� V�� ������ ������� 
			parent[parent[u]] = parent[parent[u]] + parent[v];
			parent[v] = parent[u];

			return 1;
		}
		else {
			parent[v] = parent[v] + parent[parent[u]];
			parent[parent[u]] = v;

			return 1;
		}
	}
	else { //U�� ���� V�� ��� �϶� 
		if (parent[u] <= parent[parent[v]]) {
			parent[u] = parent[u] + parent[parent[v]];
			parent[parent[v]] = u;

			return 1;
		}
		else {
			parent[parent[v]] = parent[parent[v]] + parent[u];
			parent[u] = parent[v];

			return 1;

		}
	}
}
int find_set(int u, int v) {


	int unum = -1, vnum = -1, snum = 0;   // unum, vnum �� �ε����� �˷��ֱ� ���� 0�̶����ļ� -1�� �־��ش� .


	if (cycles.size() == 0) {
		cycle l;  //cycle �� Ǫ�� 
		cycles.push_back(l);
		cycles[0].v.push_back(u);
		cycles[0].v.push_back(v);

		return 1; // union_set�϶�� 1�� ������
	}


	for (int i = 0; i < cycles.size(); i++) {
		for (int j = 0; j < cycles[i].v.size(); j++) {              // cycles �Լ��ȿ��ִ� vector v �� size ��ŭ �ݺ��Ѵ�.
			if (cycles[i].v[j] == u) {
				unum = i;
				snum++;
			}
			else if (cycles[i].v[j] == v) {
				vnum = i;
				snum++;
			}
		}
		if (snum == 2) return 0;// union_set��������� 0�� ������
		snum = 0;
	}
	if (unum == -1 && vnum == -1) {  // unum , vnum �Ѵ� -1 �ΰ��  U V ������ ���°��̴� .
		cycle l;  //cycle �� Ǫ�� 
		cycles.push_back(l);
		cycles[cycles.size() - 1].v.push_back(u);
		cycles[cycles.size() - 1].v.push_back(v);


		return 1; // union_set�϶�� 1�� ������.  
	}
	else if (unum == -1 || vnum == -1) {

		if (unum > -1) {

			cycles[unum].v.push_back(v);
			return 1;//union_set�϶�� 1�� ������.
		}
		else {

			cycles[vnum].v.push_back(u);
			return 1;//union_set�϶�� 1�� ������.
		}
	}
	else if (unum < vnum) {

		for (int i = 0; i < cycles[vnum].v.size(); i++) {
			cycles[unum].v.push_back(cycles[vnum].v[i]); // clcles[unum].v  ���� �ڿ�  vnum.v �� ������.
		}

		it = cycles.begin();
		cycles.erase(it + vnum);

		return 1;// union_set�϶�� 1�� ������
		//unum�� v �� �迭 �� ���� �����ؼ� vnum �� v�� �迭 ������ ��ŭ �Ű��ش�

	}
	else { // unum >vnum �ϰ�� 
		for (int i = 0; i < cycles[unum].v.size(); i++) {
			cycles[vnum].v.push_back(cycles[unum].v[i]); // clcles[unum].v  ���� �ڿ�  vnum.v �� ������.
		}

		it = cycles.begin();
		cycles.erase(it + unum);

		return 1;// union_set�϶�� 1�� ������
	}












	for (int i = 0; i < gan; i++) {
		cout << parent[i] << "    ";
	}

}







int main() {
	int n;
	init_graph();
	cin >> n; //n�� �Է� �޴´�.


	make_graph(n);




	init_set(n);//n���� ������ ����



	int cot1 = 0;
	int cot = 1; //�����ϱ����ؼ�
	for (int i = 0; i < n; i++) {
		for (int j = cot; j < n; j++) {
			pir[cot1] = graph[i][j];
			cot1++;
		}
		cot++;
	}
	qsort(pir, cot1, sizeof(struct adj_mat), compare); // ����ġ�� ���� 

	int count = 0; // �ּҰ����� ����
	int sum = 0;
	for (int i = 0; i < cot1; i++) {
		int u, v;
		u = pir[i].u;
		v = pir[i].v;
		if (find_set(u, v)) {  // 1 �̸� count  ++ 
			union_set(u, v);
			count++;
			sum = sum + pir[i].weight;
			cout << pir[i].u << pir[i].v << pir[i].weight << endl;
			if (count == n - 1) break;
		}

	}

	cout << "�� ����ġ��";
	cout << sum << endl;


	cout << "������ parent ���" << endl;
	for (int i = 0; i < n; i++) {
		cout << parent[i];
	}
	cout << endl;


	cout << "����ġ ��� " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j].weight;
		}
		cout << endl;
	}
}