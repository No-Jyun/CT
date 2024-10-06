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
int arr[51];
int dp[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double a = (double)(arr[j] - arr[i]) / (j - i);
			double b = arr[i] - i * a;
			bool isOnLine = false;

			for (int k = i + 1; k < j; k++) {
				if (k * a + b <= arr[k]) {
					isOnLine = true;
					break;
				}
			}

			if (!isOnLine) {
				dp[i]++;
				dp[j]++;
			}
		}
		dp[0] = max(dp[0], dp[i]);
	}

	cout << dp[0];
}