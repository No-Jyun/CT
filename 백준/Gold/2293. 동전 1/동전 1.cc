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
using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		if (coin[i] > k) coin[i] = 0;
	}

	sort(coin, coin + n + 1);

	for (int i = 1; i <= n; i++) {
		if (coin[i]) {
			for (int j = 1; j <= k; j++) {
				if (j + coin[i] <= k)dp[j + coin[i]] += dp[j];
				if (j % coin[i] == 0)dp[j]++;
			}
		}
	}

	cout << dp[k];
}