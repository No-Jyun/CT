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

int n;
int dp[50001];

void Start(int a) {
	int sqrN = floor(sqrt(a));
	int i = sqrN;

	if (a == pow(sqrN, 2)) { dp[a] = 1; return; }

	while (i >= sqrN / 2) {
		int sq = pow(i, 2);

		dp[a] = min(dp[a], dp[sq] + dp[a - sq]);
		i--;

		if (dp[a] == 2)return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	fill(dp, dp + 50001, 99999);
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		Start(i);
	}
	cout << dp[n];
}