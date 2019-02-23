#include<iostream>
#include<algorithm>
using namespace std;
template <class T>
void PrintArray(T *a, const int n) {
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

template<class T> //heapsort를 위한 조정 함수
void Adjust(T *a, const int root, const int n) {
	T e = a[root];
	int j;
	for (j = 2 * root; j <= n; j *= 2) {
		if (j < n && a[j] < a[j + 1]) j++;
		if (e >= a[j]) break;
		a[j / 2] = a[j];
	}
	a[j / 2] = e;
}

template<class T>
void HeapSort(T *a, const int n) {
	for (int i = n / 2; i >= 1; i--) {
		Adjust(a, i, n);
	}
	for (int i = n - 1; i >= 1; i--) {
		swap(a[1], a[i + 1]);
		Adjust(a, 1, i);
		PrintArray(a, i);
	}
}

template<class T>
void BubbleSort1(T *a, int n) {
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	}
}

template<class T> //연속으로 정렬된 곳은 다음에 검사 하지 않음
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
template<class T>
void Insertsort(T *a, int n) {
	for (int j = 1; j <= n; j++) {
		T val = a[j];
		int i = j - 1;
		while (i >= 0 && val < a[i]) {
			a[i + 1] = a[i];
			i--;

		}
		a[i + 1] = val;
	}
}
template<class T>
void QuickSort(T *a, int left, int right) {
	if (left < right) {
		T val = a[left];
		int i = left;
		int j = right + 1;
		do {
			do i++; while (val > a[i]);
			do j--; while (val < a[j]);
			if (i < j) {
				swap(a[i], a[j]);
			}
		} while (i < j);
		a[left] = a[j];
		a[j] = val;
		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}

int main() {
	cout << "-----HeapSort-----" << endl<<endl;
	int a[] = { 0, 26, 5,77,1,61,11,59,15,48,19 };
	int n = sizeof(a) / sizeof(int) - 1;
	cout << "Before HeapSorting: "; PrintArray(a, n);
	HeapSort(a, n);
	cout << "After HeapSorting : "; PrintArray(a, n);
	cout << endl;

	cout << "-----BubbleSort-----" << endl << endl;
	int a1[] = { 0,26,5,77,1,61,11,59,15,48,19 };
	int b[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int n1 = sizeof(a) / sizeof(int) - 1;
	cout << "Before Bubble_1_Sorting :"; PrintArray(a1, n1);
	BubbleSort1(a1, n1);
	cout << "After Bubble_1_sorting : "; PrintArray(a1, n1);
	cout << endl;

	cout << "Before Bubble_2_Sorting :"; PrintArray(b, n1);
	BubbleSort2(b, n1);
	cout << "After Bubble_2_sorting : "; PrintArray(b, n1);
	cout << endl;

	cout << "-----InsertSort-----" << endl << endl;
	int a2[] = { 0, 26, 5,77,1,61,11,59,15,48,19 };
	int n2 = sizeof(a) / sizeof(int) - 1;
	cout << "Before InsertSorting: "; PrintArray(a2, n2);
	Insertsort(a2, n2);
	cout << "After InsertSorting : "; PrintArray(a2, n2);
	cout << endl;

	cout << "-----QuickSort-----" << endl << endl;
	int a3[] = { 0, 26, 5,77,1,61,11,59,15,48,19 };
	int n3 = sizeof(a) / sizeof(int) - 1;
	cout << "Before QuickSorting: "; PrintArray(a3, n3);
	QuickSort(a3,0,n3);
	cout << "After QuickSorting : "; PrintArray(a3, n3);
	cout << endl;



	
}