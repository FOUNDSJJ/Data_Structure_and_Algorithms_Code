#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class member {
public:
	int id;
	int Fi;
	int Si;
	bool flag;
	member* next;
	member();
	member(int);
	void build(int, int, int);
};

member::member() {
	next = nullptr;
	flag = true;
}

member::member(int i) {
	id = i;
	flag = true;
	next = nullptr;
}

void member::build(int i, int F, int S) {
	id = i;
	Fi = F;
	Si = S;
	flag = true;
}

class Teamqueue {
private:
	member* front;
	member* rear;
	int count;
public:
	Teamqueue();
	~Teamqueue();
	bool push(int);
	bool pop(int&);
	void showqueue();
};

Teamqueue::Teamqueue() {
	front = nullptr;
	rear = nullptr;
	count = 0;
}

Teamqueue::~Teamqueue() {
	member* pre = front;
	member* oldpre;
	if (pre != nullptr) {
		if (pre == rear)
			delete pre;
		else {
			while (pre != nullptr) {
				oldpre = pre;
				pre = pre->next;
				delete oldpre;
			}
		}
	}
	front = nullptr;
	rear = nullptr;
}

bool Teamqueue::push(int i) {
	count++;
	member* s = new member(i);
	if (front == nullptr && rear == nullptr) {
		front = s;
		rear = s;
		return true;
	}
	else {
		rear->next = s;
		rear = s;
		return true;
	}
}

bool Teamqueue::pop(int& i) {
	if (front == nullptr)
		return false;
	else {
		if (front == rear) {
			i = front->id;
			delete front;
			front = nullptr;
			rear = nullptr;
			count--;
			return true;
		}
		else {
			member* p = front;
			member* oldnext = p->next;
			i = p->id;
			delete p;
			front = oldnext;
			count--;
			return true;
		}
	}
}

void Teamqueue::showqueue() {
	member* p = front;
	while (p != nullptr) {
		cout << p->id << " ";
		p = p->next;
	}
}

int calculate(int time, int Fi, int Si) {
	return Fi + (time - 1) * Si;
}

void Game(int num_of_player, member* player, Teamqueue& tq) {
	int num;
	for (int i = 1; i <= num_of_player; i++) {
		for (int j = 0; j < num_of_player - 1; j++) {
			while (player[j].flag == false) {
				j++;
				if (j == num_of_player - 1) {
					tq.push(player[j].id);
					player[j].flag = false;
					goto FLAG1;
				}
			}
			int a = j + 1;
		FLAG:
			if (a > num_of_player - 1) {
				tq.push(player[j].id);
				player[j].flag = false;
				goto FLAG1;
			}
			while (a <= num_of_player - 1 && player[a].flag == false) {
				a++;
				if (a >= num_of_player - 1) {
					if (player[a].flag == false) {
						tq.push(player[j].id);
						player[j].flag = false;
						goto FLAG1;
					}
				}
			}
			if (calculate(i, player[j].Fi, player[j].Si) > calculate(i, player[a].Fi, player[a].Si)) {
				a++;
				goto FLAG;
			}
			if (calculate(i, player[j].Fi, player[j].Si) < calculate(i, player[a].Fi, player[a].Si)) {
				j = a;
				a++;
				goto FLAG;
			}
			if (calculate(i, player[j].Fi, player[j].Si) == calculate(i, player[a].Fi, player[a].Si)) {
				if (player[j].id < player[a].id) {
					a++;
				}
				else {
					j = a;
					a++;
				}
				goto FLAG;
			}

		}
	FLAG1:
		num = 0;
	}
}

int main() {
	fstream ifs("in.txt");
	Teamqueue tq;
	int num_of_player;
	ifs >> num_of_player;
	member* player = new member[num_of_player];
	int i = 0;
	for (i; i < num_of_player; i++) {
		int F, S;
		ifs >> F >> S;
		player[i].build(i + 1, F, S);
	}
	Game(num_of_player, player, tq);
	tq.showqueue();
	return 0;
}
