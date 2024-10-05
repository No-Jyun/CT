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
int arr[1001];
vector<int> dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	dp[1].push_back(arr[1]);
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			int myS = dp[i].size();
			int exS = dp[j].size();

			if (myS - 1 < exS && dp[j][exS-1] < arr[i]) {
				dp[i] = dp[j];
				dp[i].push_back(arr[i]);
			}
		}

		if (dp[i].empty())dp[i].push_back(arr[i]);

		if (dp[i].size() > dp[0].size()) {
			dp[0] = dp[i];
		}
	}

	cout << dp[0].size() << '\n';
	for (auto it : dp[0]) {
		cout << it << ' ';
	}
}