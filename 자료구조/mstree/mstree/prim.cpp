/*#include<fstream>
#include<queue>
#include"mstree.h"
int NNODES;

priority_queue<Edge, vector<Edge>, Compare> PQ;
queue<Edge> *Q;

void MoveIntoPQ_EdgesOfNode(int v) {
	while (!Q[v].empty()) {
		PQ.push(Q[v].front());     // ������ 0�� ���տ� ���ϰԵɶ� ������ ����� �����鵵 0�� ������ �켱���� ������ �־��ֱ� ����.
		Q[v].pop();
	}
}

void prim() {
	Sets sets(NNODES);
	int nedges = 0; //������� �� ���(���� ��)
	while (nedges < NNODES - 1) {
		if (PQ.empty()) throw "No Spanning Tree Exists.";
		Edge e = PQ.top(); PQ.pop(); // �켱���� ������ �̾Ƴ�
		int root0 = sets.Find(0); //����0�� �����ϴ� ����
		int v1root = sets.Find(e.v1);    //������ �������� � ����Ʈ���� �������� Ȯ��. �ؿ��� ��
		if (root0 == v1root) { v1root = sets.Find(e.v2); }  
		if (root0 != v1root) { //�Ѵ� ���տ� �̹� ���� ������ �ѹ��� �����ϸ� ����Ŭ�̵�..(���� �̹� �ϳ��� ������ִ� ��������(0���� ������ �����̹Ƿ�) v1,v2�߿� ������ �˼� �����Ƿ� ���� �ϳ��� ������ �ȵ��ִٸ����� ����.)
			MoveIntoPQ_EdgesOfNode(v1root);   //���� ����� ������ ���� �������� �Ǵٸ� �����鵵 �켱������ �־��ش�.
			sets.Union(v1root,root0); //�켱���� ������ ������ ������ 0�� ���հ� �ٸ��ٸ� �����ش�. *������ �� �����ϰ� �Ǹ� ����Ŭ�̱⿡ ��ŵ,
			nedges++;
			cout << e;
		}		
	}
}
void ReadEdges4prim(istream& is) {
	Q = new queue<Edge>[NNODES];
	Edge e;
	while (GetEdge(is, NNODES, e)) {
		Q[e.v1].push(e); //������ ����� ��� ������ queue�� ���� ����
		Q[e.v2].push(e);
	}
	MoveIntoPQ_EdgesOfNode(0);  //0���� �����ϱ⋚���� �켱���� ť���� ����0�� ������ �־��ش�.
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