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

int k, v, e;
int chk[20001];
vector<int> edges[20001];

bool BFS(int index) {
	queue<int> q;
	q.push(index);
	chk[index] = 1;

	while (!q.empty()) {
		int nowI = q.front();
		q.pop();

		for (int i = 0; i < edges[nowI].size(); i++) {
			if (!chk[edges[nowI][i]]) {
				chk[edges[nowI][i]] = -chk[nowI];
				q.push(edges[nowI][i]);
			}
			else {
				if (chk[edges[nowI][i]] == chk[nowI])return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	while (k--) {
		cin >> v >> e;

		for (int i = 1; i <= v; i++) {
			chk[i] = 0;
			edges[i].clear();
		}

		while (e--) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		bool isB = true;
		for (int i = 1; i <= v; i++) {
			if (!chk[i]) {
				isB = BFS(i);
				if (!isB) break;
			}
		}

		if (isB)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}