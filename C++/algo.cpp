

#include <iostream>
#include <stdlib.h> 
#include<vector>

using namespace std;
struct adj_mat {
	int u, v, weight;  // 구조체  정점u,정점v,가중치weight를 선언
};
struct cycle {
	vector<int> v;
};
vector<cycle>::iterator it;
int gan;
vector<cycle> cycles;

adj_mat graph[20][20]; // 최대크기를 20*20 개 설정
int parent[20];//union_set할때 필요
adj_mat pir[210]; //qsort
int find_set(int u, int v);
/*adj_mat graph[9][9] = {
**입력**

가중치 0은 자기자신 20은 무한대
{0 , 4, 20, 20, 20, 20, 20, 8,  20,
{4 , 0, 8 , 20, 20, 20, 20, 11, 20},
{20, 8 , 0, 7 , 20, 4 , 20, 20, 2 },            //20은 무한대
{20, 20, 7 ,0, 9 , 14, 20, 20, 20},            // 비용인접행렬
{20, 20, 20, 9 ,0, 10, 20, 20 ,20},
{20, 20, 4 , 14, 10,0, 2 , 20 ,20},
{20, 20, 20, 20, 20, 2 , 0, 1 , 6 },
{8 , 11, 20, 20, 20, 20, 1 , 0, 7 },
{20, 20, 2 , 20, 20, 20, 6 , 7 , 0} };


 실제 입력 0 1 4 , 0 7 8 , 1 2 8 ,1 7 11 , 7 8 7 , 7 6 1 , 8 6 6 , 8 2 2 , 6 5 2, 2 5 4, 2 3 7 , 3 4 9 , 3 5 14, 4 5 10                    */
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
	cout << "간선의 개수를 " << endl;
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
	if ((parent[u] < 0) && (parent[v] < 0)) {    //두개다 음수일때 
		if (parent[u] <= parent[v]) { // U 가 더작으면 U에 합병시켜라 
			parent[u] = parent[u] + parent[v];
			parent[v] = u;


			return 1;
		}
		else {                       // V 가 더작으면 V에 합병시켜라 .
			parent[v] = parent[v] + parent[u];
			parent[u] = v;


			return 1;
		}
	}
	if ((parent[u] >= 0) && (parent[v] >= 0)) { //두개다  양수이면 

		if (parent[u] == parent[v]) {  //둘이 같으면 합병시키지마라 .

			return 0;
		}
		if (parent[parent[u]] <= parent[parent[v]]) {  //U 의 루트노드와  V의 루트노드중에 U가 더작을시에 U에 합병시켜라
			parent[parent[u]] = parent[parent[u]] + parent[parent[v]];  // U의 루트노드에 V의 루트노드 값을 더한다. 
			parent[parent[v]] = parent[u]; // V의루트노드에 U의 값을 넣는다. 




			return 1;
		}


		else {
			parent[parent[v]] = parent[parent[v]] + parent[parent[u]];  // U의 루트노드에 V의 루트노드 값을 더한다. 
			parent[parent[u]] = parent[v]; // V의루트노드에 U의 값을 넣는다. 

			return 1;
		}

	}
	/*이제는   양수 음수     ,  음수 양수 밖에 없다 .*/
	if (parent[u] > parent[v]) {  // U가 양수 V 가 음수 일때
		if (parent[parent[u]] <= parent[v]) { // U의 루트노드의 값이 V의 값보다 작을경우 
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
	else { //U가 음수 V가 양수 일때 
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


	int unum = -1, vnum = -1, snum = 0;   // unum, vnum 은 인덱스를 알려주기 위해 0이랑겹쳐서 -1을 넣어준다 .


	if (cycles.size() == 0) {
		cycle l;  //cycle 을 푸쉬 
		cycles.push_back(l);
		cycles[0].v.push_back(u);
		cycles[0].v.push_back(v);

		return 1; // union_set하라고 1을 리턴함
	}


	for (int i = 0; i < cycles.size(); i++) {
		for (int j = 0; j < cycles[i].v.size(); j++) {              // cycles 함수안에있는 vector v 의 size 만큼 반복한다.
			if (cycles[i].v[j] == u) {
				unum = i;
				snum++;
			}
			else if (cycles[i].v[j] == v) {
				vnum = i;
				snum++;
			}
		}
		if (snum == 2) return 0;// union_set하지말라고 0을 리턴함
		snum = 0;
	}
	if (unum == -1 && vnum == -1) {  // unum , vnum 둘다 -1 인경우  U V 정점이 없는것이다 .
		cycle l;  //cycle 을 푸쉬 
		cycles.push_back(l);
		cycles[cycles.size() - 1].v.push_back(u);
		cycles[cycles.size() - 1].v.push_back(v);


		return 1; // union_set하라고 1을 리턴함.  
	}
	else if (unum == -1 || vnum == -1) {

		if (unum > -1) {

			cycles[unum].v.push_back(v);
			return 1;//union_set하라고 1을 리턴함.
		}
		else {

			cycles[vnum].v.push_back(u);
			return 1;//union_set하라고 1을 리턴함.
		}
	}
	else if (unum < vnum) {

		for (int i = 0; i < cycles[vnum].v.size(); i++) {
			cycles[unum].v.push_back(cycles[vnum].v[i]); // clcles[unum].v  벡터 뒤에  vnum.v 를 붙힌다.
		}

		it = cycles.begin();
		cycles.erase(it + vnum);

		return 1;// union_set하라고 1을 리턴함
		//unum의 v 의 배열 끝 부터 시작해서 vnum 의 v의 배열 사이즈 만큼 옮겨준다

	}
	else { // unum >vnum 일경우 
		for (int i = 0; i < cycles[unum].v.size(); i++) {
			cycles[vnum].v.push_back(cycles[unum].v[i]); // clcles[unum].v  벡터 뒤에  vnum.v 를 붙힌다.
		}

		it = cycles.begin();
		cycles.erase(it + unum);

		return 1;// union_set하라고 1을 리턴함
	}












	for (int i = 0; i < gan; i++) {
		cout << parent[i] << "    ";
	}

}







int main() {
	int n;
	init_graph();
	cin >> n; //n을 입력 받는다.


	make_graph(n);




	init_set(n);//n개의 집합을 생성



	int cot1 = 0;
	int cot = 1; //정렬하기위해서
	for (int i = 0; i < n; i++) {
		for (int j = cot; j < n; j++) {
			pir[cot1] = graph[i][j];
			cot1++;
		}
		cot++;
	}
	qsort(pir, cot1, sizeof(struct adj_mat), compare); // 가중치로 정렬 

	int count = 0; // 최소간선의 개수
	int sum = 0;
	for (int i = 0; i < cot1; i++) {
		int u, v;
		u = pir[i].u;
		v = pir[i].v;
		if (find_set(u, v)) {  // 1 이면 count  ++ 
			union_set(u, v);
			count++;
			sum = sum + pir[i].weight;
			cout << pir[i].u << pir[i].v << pir[i].weight << endl;
			if (count == n - 1) break;
		}

	}

	cout << "총 가중치는";
	cout << sum << endl;


	cout << "마지막 parent 행렬" << endl;
	for (int i = 0; i < n; i++) {
		cout << parent[i];
	}
	cout << endl;


	cout << "가중치 행렬 " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j].weight;
		}
		cout << endl;
	}
}