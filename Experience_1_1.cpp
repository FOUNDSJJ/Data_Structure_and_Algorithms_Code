#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
	int n1;
	int* arr;
	Node* next;
	Node();
	void build(int n, int* num);
};

Node::Node() {
	next = nullptr;
}

void Node::build(int n, int* num) {
	n1 = n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = num[i];
	next = nullptr;
}

class List {
public:
	Node* head;
	List();
	bool tailinsert(Node* s);
	void display();
};

List::List() {
	head = new Node();
}

bool List::tailinsert(Node* s) {
	Node* p = head;
	while (p->next != nullptr)
		p = p->next;
	p->next = s;
	return true;
}

void List::display() {
	Node* p = head->next;
	while (p != nullptr) {
		for (int i = 0; i < p->n1; i++)
			cout << p->arr[i] << " ";
		cout << endl;
		p = p->next;
	}
}

void Game(List R, List S, int Rn, int Sn) {
	ofstream ofs("abc.out");
	Node* pR = R.head->next;
	Node* pS = S.head->next;
	while (pR != nullptr) {
		while (pS != nullptr) {
			if (pR->arr[Rn - 1] > pS->arr[Sn - 1]) {
				for (int i = 0; i < pR->n1; i++)
					ofs << pR->arr[i] << " ";
				for (int i = 0; i < pS->n1; i++)
					ofs << pS->arr[i] << " ";
				ofs << endl;
			}
			pS = pS->next;
		}
		pS = S.head->next;
		pR = pR->next;
	}
	ofs.close();
	return;
}

int main() {
	ifstream ifs("in.txt");
	List R, S;
	int m, n;
	ifs >> m >> n;
	Node* s = new Node[m];
	int* num = new int[n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			ifs >> num[j];
		}
		s[i].build(n, num);
		R.tailinsert(&s[i]);
	}
	ifs >> m >> n;
	Node* s1 = new Node[m];
	int* num1 = new int[n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			ifs >> num1[j];
		}
		s1[i].build(n, num1);
		S.tailinsert(&s1[i]);
	}
	int Rn, Sn;
	ifs >> Rn >> Sn;
	ifs.close();
	Game(R, S, Rn, Sn);
	return 0;
}

