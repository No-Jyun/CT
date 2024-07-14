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
bool home[17][17];
int dp[3][17][17];

bool Possible(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= n && !home[a][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)cin >> home[i][j];
	}
	dp[0][1][2] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 3; k++) {
				if (Possible(i + 1, j + 1) && Possible(i, j + 1) && Possible(i + 1, j)) {
					dp[2][i + 1][j + 1] += dp[k][i][j];
				}
				
				if (k != 1 && Possible(i, j + 1)) {
					dp[0][i][j + 1] += dp[k][i][j];
				}

				if (k !=  0&& Possible(i + 1, j)) {
					dp[1][i + 1][j] += dp[k][i][j];
				}
			}
		}
	}

	cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n];
}