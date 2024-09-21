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

int n;
int buildT[501];
int ans[501];
vector<int> edges[501];

void DP(int index) {
	if (edges[index].empty()) {
		ans[index] = buildT[index];
		return;
	}

	int maxT = 0;
	for (int i = 0; i < edges[index].size(); i++) {
		if (!ans[edges[index][i]])DP(edges[index][i]);

		maxT = max(maxT, ans[edges[index][i]]);
	}
	ans[index] = maxT + buildT[index];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> buildT[i] >> a;
		while (a != -1) {
			edges[i].push_back(a);
			cin >> a;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!ans[i])DP(i);
	}
	
	for (int i = 1; i <= n; i++)cout << ans[i] << '\n';
}