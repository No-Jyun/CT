#include <iostream>
#include <vector>
using namespace std;

struct Node {
	Node() {}
	bool valid = true;
	vector<Node*> child;
};

int n, k;
Node* tree[50];
int result;
Node* root;

void DFS(Node* nowN) {
	if (!nowN)return;
	if (nowN->valid == false)return;

	if (nowN->child.size() == 0) {
		result++;
		return;
	}

	if (nowN->child.size() == 1 && nowN->child[0]->valid == false) {
		result++;
		return;
	}

	for (int i = 0; i < nowN->child.size(); i++)DFS(nowN->child[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 50; i++)tree[i] = new Node();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == -1)root = tree[i];
		else {
			tree[k]->child.push_back(tree[i]);
		}
	}
	cin >> k;
	tree[k]->valid = false;

	DFS(root);
	cout << result;
}