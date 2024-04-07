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
int dp[3][10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
		dp[1][i] = dp[0][i - 1] + a;
		dp[2][i] = dp[1][i - 1] + a;
	}

	cout << max(dp[0][n], max(dp[1][n], dp[2][n]));
}