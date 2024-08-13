#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <tuple>
#include <math.h>
using namespace std;

int n;
int day[1500002];
int money[1500002];
int dp[1500002];

bool Range(int a) {
	return a <= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> day[i] >> money[i];

	for (int i = n; i >= 1; i--) {
		if (Range(i + day[i] - 1)) {
			dp[i] = max(dp[i + 1], money[i] + dp[i + day[i]]);
		}
		else dp[i] = dp[i + 1];
	}

	cout << dp[1];
}