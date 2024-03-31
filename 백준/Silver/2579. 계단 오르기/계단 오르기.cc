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
int dp[3][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int* stair = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		stair[i] = a;

		dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] = dp[0][i - 1] + stair[i];
		dp[2][i] = dp[1][i - 1] + stair[i];
	}

	cout << max(dp[1][n], dp[2][n]);
}