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
using namespace std;

int v, e;
int k;
int vertex[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	cin >> k;

	vector<pair<int, int>> edges[20001];
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({ v,w });
	}
	fill(vertex, vertex + v + 1, -1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,k });

	while (!q.empty()) {
		int nowV = q.top().second;
		int distance = q.top().first;
		q.pop();

		if (vertex[nowV] == -1) {
			vertex[nowV] = distance;

			for (auto tmp : edges[nowV]) {
				q.push({ distance + tmp.second,tmp.first });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (vertex[i] == -1)cout << "INF" << '\n';
		else cout << vertex[i] << '\n';
	}
}