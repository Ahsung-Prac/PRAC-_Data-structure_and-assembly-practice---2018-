#include<iostream>
#include<vector>
using namespace std;
void Path(vector<vector<int>> &v,int i,int j) {
	if (i == j) cout << "A"<<i;
	else{
		int k = v[i][j];
		cout << "(";
		Path(v, i, k);
		Path(v, k + 1, j);
		cout << ")";
	}
	//cout << i <<" " ;
}
vector<int> *pt;
int main() {
	int m;
	cout << endl<< "곱할 행렬의 개수 입력:";
	cin >> m;
	cout <<endl<< "( i번째 행렬의 열은 i+1번째 행렬의 행과 같다.)" << endl << endl;
	vector<vector<int>> SW(m, vector<int>(m,0));
	int *D = new int[m+1];
	vector<vector<int>> path(m, vector<int>(m,-1));
	for (int i = 0; i < m; i++) {
		cout << i+1 << " 번째 행렬의 행(d" << i << ")입력:";
		cin >> D[i];
	}
	cout<< "마지막 열(d" << m << ")입력:";
	cin >> D[m];
	//0~m-1 행렬.
	for (int d = 1; d < m; d++) {
		for (int i = 0; i < m - d; i++) {
			int j = i + d;
			SW[i][j] = SW[i][i] + SW[i + 1][j] + D[i] * D[i + 1] * D[j + 1];
			path[i][j] = i;
			for (int k = i+1; k < j; k++) {
				int comp = SW[i][k] + SW[k + 1][j] + D[i] * D[k+1] * D[j+1];
				if (SW[i][j] > comp) {
					SW[i][j] = comp;
					path[i][j] = k;
				}
			}
		}
	}
	cout<<endl<<"최소 연산 횟수:" << SW[0][m - 1]<<endl<<endl;
	Path(path, 0, m - 1);
	cout << endl<<endl;
	system("pause");



}

