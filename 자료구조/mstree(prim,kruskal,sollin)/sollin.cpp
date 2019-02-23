#include<fstream>
#include<queue>
#include"mstree.h"
int NNODES;

priority_queue<Edge, vector<Edge>, Compare> *PQ;

void MoveIntoPQ_EdgesOfNode(int v,int c) {  //v���� c�� �ű� ���� ������ �� �������� �켱���� ������ �����ϰԵ� ,�̶� ���� ������ ����������.
	while (!PQ[v].empty()) {
		PQ[c].push(PQ[v].top());     // ������ 0�� ���տ� ���ϰԵɶ� ������ ����� �����鵵 0�� ������ �켱���� ������ �־��ֱ� ����.
		PQ[v].pop();
	}
}

void sollin() {
	Sets sets(NNODES);
	int nedges = 0;
	while (nedges < NNODES - 1) {
		for (int i = 0; i < NNODES; i++) {
			int current = sets.Find(i);     // ���� i�� ���մ�ǥ!
			if (PQ[current].empty()) throw "No Spanning Tree Exists.";
			Edge e = PQ[current].top(); PQ[current].pop(); //�� ���� ��ǥ�� �켱���� ���� Ƣ���!
			int v1root = sets.Find(e.v1);
			if (current == v1root) { v1root = sets.Find(e.v2); }  //������ v1�� v2�� ���� ��ǥ Ƣ���~ ��� �����ϳ��� current�� ������������ ������ �𸣴ϱ� �Ѵ� ����.
			if (v1root != current) {
				//sets.Union(v1root, v2root);
				//current = sets.Find(v1root);  //current ���� ���ο� ��ǥ�� ����, v1�� v2�� ũ���� �����̹Ƿ� ���� ���տ� ���ϴ� ���������� �׳��� �� �� ����.
				sets.Union(v1root, current); MoveIntoPQ_EdgesOfNode(v1root, current);   //���� ������ �ְ� ���⸦ �ݺ��� �ʿ�� ����. ���� ������ �켱�������� ���ο� ��ǥ���Է� �־��ش�
				//else {  // �Ѵ� �ƴ� ���� ������ Ȥ�� �𸣴� �־���
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