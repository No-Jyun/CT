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

int t, n;
long long arr[501];
ULL dp[501][501];
ULL dp2[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		fill(dp[0], dp[n + 1], INTMAX);
		fill(dp2[0], dp2[n + 1], INTMAX);

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			dp[i][i] = arr[i];
			if (i != 1) {
				dp[i - 1][i] = arr[i] + arr[i - 1];
				dp2[i - 1][i] = dp[i - 1][i];
			}
		}

		for (int k = 3; k <= n; k++) {
			for (int i = 0; k + i <= n; i++) {
				int minI = i + 1;
				int maxI = k + i;
				for (int j = minI; j < maxI; j++) {
					ULL sum = 0;
					ULL sum2 = 0;
					sum += dp[minI][j] + dp[j + 1][maxI];
					sum2 += sum;

					if (j == minI) {
						sum2 += dp2[j + 1][maxI];
					}
					else if (j == maxI - 1) {
						sum2 += dp2[minI][j];
					}
					else {
						sum2 += dp2[minI][j] + dp2[j + 1][maxI];
					}

					if (dp2[minI][maxI] > sum2) {
						dp2[minI][maxI] = sum2;
						dp[minI][maxI] = sum;
					}
				}
			}
		}

		cout << dp2[1][n] << '\n';
	}
}