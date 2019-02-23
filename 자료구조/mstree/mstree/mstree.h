#ifndef MSTREE_H
#define MSTREE_H
#include<iostream>
using namespace std;

class Sets {    // 분리된 집합들의 set들
public:
	Sets(int);
	void Union(int i, int j);
	int Find(int i);
private:
	int *parent;
	int n;  //집합 원소의 개수
};
struct Edge {     //간선


	int v1, v2;
	double weight;
	bool operator==(Edge& e2);
	bool operator!=(Edge& e2);
};
struct Compare {
	bool operator()(Edge el, Edge e2) {
		return el.weight > e2.weight;

	}
};
ostream& operator<<(ostream& os, Edge& e);
bool GetEdge(istream& is, const int numnodes, Edge& e);
#endif

