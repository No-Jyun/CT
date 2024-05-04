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

int dp[21][21][21];

int w(int a, int b, int c) {
	if (!dp[a][b][c]) {
		if (a <= 0 || b <= 0 || c <= 0) { dp[a][b][c] = 1; }

		else if (a < b && b < c)dp[a][b][c] = w(a, b, c - 1) +
			w(a, b - 1, c - 1) - w(a, b - 1, c);

		else dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
			w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	return dp[a][b][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && b == c && c == -1)return 0;

		int result = 0;
		if (a <= 0 || b <= 0 || c <= 0)result = 1;
		else if (a > 20 || b > 20 || c > 20) result = w(20, 20, 20);
		else result = w(a, b, c);

		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
	}
}