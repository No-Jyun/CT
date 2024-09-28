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

int n, result;
vector<pair<int, int>> edges[10001];
bool chk[10001];

void DFS(int index, int sum) {
	chk[index] = 1;

	if (edges[index].size() == 1) {
		result = max(result, sum);
	}

	for (int i = 0; i < edges[index].size(); i++) {
		if (!chk[edges[index][i].first]) {
			DFS(edges[index][i].first, sum + edges[index][i].second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) {
		if (edges[i].size() == 1) {
			fill(chk, chk + n + 1, 0);
			DFS(i, 0);
		}
	}
	cout << result;
}