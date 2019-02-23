#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int number = 7;
int c[8];
vector<int> tt[8];

void bfs(int start) {
	queue<int> q; q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		cout << r << " ";
		for (int i = 0; i < tt[r].size(); i++) {
			int cu = tt[r][i];
			if (!c[cu]) {
				q.push(cu);
				c[cu] = true;
			}
		}
	}
}
void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	cout << x << " ";
	for (int i = 0; i < tt[x].size(); i++) {
		int r = tt[x][i];
		dfs(r);
	}
}
void stackDfs(int start) {
	stack<int> s; s.push(start);
	c[start] = true;
	while (!s.empty()) {
		int r = s.top();
		s.pop();
		cout << r << " ";
		for (int i = tt[r].size() - 1; i >= 0; i--) {
			int cu = tt[r][i];
			if (!c[cu]) {
				s.push(cu);
				c[cu] = true;
			}
		}
	}
}
void push(int x, int y) {
	tt[x].push_back(y);
	tt[y].push_back(x);
}
void cRsert() {
	for (int i = 0; i < 8; i++) {
		c[i] = false;
	}
}
void grapOder(int x) {
	cout << x << " 시작 순회---------------" << endl;
	cout << "bfs:  ";
	bfs(x);
	cRsert();
	cout << endl;
	cout << "dfs:  ";
	dfs(x);
	cout << endl;
	cRsert();
	cout << "Sbfs: ";
	stackDfs(x);
	cout << endl;
	cRsert();
}
int main() {
	tt[1].push_back(2);
	tt[2].push_back(1);
	push(1, 3);
	push(2, 4);
	push(2, 5);
	push(3, 6);
	push(3, 7);
	for (int i = 1; i < 8; i++) {
		grapOder(i);
	}
}

