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
using namespace std;

struct CharNode {
	CharNode* left = NULL;
	CharNode* right = NULL;
	char data = 0;
	CharNode(char e) { data = e; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	CharNode* sNode = new CharNode('0');
	CharNode* first = sNode;
	for (int i = 0; i < s.length(); i++) {
		sNode->data = s[i];
		sNode->right = new CharNode('0');
		sNode->right->left = sNode;
		sNode = sNode->right;
	}
	int a;
	cin >> a;
	while (a--) {
		char edit;
		cin >> edit;

		switch (edit) {
		case 'L':
			if (sNode->left)sNode = sNode->left;
			break;
		case 'D':
			if (sNode->right)sNode = sNode->right;
			break;
		case 'B':
			if (sNode->left == first) {
				first = sNode;
				sNode->left = NULL;
			}
			else if (sNode != first) {
				sNode->left = sNode->left->left;
				sNode->left->right = sNode;
			}
			break;
		default:
			cin >> edit;
			if (sNode == first) {
				sNode->left = new CharNode(edit);
				first = sNode->left;
				first->right = sNode;
			}
			else {
				CharNode* tmp = sNode->left;
				tmp->right = new CharNode(edit);
				sNode->left = tmp->right;
				tmp->right->left = tmp;
				tmp->right->right = sNode;
			}
			break;
		}
	}
	while (first->data != '0') {
		cout << first->data;
		first = first->right;
	}
}