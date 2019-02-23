#ifndef MAXHEAP_H
#define MAXHEAP_H
#include<iostream>
#include<algorithm>
using namespace std;

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize);

template<class T>
class MaxHeap {
public:
	MaxHeap(int theCapacity =10);
	void Push(const T& e);
	void Pop();
	bool IsEmpty() { return heapSize == 0; }
	T Top() { return heap[1]; }
private:
	int heapSize;
	int capacity;
	T *heap;

	template<class T2>
	friend ostream& operator<< (ostream&, MaxHeap<T2>&);
};

template<class T>
ostream& operator<< (ostream& os, MaxHeap<T>& H) {
	os << "<Heap Contents>";
	for (int i = 1; i <= H.heapSize; i++)
		os << i << ":" << H.heap[i] << " ";
	os << endl;
	return os;
}

template<class T>
MaxHeap<T>::MaxHeap(int theCapacity) :heapSize(0) {
	if (theCapacity < 1) throw "Must be +ve";
	capacity = theCapacity;
	heap = new T[capacity + 1];
}

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize) {
	T *temp = new T[newSize];
	/*for (int i = 0; i < oldSize; i++) {
		temp[i] = a[i];
	}*/
	int len = min(oldSize, newSize);
	copy(a, a + len, temp);
	delete[] a;
	a = temp;
}

template<class T>
void MaxHeap<T>::Push(const T& e) {
	if (heapSize == capacity) {
		ChangeSize1D(heap, capacity + 1, 2 * capacity + 1);
		capacity *= 2;
	}
	int currentNode = ++heapSize;
	while (currentNode > 1 && heap[currentNode / 2] < e)
	{
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	heap[currentNode] = e;
}
template<class T>
void MaxHeap<T>::Pop() {
	if (IsEmpty())throw"Heap is empty.Cannot delete";
	T lastE = heap[heapSize--];
	int currentNode = 1;
	int child = 2;
	while (child <= heapSize) {
		if (child < heapSize&&heap[child] < heap[child + 1]) child++;

		if (lastE >= heap[child]) break;

		heap[currentNode] = heap[child];
		currentNode = child; child *= 2;
	}
	heap[currentNode] = lastE;
}
#endif