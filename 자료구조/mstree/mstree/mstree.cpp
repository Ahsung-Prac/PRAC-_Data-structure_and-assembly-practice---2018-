#include"mstree.h"
#include<algorithm>
Sets::Sets(int numberOfElements) {
	if (numberOfElements < 2) throw" 2�� �̻��̾�� ��";    //�� ������ ����..��  �ΰ��̻�
	n = numberOfElements;
	parent = new int[n];       //0 ~ n-1
	fill(parent, parent + n, -1); // ó������ ��ΰ� ������ ���,
}
void Sets::Union(int i, int j) { parent[i] = j; } //��尡 �ٲ�鼭 i ��尡 j�� ����
int Sets::Find(int i) { while (parent[i] >= 0) i = parent[i]; return i; } //i�� ����� ã��  parent[i]=-1�ϋ����� ������. -1�϶� �ڱ��ڽ�.
bool Edge :: operator==(Edge & e2) { return (v1 == e2.v1 && v2 == e2.v2); }  //������ ������ Ʈ��
bool Edge::operator!=(Edge & e2) { return (v1 != e2.v1 || v2 != e2.v2); }   // ��� Ȥ�� ���� ���� �����ϳ��� �ٸ��� Ʈ��
ostream& operator<<(ostream& os, Edge&e) {
	os << "(" << e.v1 << "," << e.v2 << ") : " << e.weight << endl;  //���� ���ؽ�
	return os;
}
bool GetEdge(istream& is, const int numnodes, Edge& e) {  //���ο� ���� �߰�!!
	is >> e.v1 >> e.v2 >> e.weight; if (!is.good()) return false;  //is�� ������ false
	if (e.v1 < 0 || e.v1 >= numnodes || e.v2<0 || e.v2 > numnodes || e.v1 == e.v2)
		throw "Incorrect Edge";    // ������ 0���� ũ��  node�� �� �����ٴ� �۴�. �� ���ο� �����߰��� �Ұ�.
	if (e.v2 < e.v1) swap(e.v1, e.v2); // ���� �������� ����.
	return true;
}