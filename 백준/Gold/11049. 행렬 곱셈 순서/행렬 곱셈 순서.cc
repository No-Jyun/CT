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

int n, result;
pair<int, int> arr[501];
int dp[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	fill(dp[0], dp[n + 1], INTMAX);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
		if (i != 1) {
			int sum = arr[i].first * arr[i].second * arr[i - 1].first;
			dp[i - 1][i] = sum;
		}
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n == 2) {
		cout << dp[1][2];
		return 0;
	}

	for (int k = 3; k <= n; k++) {
		for (int i = 0; k + i <= n; i++) {
			int minI = i + 1;
			int maxI = k + i;
			for (int j = i + 1; j < maxI; j++) {
				int sum = 0;
				if (j == minI) {
					sum += arr[minI].first * arr[minI].second * arr[maxI].second;
					sum += dp[minI + 1][maxI];
				}
				else if (j == maxI - 1) {
					sum += dp[minI][j];
					sum += arr[maxI].first * arr[maxI].second * arr[minI].first;
				}
				else {
					sum += dp[minI][j] + dp[j + 1][maxI];
					sum += arr[minI].first * arr[j].second * arr[maxI].second;
				}
				dp[minI][maxI] = min(dp[minI][maxI], sum);
			}
		}
	}

	cout << dp[1][n];
}