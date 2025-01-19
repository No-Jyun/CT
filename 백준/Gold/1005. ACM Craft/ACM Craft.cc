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

int t, n, k, w;
int duration[1001];
int dp[1001];
vector<int> edges[1001];

int DecT(int index) {
	if (dp[index] != -1)return dp[index];
	if (edges[index].empty()) return dp[index] = duration[index];
	
	int mT = 0;
	for (int i = 0; i < edges[index].size(); i++) {
		mT = max(mT, DecT(edges[index][i]));
	}
	return dp[index] = mT + duration[index];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		fill(dp, dp + n + 1, -1);
		for (int i = 1; i <= n; i++) {
			cin >> duration[i];
			edges[i].clear();
		}

		while (k--) {
			int a, b;
			cin >> a >> b;
			edges[b].push_back(a);
		}
		cin >> w;

		cout << DecT(w) << '\n';
	}
}