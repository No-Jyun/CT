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

int n, m;
vector<int> edges[50001];
int chk[50001];
int depth[50001];
int upside[50001];

int Ancestor(int a, int b) {
	if (depth[a] > depth[b]) {
		int t = depth[a] - depth[b];
		while (t--) {
			a = upside[a];
		}
	}
	else if (depth[a] < depth[b]) {
		int t = depth[b] - depth[a];
		while (t--) {
			b = upside[b];
		}
	}

	if (a == b)return a;

	int t = depth[a];
	while (t--) {
		if (upside[a] == upside[b])return upside[a];
		a = upside[a];
		b = upside[b];
	}
}

void BFS() {
	chk[1] = 1;
	depth[1] = 1;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int nowN = q.front();
		q.pop();

		for (int i = 0; i < edges[nowN].size(); i++) {
			int tN = edges[nowN][i];
			if (!chk[tN]) {
				chk[tN] = 1;
				q.push(tN);

				depth[tN] = depth[nowN] + 1;
				upside[tN] = nowN;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	BFS();

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;

		cout << Ancestor(a, b) << '\n';
	}
}