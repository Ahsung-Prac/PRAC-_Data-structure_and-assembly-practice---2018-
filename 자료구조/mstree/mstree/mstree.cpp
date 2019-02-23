#include"mstree.h"
#include<algorithm>
Sets::Sets(int numberOfElements) {
	if (numberOfElements < 2) throw" 2개 이상이어야 함";    //총 원소의 개수..가  두개이상
	n = numberOfElements;
	parent = new int[n];       //0 ~ n-1
	fill(parent, parent + n, -1); // 처음에는 모두가 각각의 헤드,
}
void Sets::Union(int i, int j) { parent[i] = j; } //헤드가 바뀌면서 i 노드가 j에 속함
int Sets::Find(int i) { while (parent[i] >= 0) i = parent[i]; return i; } //i의 헤더를 찾음  parent[i]=-1일떄까지 돌려서. -1일땐 자기자신.
bool Edge :: operator==(Edge & e2) { return (v1 == e2.v1 && v2 == e2.v2); }  //간선이 같으면 트루
bool Edge::operator!=(Edge & e2) { return (v1 != e2.v1 || v2 != e2.v2); }   // 출발 혹은 도착 간선 둘중하나라도 다르면 트루
ostream& operator<<(ostream& os, Edge&e) {
	os << "(" << e.v1 << "," << e.v2 << ") : " << e.weight << endl;  //간선 버텍스
	return os;
}
bool GetEdge(istream& is, const int numnodes, Edge& e) {  //새로운 간선 추가!!
	is >> e.v1 >> e.v2 >> e.weight; if (!is.good()) return false;  //is의 끝나면 false
	if (e.v1 < 0 || e.v1 >= numnodes || e.v2<0 || e.v2 > numnodes || e.v1 == e.v2)
		throw "Incorrect Edge";    // 간선은 0보다 크고  node의 총 수보다는 작다. 즉 새로운 정점추가는 불가.
	if (e.v2 < e.v1) swap(e.v1, e.v2); // 작은 정점부터 나열.
	return true;
}