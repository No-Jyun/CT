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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> v(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int* parent = new int[n + 1];
	fill(parent, parent + n + 1, 0);

	queue<int> q;
	q.push(1);
	parent[1] = -1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int tmp = v[now][i];
			if (!parent[tmp]) {
				parent[tmp] = now;
				q.push(tmp);
			}
		}
	}

	for (int i = 2; i <= n; i++) { cout << parent[i] << '\n'; }
}