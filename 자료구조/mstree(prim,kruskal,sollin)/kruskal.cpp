/*#include<fstream>
#include<queue>
#include"mstree.h"
int NNODES;

priority_queue<Edge, vector<Edge>, Compare> PQ;
void kruskal() {
	Sets sets(NNODES);   //총 정점 NNODES개
	int nedges = 0;   //간선들 찾은 개수?
	while (nedges < NNODES - 1) {  //간선의 총 개수가  정점의 총개수 -1 까지되면 탈출!
		if (PQ.empty()) throw "No Spanning Tree Exists";
		Edge e = PQ.top(); PQ.pop();

		int v1root = sets.Find(e.v1); int v2root = sets.Find(e.v2); //누구의 집합인지( 집합이라는 것은 연결되있다는 것)
		if (v1root != v2root) {//정점 v1과 v2가 이미 연결된점 즉 사이클이면 아무것도 하지 않는다.
			sets.Union(v1root, v2root); nedges++; //연결이 되지 않았다면 연결 시키고 현재 간선  개수 추가!
			cout << e;
		}
	}
}

void ReadEdges4kruskal(istream& is) {
	Edge e;
	while (GetEdge(is, NNODES, e)) PQ.push(e);  //간선 e부터 PQ에 우선순위(weight가 낮은 것 우선)로 넣음, 입력끝나기 전까진 계속 GetEdge
}
int main(int argc, char *argv[]) {
	ifstream is;
	if (argc == 1) is.open("mstree.txt"); else is.open(argv[1]);
	if (!is) {
		cerr << "No such input file\n; return 1;";
	}
	is >> NNODES;
	if (NNODES < 2) { cerr << "#nodes must be 2.." << endl; return 1; }

	try { ReadEdges4kruskal(is); kruskal(); }
	catch (char const *str) {
		cerr << "Exception: " << str << endl; return 1;
	}
}*/