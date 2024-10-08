#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class member {
public:
	int name_of_team;
	string number;
	member* next;
	member(int, string);
};

member::member(int name, string num) {
	name_of_team = name;
	number = num;
	next = nullptr;
}

class Teamqueue {
private:
	member* front;
	member* rear;
	int count;
public:
	Teamqueue();
	~Teamqueue();
	member* seek(int);
	bool push(int, string);
	bool pop(string&);
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

member* Teamqueue::seek(int name) {
	if (count == 0)
		return nullptr;
	else {
		member* p = front;
		member* oldp;
		while (p != nullptr) {
			if (name == p->name_of_team) {
				if (p->next == nullptr || p->next->name_of_team != name)
					return p;
				while (p->name_of_team == name) {
					oldp = p;
					p = p->next;
					if (p == nullptr)
						return oldp;
					if (p->name_of_team != name)
						return oldp;
				}
			}
			oldp = p;
			p = p->next;
		}
		return oldp;
	}
}

bool Teamqueue::push(int name, string number) {
	count++;
	member* s = new member(name, number);
	if (front == nullptr && rear == nullptr) {
		front = s;
		rear = s;
		return true;
	}
	if (front == rear) {
		front->next = s;
		rear = s;
		return true;
	}
	else {
		member* p = seek(name);
		if (p == rear) {
			p->next = s;
			rear = s;
		}
		else {
			member* oldnext = p->next;
			s->next = oldnext;
			p->next = s;
		}
		return true;
	}
}

bool Teamqueue::pop(string& number) {
	if (front == nullptr)
		return false;
	else {
		if (front == rear) {
			number = front->number;
			delete front;
			front = nullptr;
			rear = nullptr;
			count--;
			return true;
		}
		else {
			member* p = front;
			member* oldnext = p->next;
			number = p->number;
			delete p;
			front = oldnext;
			count--;
			return true;
		}
	}
}

int main() {
	fstream ifs("in.txt");
	int num_of_teams;
	ifs >> num_of_teams;
	string* line = new string[num_of_teams];
	int* name_of_team = new int[num_of_teams];
	int total = 0;
	for (int i = 0; i < num_of_teams; i++) {
		ifs >> name_of_team[i];
		getline(ifs, line[i]);
		total += name_of_team[i];
	}
	int total_of_instruction = 0;
	string* instruction = new string[(2 * total + 1)];
	for (int m = 0; m < (2 * total) + 1; m++) {
		getline(ifs, instruction[m]);
		if (instruction[m] == "STOP") {
			total_of_instruction = m;
			break;
		}
	}
	Teamqueue tq;
	for (int i = 0; i < total_of_instruction; i++) {
		if (instruction[i].find("ENQUEUE") != -1) {
			instruction[i].erase(0, 8);
			int name;
			for (int j = 0; j < num_of_teams; j++) {
				if (line[j].find(instruction[i]) != -1) {
					tq.push(j, instruction[i]);
				}
			}
		}
		if (instruction[i].find("DEQUEUE") != -1) {
			string temp;
			tq.pop(temp);
			cout << temp << endl;
		}
	}
	return 0;
}