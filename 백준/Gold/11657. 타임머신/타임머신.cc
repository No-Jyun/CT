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
vector<pair<int, int>> edges[501];
vector<long long> result;

bool UpChk() {
	vector<long long> tmp = result;

	for (int start = 1; start <= n; start++) {
		if (tmp[start] != 4000000000) {
			for (int i = 0; i < edges[start].size(); i++) {
				int end = edges[start][i].first;
				int cost = edges[start][i].second;
				if (tmp[end] > (tmp[start] + cost))
					tmp[end] = tmp[start] + cost;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (result[i] != tmp[i])return true;
	}
	return false;
}

void BellmanFord() {
	result[1] = 0;
	for (int k = 1; k < n; k++) {
		for (int start = 1; start <= n; start++) {
			if (result[start] != 4000000000) {
				for (int i = 0; i < edges[start].size(); i++) {
					int end = edges[start][i].first;
					int cost = edges[start][i].second;
					if (result[end] > result[start] + cost)
						result[end] = result[start] + cost;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}

	vector<long long> t(n + 1, 4000000000);
	result = t;

	BellmanFord();
	if (UpChk()) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (result[i] == 4000000000)cout << -1 << '\n';
			else cout << result[i] << '\n';
		}
	}
}