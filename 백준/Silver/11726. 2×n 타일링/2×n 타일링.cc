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
#define MAX 3999999979
#define ULL unsigned long long
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int* dp = new int[n + 1];

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n];
}