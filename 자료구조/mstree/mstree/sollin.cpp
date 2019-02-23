#include<fstream>
#include<queue>
#include"mstree.h"
int NNODES;

priority_queue<Edge, vector<Edge>, Compare> *PQ;

void MoveIntoPQ_EdgesOfNode(int v,int c) {  //v에서 c로 옮김 같은 집합이 된 정점끼리 우선순위 간선을 공유하게됨 ,이때 같은 간선은 삭제해주자.
	while (!PQ[v].empty()) {
		PQ[c].push(PQ[v].top());     // 정점이 0의 집합에 속하게될때 정점과 연결된 간선들도 0의 집합의 우선순위 간선에 넣어주기 위해.
		PQ[v].pop();
	}
}

void sollin() {
	Sets sets(NNODES);
	int nedges = 0;
	while (nedges < NNODES - 1) {
		for (int i = 0; i < NNODES; i++) {
			int current = sets.Find(i);     // 정점 i의 집합대표!
			if (PQ[current].empty()) throw "No Spanning Tree Exists.";
			Edge e = PQ[current].top(); PQ[current].pop(); //그 집합 대표의 우선순위 간선 튀어나왔!
			int v1root = sets.Find(e.v1);
			if (current == v1root) { v1root = sets.Find(e.v2); }  //간선의 v1과 v2의 집합 대표 튀어나와~ 사실 둘중하나는 current와 같을것이지만 누군지 모르니까 둘다 나와.
			if (v1root != current) {
				//sets.Union(v1root, v2root);
				//current = sets.Find(v1root);  //current 갱신 새로운 대표로 변경, v1과 v2는 크기의 문제이므로 누가 집합에 속하는 정점인지는 그냥은 알 수 업음.
				sets.Union(v1root, current); MoveIntoPQ_EdgesOfNode(v1root, current);   //같은 곳에서 넣고 빼기를 반복할 필요는 없다. 전의 집합의 우선순위들을 새로운 대표에게로 넣어준다
				//else {  // 둘다 아닐 경우는 없지만 혹시 모르니 넣어줌
				//	MoveIntoPQ_EdgesOfNode(current, e.v1);
				//	MoveIntoPQ_EdgesOfNode(current, e.v2);
				//}
				nedges++;
				cout << e;
				if (nedges == NNODES - 1) break;
			}
		}
	}
}

	void ReadEdges4sollin(istream& is){
	PQ = new priority_queue<Edge,vector<Edge>,Compare>[NNODES];
	Edge e;
	while (GetEdge(is, NNODES, e)) {
		PQ[e.v1].push(e); PQ[e.v2].push(e);
	}
}

int main(int argc, char *argv[]) {
	ifstream is;
	if (argc == 1) is.open("mstree.txt"); else is.open(argv[1]);
	if (!is) {
		cerr << "No such input file\n; return 1;";
	}
	is >> NNODES;
	if (NNODES < 2) { cerr << "#nodes must be 2.." << endl; return 1; }

	try { ReadEdges4sollin(is); sollin(); }
	catch (char const *str) {
		cerr << "Exception: " << str << endl; return 1;
	}
}