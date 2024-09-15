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

int n;
ULL dp[16];
int d[16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n % 2)cout << 0;
	else {
		n /= 2;
		dp[1] = 3;		d[1] = 0;
		dp[2] = 11;		d[2] = 2;
		dp[3] = 41;		d[3] = 8;
		dp[4] = 153;	d[4] = 30;
		for (int i = 5; i <= n; i++) {
			d[i] = d[i - 1] * 4 - d[i - 2];
			dp[i] = dp[i - 1] * 3 + d[i];
		}

		cout << dp[n];
	}
}