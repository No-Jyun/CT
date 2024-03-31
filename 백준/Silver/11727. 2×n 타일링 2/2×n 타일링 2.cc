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
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (i % 2) {
			dp[i] = (dp[i - 1] * 2 - 1) % 10007;
		}
		else {
			dp[i] = (dp[i - 1] * 2 + 1) % 10007;
		}
	}
	cout << dp[n];
}