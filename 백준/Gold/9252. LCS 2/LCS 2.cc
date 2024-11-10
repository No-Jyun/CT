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

int dp[1010][1010];
pair<int, int> exP[1010][1010];
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				exP[i][j] = { i,j };
			}
			else {
				if (dp[i][j - 1] > dp[i - 1][j]) {
					dp[i][j] = dp[i][j - 1];
					exP[i][j] = exP[i][j - 1];
				}
				else {
					dp[i][j] = dp[i - 1][j];
					exP[i][j] = exP[i - 1][j];
				}
			}
		}
	}

	cout << dp[a.length()][b.length()] << '\n';
	if (dp[a.length()][b.length()]) {
		stack<char> stk;
		int nowI = exP[a.length()][b.length()].first;
		int nowJ = exP[a.length()][b.length()].second;

		while (nowI && nowJ) {
			stk.push(a[nowI - 1]);
			int ti = exP[nowI - 1][nowJ - 1].first;
			int tj = exP[nowI - 1][nowJ - 1].second;
			nowI = ti;
			nowJ = tj;
		}
		while (!stk.empty()) {
			cout << stk.top();
			stk.pop();
		}
	}
}