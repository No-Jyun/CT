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

int tc, n, m, w;
vector<pair<int, int>> v[501];
vector<int> pos;
int result[501];

void BellmanFord(int index) {
	result[index] = 0;
	for (int k = 1; k < n; k++) {
		for (int start = 1; start <= n; start++) {
			if (result[start] != INTMAX) {
				for (int i = 0; i < v[start].size(); i++) {
					int end = v[start][i].first;
					int cost = v[start][i].second;
					if (result[end] > result[start] + cost)
						result[end] = result[start] + cost;
				}
			}
		}
	}
}

void Chk() {
	for (int i = 0; i < pos.size(); i++) {
		fill(result, result + 501, INTMAX);
		BellmanFord(pos[i]);
		if (result[pos[i]] < 0) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;
	while (tc--) {
		pos.clear();
		fill(result, result + 501, INTMAX);
		for (int i = 0; i <= 500; i++)v[i].clear();
		cin >> n >> m >> w;

		int s, e, t;
		for (int i = 1; i <= m; i++) {
			cin >> s >> e >> t;
			v[s].push_back({ e,t });
			v[e].push_back({ s,t });
		}
		for (int i = 1; i <= w; i++) {
			cin >> s >> e >> t;
			pos.push_back(e);
			v[s].push_back({ e,-t });
		}

		Chk();
	}
}