#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
void PrintArray(T* a, const int n) {
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}
template<class T>
void BubbleSort1(T *a, int n) {
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	}
}
template<class T>
void BubbleSort2(T* a, int n) {
	int newn;
	while (n > 1) {
		newn = 1;
		for (int i = 1; i < n; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]); newn = i;
			}
		n = newn;
	}
}
#endif
