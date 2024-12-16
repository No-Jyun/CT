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
int arr[201];
int dp[201];
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int t = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j]) t = max(t, dp[j] + 1);
		}
		dp[i] = t;
		result = max(result, dp[i]);
	}

	cout << n - result;
}