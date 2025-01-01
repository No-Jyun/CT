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

int n, m, result = INTMAX;
pair<int, int> arr[101];
int dp[101][10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(dp[0], dp[101], -1);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> arr[i].second;
	for (int i = 1; i <= n; i++)cin >> arr[i].first;
	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n; i++)dp[i][arr[i].first] = arr[i].second;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (dp[i][j] != -1) {
				if (dp[i][j] >= m)result = min(result, j);

				for (int k = i + 1; k <= n; k++) {
					dp[k][j + arr[k].first] = max(dp[k][j + arr[k].first], dp[i][j] + arr[k].second);
				}
			}
		}
	}
	cout << result;
}