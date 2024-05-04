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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		
		vector<vector<int>> dp;
		vector<int> tmp(n + 1);
		dp.push_back(tmp);
		dp.push_back(tmp);
		dp.push_back(tmp);
		dp.push_back(tmp);
		
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				int a;
				cin >> a;
				dp[i][j] = a;
			}
		}
		dp[2][1] = dp[0][1];
		dp[3][1] = dp[1][1];

		for (int i = 2; i <= n; i++) {
			dp[2][i] = dp[3][i - 1] + dp[0][i];
			dp[3][i] = dp[2][i - 1] + dp[1][i];

			dp[2][i] = max(dp[2][i], dp[0][i] + dp[3][i - 2]);
			dp[3][i] = max(dp[3][i], dp[1][i] + dp[2][i - 2]);
		}

		cout << max(dp[2][n], dp[3][n]) << '\n';
	}
}