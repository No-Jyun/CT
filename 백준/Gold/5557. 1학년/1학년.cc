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
int arr[101];
long long dp[21][101];

bool Range(int a) {
	return a >= 0 && a <= 20;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	dp[arr[1]][1] = 1;

	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[j][i - 1] && Range(j + arr[i])) {
				dp[j + arr[i]][i] += dp[j][i - 1];
			}
			if (dp[j][i - 1] && Range(j - arr[i])) {
				dp[j - arr[i]][i] += dp[j][i - 1];
			}
		}
	}
	cout << dp[arr[n]][n - 1];
}