// template�� ���ؼ� sort�� �켱���� ť���� ��ü(�Լ� ����)�� ���ؼ� ������ ���� �� �ְ�
// operate()�� ���ؼ� ����!

#include<iostream>
using namespace std;

struct Cmp {
	int operator()(int a, int b) {
		cout << "���۷�����, x+y = "<<a+b<<endl;
		return a + b;
	}
}cmp;

template<class T>
int ptr(int a, T b) {
	cout << a << " + �Էµ� ��ü(x,y)" << endl;
	int x;
	int y;
	cout << "x �Է�:"; 
	cin >> x;
	cout << "y �Է�:"; cin >> y;
	return a + b(x, y);
}
int ppp(int a, int b) {
	cout << "x,y ���� x*y = "<<a*b<<endl;
	return a * b;
}

int main() {
	cout << "��Ģ���� �Լ��� ��ü operater ���" << endl;
	cout << ptr(3, cmp)<<endl;
	cout << endl << "��Ģ���� �Լ��� ��ü �Լ� ���" << endl;
	cout << ptr(5, ppp) << endl;

}