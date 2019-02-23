#ifndef BST_H
#define BST_H
#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
template<class K, class E>
struct Node {
	Node(K ky, E el, Node<K, E> *left = 0, Node<K, E> *right = 0)
		:key(ky), element(el), leftChild(left), rightChild(right),leftsize(1) {}
	Node<K, E> *leftChild;
	K key;
	E element;
	Node<K, E> *rightChild;
	int leftsize;
};

template<class K, class E>
class BST {
public:
	BST() { root = 0; }
	void Insert(K &newkey, E &el) { Insert(this->root, newkey, el); }
	void Preorder() { Preorder(this->root); }
	void Inorder() { Inorder(this->root); }
	void Postorder() { Postorder(this->root); }
	void Levelorder() { Levelorder(this->root); }
	bool Get(const K&, E&);
	void Print();
	bool RankGet(int r, K& k, E& e);
	void Delete(K &oldkey) { Delete(this->root, oldkey); }
	void ThreeWayJoin(BST<K, E>& small, K midkey, E midel, BST<K, E>& big);
	void TwoWayJoin(BST<K, E>& small, BST<K, E>& big);
private:
	void Visit(Node<K, E> *ptr) { cout << ptr->key << ":" << ptr->element << " "; }
	void Insert(Node<K, E>* &ptr, K &newkey, E &el) {
		if (ptr == 0) {
			ptr = new Node<K, E>(newkey, el);
		}
		else if (newkey < ptr->key) {
			ptr->leftsize++;
			Insert(ptr->leftChild, newkey, el);
		}
		else if (newkey > ptr->key) {
			Insert(ptr->rightChild, newkey, el);
		}
		else ptr->element = el;

	}
	void Preorder(Node<K, E>* currentNode) {
		if (currentNode) {
			Visit(currentNode);
			Preorder(currentNode->leftChild);
			Preorder(currentNode->rightChild);
		}
	}
	void Inorder(Node<K, E> *currentNode) {
		stack<Node<K, E>*> s;
		while (1) {
			while (currentNode) {
				s.push(currentNode);
				currentNode = currentNode->leftChild;
			}
			if (s.empty()) return;
			currentNode = s.top();
			s.pop();
			Visit(currentNode);
			currentNode = currentNode->rightChild;
		}
	}
	void Postorder(Node<K, E> *currentNode) {
		if (currentNode) {
			Postorder(currentNode->leftChild);
			Postorder(currentNode->rightChild);
			Visit(currentNode);
		}
	}
	void Levelorder(Node<K, E> *currentNode) {
		queue<Node<K, E>*> q;
		while (currentNode) {
			Visit(currentNode);
			if (currentNode->leftChild) q.push(currentNode->leftChild);
			if (currentNode->rightChild) q.push(currentNode->rightChild);
			if (q.empty()) return;
			currentNode = q.front();
			q.pop();
		}
	}
	void Delete(Node<K,E>* & root, K & oldkey);
	Node<K, E> *root;
};

