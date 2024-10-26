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

int n, c;
int cost[21];
int effect[21];
int dp[1201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c >> n;
	for (int i = 1; i <= n; i++)cin >> cost[i] >> effect[i];

	fill(dp, dp + 1201, 999999999);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; effect[i] * j <= 1200; j++) {
			dp[effect[i] * j] = min(dp[effect[i] * j], cost[i] * j);
		}
	}

	for (int i = 1; i <= 1200; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
		if (i >= c) {
			dp[0] = min(dp[0], dp[i]);
		}
	}
	cout << dp[0];
}