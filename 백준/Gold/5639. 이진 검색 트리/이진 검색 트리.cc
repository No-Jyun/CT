#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
#define ULL unsigned long long
#define INTMAX 2147483647
using namespace std;

struct Node {
	Node* leftC = NULL;
	Node* rightC = NULL;
	int n = 0;
	Node(int a) { n = a; }
	void Insert(int);
};

void Node::Insert(int num) {
	Node* tmp = this, * after = this;
	Node* ins = new Node(num);

	while (tmp) {
		after = tmp;
		if (tmp->n > num)tmp = tmp->leftC;
		else tmp = tmp->rightC;
	}

	if (after->n > num)after->leftC = ins;
	else after->rightC = ins;
}

void Visit(Node* t) {
	if (!t)return;

	Visit(t->leftC);
	Visit(t->rightC);
	cout << t->n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nowN;
	Node* root = NULL;

	while (cin >> nowN) {
		if (!root) root = new Node(nowN);
		else root->Insert(nowN);
	}

	Visit(root);
}