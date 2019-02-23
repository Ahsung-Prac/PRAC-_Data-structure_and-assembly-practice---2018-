/*#include<fstream>
#include<queue>
#include"mstree.h"
int NNODES;

priority_queue<Edge, vector<Edge>, Compare> PQ;
queue<Edge> *Q;

void MoveIntoPQ_EdgesOfNode(int v) {
	while (!Q[v].empty()) {
		PQ.push(Q[v].front());     // 정점이 0의 집합에 속하게될때 정점과 연결된 간선들도 0의 집합의 우선순위 간선에 넣어주기 위해.
		Q[v].pop();
	}
}

void prim() {
	Sets sets(NNODES);
	int nedges = 0; //현재까지 총 노드(간선 수)
	while (nedges < NNODES - 1) {
		if (PQ.empty()) throw "No Spanning Tree Exists.";
		Edge e = PQ.top(); PQ.pop(); // 우선순위 간선을 뽑아냄
		int root0 = sets.Find(0); //정점0을 포함하는 집합
		int v1root = sets.Find(e.v1);    //간선의 정점들이 어떤 집합트리의 원소인지 확인. 밑에서 비교
		if (root0 == v1root) { v1root = sets.Find(e.v2); }  
		if (root0 != v1root) { //둘다 집합에 이미 속한 정점을 한번더 연결하면 사이클이됨..(둘중 이미 하나는 연결되있는 것이지만(0부터 시작한 간선이므로) v1,v2중에 누군지 알수 없으므로 둘중 하나라도 연결이 안되있다면으로 가정.)
			MoveIntoPQ_EdgesOfNode(v1root);   //새로 연결될 간선에 속한 정점들의 또다른 간선들도 우선순위에 넣어준다.
			sets.Union(v1root,root0); //우선순위 간선의 정점의 집합이 0의 집합과 다르다면 합쳐준다. *같은데 또 연결하게 되면 사이클이기에 스킵,
			nedges++;
			cout << e;
		}		
	}
}
void ReadEdges4prim(istream& is) {
	Q = new queue<Edge>[NNODES];
	Edge e;
	while (GetEdge(is, NNODES, e)) {
		Q[e.v1].push(e); //정점에 연결된 모든 간선을 queue에 집어 넣음
		Q[e.v2].push(e);
	}
	MoveIntoPQ_EdgesOfNode(0);  //0부터 시작하기떄문에 우선순위 큐에는 정점0의 간선을 넣어준다.
}

int main(int argc, char *argv[]) {
	ifstream is;
	if (argc == 1) is.open("mstree.txt"); else is.open(argv[1]);
	if (!is) {
		cerr << "No such input file\n; return 1;";
	}
	is >> NNODES;
	if (NNODES < 2) { cerr << "#nodes must be 2.." << endl; return 1; }

	try { ReadEdges4prim(is); prim(); }
	catch (char const *str) {
		cerr << "Exception: " << str << endl; return 1;
	}
}*/