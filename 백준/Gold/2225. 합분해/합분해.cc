#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n;
int k;
int modular = 1000000000;

int pascal[201][201];
long long dp[201];

int Pascal(int a, int b) {
	if (pascal[a][b])return pascal[a][b];

	return pascal[a][b] = (Pascal(a - 1, b) + Pascal(a - 1, b - 1)) % modular;
}


int main() {
	cin >> n >> k;

	for (int i = 0; i <= 200; i++) {
		pascal[i][0] = 1;
		pascal[i][i] = 1;
	}

	for (int i = 1; i <= k && i <= n; i++) {
		dp[i] = Pascal(n - 1, i - 1) % modular;
	}

	int tmp = 0;
	for (int j = k; j >= 1; j--) {
		dp[0] += (dp[j] * Pascal(k, tmp++)) % modular;
		dp[0] %= modular;
	}
	cout << dp[0];
}