// template를 통해서 sort나 우선순위 큐같이 객체(함수 포함)를 통해서 기준을 받을 수 있게
// operate()를 통해서 구현!

#include<iostream>
using namespace std;

struct Cmp {
	int operator()(int a, int b) {
		cout << "오퍼레이터, x+y = "<<a+b<<endl;
		return a + b;
	}
}cmp;

template<class T>
int ptr(int a, T b) {
	cout << a << " + 입력된 객체(x,y)" << endl;
	int x;
	int y;
	cout << "x 입력:"; 
	cin >> x;
	cout << "y 입력:"; cin >> y;
	return a + b(x, y);
}
int ppp(int a, int b) {
	cout << "x,y 곱함 x*y = "<<a*b<<endl;
	return a * b;
}

int main() {
	cout << "사칙연산 함수에 객체 operater 사용" << endl;
	cout << ptr(3, cmp)<<endl;
	cout << endl << "사칙연산 함수에 객체 함수 사용" << endl;
	cout << ptr(5, ppp) << endl;

}