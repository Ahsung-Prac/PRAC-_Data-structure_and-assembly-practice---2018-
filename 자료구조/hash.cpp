#include<iostream>
#include<list>
#include<cstring>
using namespace std;
#define HTSIZE	137

struct Node{
	Node(char *n, float v) :name(n), val(v){}
	char *name;
	float val;
};
list<Node> HT[HTSIZE];
int hashfcn(char *name){
	return name[0] * name[strlen(name) - 1] % HTSIZE;
}
bool GetFromHT(char *name, float& val){
	int hashval = hashfcn(name);
	list<Node>::iterator iter;
	for (iter = HT[hashval].begin(); iter != HT[hashval].end(); iter++)
		if (!strcmp(iter->name,name))
		{
			val = iter->val; return true;
		}
	return false;
}

void StoreIntoHT(char *name, float val){
	int hashval = hashfcn(name);
	list<Node>::iterator iter;
	for (iter = HT[hashval].begin(); iter != HT[hashval].end(); iter++)
		if (!strcmp(iter->name, name))
		{
			iter->val = val; return;
		}
	HT[hashfcn(name)].push_front(Node(name, val));
}
void PrintValue(char *name){
	float val;
	if (!GetFromHT(name, val))
		cout << name << " does not exist" << endl;
	else
		cout << name << " " << val << endl;
}
int main(){
	StoreIntoHT((char *)"abro", 23);
	StoreIntoHT((char *)"bb", 34.5);
	StoreIntoHT((char *)"haha", 99);
	
	StoreIntoHT((char *)"bb", 1234.5);

	PrintValue((char*)"bb");
	PrintValue((char*)"haha");
	PrintValue((char*)"hoho");
}