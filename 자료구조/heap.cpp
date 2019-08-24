#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

struct DefaultCMP {
	bool operator()(int a, int b) {
		return a > b;
	}

};

template<class T, class K = DefaultCMP>
struct heap {
	K cmp;
	int size;
	int cap;
	T *heaparr;
	heap(int s = 4) :size(0), cap(s) {
		heaparr = new T[s + 1];
	};
	void updateArrSize() {
		T *tempArry = new T[cap * 2 + 1];
		memcpy(tempArry, heaparr, sizeof(T)*(size + 1));
		//for (int i = 1; i <= size; i++) tempArry[i] = heaparr[i];
		delete[] heaparr;
		heaparr = tempArry;
		cap *= 2;
	}

	T top() {
		if (size <= 0) {
			cout << "비었음" << endl;
		}
		return heaparr[1];
	}

	void push(T sel) {
		if (size >= cap) {
			cout << "늘림" << endl;
			updateArrSize();
		}
		size++;
		int index = size;
		while (index > 1 && cmp(sel, heaparr[index / 2])) {
			heaparr[index] = heaparr[index / 2];
			index /= 2;
		}
		heaparr[index] = sel;

	}

	void pop() {
		if (size == 0) return;

		T sel = heaparr[size]; size--;


		int index;
		if (size > 2 && cmp(heaparr[3], heaparr[2]))index = 3;
		else index = 2;

		while (index < size && cmp(heaparr[index], sel)) {
			heaparr[index / 2] = heaparr[index];
			index *= 2;
			if (index < size && cmp(heaparr[index + 1], heaparr[index])) index++;
		}
		heaparr[index / 2] = sel;

	}
};


struct pp {
	int num;
	char str[100];
	pp() { }
	pp(int a, const char stg[]) {
		num = a;
		strcpy(str, stg);
	}
	void makePP(int a, const char stg[]) {
		num = a;
		strcpy(str, stg);
	}
};

struct cmp {
	bool operator()(pp a, pp b) {
		if (strcmp(a.str, b.str) > 0) return 0;
		else return 1;
	}
}CMP;

int main() {
	char str[100];


	//cout << CMP(a,b);
	heap<int> hp;
	heap<pp, cmp> Hp;

	int b = 1;
	pp t;
	int a;
	cout << "int heap test, 1은 push 0은 종료 나머지 숫자는 pop" << endl << endl;
	while (b) {

		cin >> b;
		if (b == 1) { cin >> a; hp.push(a); }
		else hp.pop();

		cout << "top: " << hp.top() <</* " size: "<<hp.size<< */endl << endl;

		/*for (int i = 1; i <= hp.size; i++) {
			cout << i << ": " << hp.heaparr[i] << "  ";
		}
		cout << endl << endl;*/
	}
	cout << "pp heap test, 1은 push 0은 종료 나머지 숫자는 pop" << endl << endl;
	b = 1;

	while (b) {

		cin >> b;
		if (b == 1) {
			cin >> str;
			t.makePP(1, str);
			Hp.push(t);
		}
		else Hp.pop();

		cout << "top: " << Hp.top().str <</* " size: "<<hp.size<< */endl << endl;

		/*for (int i = 1; i <= hp.size; i++) {
			cout << i << ": " << hp.heaparr[i] << "  ";
		}
		cout << endl << endl;*/
	}

}
