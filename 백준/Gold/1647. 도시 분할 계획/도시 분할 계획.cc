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

int n, m, cost, maxC;
vector<pair<int, int>> edges[100001];
int chk[100001];
priority_queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	q.push({ 0,1 });
	while (!q.empty()) {
		int c = -q.top().first;
		int a = q.top().second;
		q.pop();

		if (!chk[a]) {
			chk[a] = 1;
			cost += c;
			maxC = max(maxC, c);
			for (int i = 0; i < edges[a].size(); i++) {
				if(!chk[edges[a][i].first])q.push({ -edges[a][i].second,edges[a][i].first });
			}
		}
	}

	cout << cost - maxC;
}