template <class K, class E>
 bool BST<K, E> ::Get(const K &k, E& e) {
	Node<K, E> *ptr = root;
	while (ptr)
		if (k < ptr->key) ptr = ptr->leftChild;
		else if (k > ptr->key) ptr = ptr->rightChild;
		else { e = ptr->element; return true; }
	return false;
}

 template<class K, class E>
 void BST<K, E>::Print() {
	 cout << endl << "Inorder traversal : "; Inorder();
	 cout << endl << "Postorder traversal : "; Postorder();
	 cout << endl;
 }
 template<class K, class E>
 bool BST<K, E>:: RankGet(int r , K& k, E& e){
	 Node<K, E> *currentNode = root;
	 while (currentNode) {
		 if (r < currentNode->leftsize) currentNode = currentNode->leftChild;
		 else if (r > currentNode->leftsize) {
			 r -= currentNode->leftsize;
			 currentNode = currentNode->rightChild;
		 }
		 else {
			 k = currentNode->key;
			 e = currentNode->element;
			 return true;
		 }
	 }
	 return false;
 }
 template<class K, class E>
 void BST<K, E>::Delete(Node<K,E> * & root, K & oldkey) {
	 Node<K, E> *tempper; Node<K, E> *tempdaddyptr;
	 if (root == 0) return;
	 else if (oldkey < root->key)
		 Delete(root->leftChild, oldkey);
	 else if (oldkey > root->key)
		 Delete(root->rightChild, oldkey);
	 else {
		 if (!root->leftChild && !root->rightChild) {
			 delete root; root = 0; return;
		 }
		 else if (root->leftChild && !root->rightChild) {
			 tempper = root; root = root->leftChild;
			 delete tempper; return;
		 }
		 else if (!root->leftChild && root->rightChild) {
			 tempper = root; root = root->rightChild;
			 delete tempper; return;
		 }
		 else {
			 Node<K, E> *rc = root->rightChild;
			 if (!rc->leftChild) {
				 root->element = rc->element;
				 root->key = rc->key;
				 root->rightChild = rc->rightChild;
				 delete rc;
			 }
			 else {
				 while (rc->leftChild) {
					 tempper = rc;
					 rc = rc->leftChild;
				 }
				 root->element = rc->element;
				 root->key = rc->key;
				 tempper->leftChild = rc->rightChild;
				 delete rc; rc = 0;
			 }
		 }
	 }
	 
	 
	 
	 /* Node<K, E> *ptr = root;
	 Node<K, E> * prptr;
	 while (ptr) {
		 if (oldkey < ptr->key) {
			 prptr = ptr;
			 ptr = ptr->leftChild;
		 }
		 else if (oldkey > ptr->key) {
			 prptr = ptr;
			 ptr = ptr->rightChild;
		 }
		 else break;
	 }
	 Node<K, E> *prNode; Node<K,E>* MaxNode;
	 if (ptr->leftChild) {
		 MaxNode = ptr->leftChild;
		 prNode = ptr;
		 if (MaxNode->rightChild == 0) {
			 ptr->key = MaxNode->key;
			 ptr->element = MaxNode->element;
			 ptr->leftChild = MaxNode->leftChild;
			delete MaxNode;
		 }
		 else {
			 while (MaxNode->rightChild) {
				 prNode = MaxNode;
				 MaxNode = MaxNode->rightChild;
			 }
			 ptr->key = MaxNode->key;
			 ptr->element = MaxNode->element;
			 prNode->rightChild = MaxNode->leftChild;
			 delete MaxNode;
		 }
	 }
	 else {
		 if (prptr->leftChild == ptr)
		 {
			 prptr->leftChild = ptr->rightChild;
		 }
		 else {
			 prptr->rightChild = ptr->rightChild;
		 }
		 delete ptr;
	 }*/
 }
template<class K,class E>
void BST<K, E> ::ThreeWayJoin(BST<K, E>& small, K midkey, E midel, BST<K, E>& big) {
	this->root = new Node<K, E>(midkey, midel, small.root, big.root);
	small.root = big.root = 0;
}
template<class K, class E>
void BST<K,E>::TwoWayJoin(BST<K, E>& small, BST<K, E>& big) {
	if (!small.root) { root = big.root; big.root = 0; return; }
	if (!big.root) { root = small.root; small.root = 0; return; }
	BST<K,E> small2 = small;
	Node<K, E> *ptr = small.root;
	//Node<K, E> *prptr;
	K midkey;
	E midel;
	while (ptr->rightChild) {
		ptr = ptr->rightChild;
	}
	midkey = ptr->key;
	midel = ptr->element;
	small.Delete(ptr->key);
	/*if (small.root->rightChild == 0) {
		Node<K, E> *temp = small.root;
		midkey = small.root->key;
		midel = small.root->element;
		small.root = small.root->leftChild;
		delete temp;
	}
	else {
		while (ptr->rightChild) {
			prptr = ptr;
			ptr = ptr->rightChild;
		}
		midkey = ptr->key;
		midel = ptr->element;
		prptr->rightChild = ptr->leftChild;
		delete ptr;
	}*/
	ThreeWayJoin(small, midkey, midel, big);
	small.root = 0; big.root = 0;
}
#endif