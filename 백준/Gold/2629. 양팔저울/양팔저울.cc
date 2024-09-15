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

int n, m;
int balls[31];
int gold[8];
bool dp[31][40001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> balls[i];
	cin >> m;
	for (int i = 1; i <= m; i++)cin >> gold[i];

	dp[1][balls[1]] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 40000; j++) {
			if (dp[i - 1][j]) {
				dp[i][j] = 1;
				int nowBall = balls[i];
				dp[i][nowBall] = 1;

				dp[i][j + nowBall] = 1;
				dp[i][abs(j - nowBall)] = 1;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		if (dp[n][gold[i]])cout << 'Y' << ' ';
		else cout << 'N' << ' ';
	}
}