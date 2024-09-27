#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
	int val;
	char stack;
	Node* next;
	Node();
	Node(int v, char t);
	Node(int v);
};

Node::Node() {
	next = nullptr;
}

Node::Node(int v) {
	val = v;
	next = nullptr;
}

Node::Node(int v, char t) {
	val = v;
	stack = t;
	next = nullptr;
}

class list {
public:
	list();
	void headinsert(int, char);
	int pop(char);
	~list();
	void change(char, char);
private:
	Node* head;
	int count;
};

list::list() {
	head = new Node();
	count = 0;
}

list::~list() {
	Node* p = head;
	while (p != nullptr) {
		Node* q = p->next;
		delete p;
		p = q;
	}
}

void list::change(char c1, char c2) {
	Node* p = head->next;
	while (p != nullptr) {
		if (p->stack == c2)
			p->stack = c1;
		p = p->next;
	}
}

int list::pop(char t) {
	int e;
	Node* p = head;
	Node* q;
	while (p->next != nullptr) {
		if (p->next->stack == t) {
			e = p->next->val;
			q = p->next;
			p->next = p->next->next;
			delete q;
			return e;
		}
		p = p->next;
	}
	return 0;
}

void list::headinsert(int v, char t) {
	Node* s = new Node(v, t);
	Node* p = head->next;
	if (count == 0) {
		count++;
		head->next = s;
		return;
	}
	else {
		count++;
		s->next = p;
		head->next = s;
		return;
	}
}

int main() {
	int n;
	ifstream ifs("in.txt");
	list C;
	ifs >> n;
	string* txtLine = new string[n + 1];
	for (int i = 0; i < n + 1; i++) {
		getline(ifs, txtLine[i]);
	}
	ifs.close();
	for (int i = 1; i <= n; i++) {
		if ((int)(txtLine[i].find("push A")) != -1) {
			txtLine[i].erase(0, 7);
			int x;
			x = stoi(txtLine[i]);
			C.headinsert(x, 'A');
		}
		if ((int)(txtLine[i].find("push B")) != -1) {
			txtLine[i].erase(0, 7);
			int x;
			x = stoi(txtLine[i]);
			C.headinsert(x, 'B');
		}
		if ((int)(txtLine[i].find("pop A")) != -1) {
			int e = C.pop('A');
			cout << e << endl;
		}
		if ((int)(txtLine[i].find("pop B")) != -1) {
			int e = C.pop('B');
			cout << e << endl;
		}
		if ((int)(txtLine[i].find("merge A B")) != -1) {
			C.change('A', 'B');
		}
		if ((int)(txtLine[i].find("merge B A")) != -1) {
			C.change('B', 'A');
		}
	}
	return 0;
}
