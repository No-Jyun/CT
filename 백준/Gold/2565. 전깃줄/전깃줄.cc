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
int arr[501];
int dp[501];
int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	for (int i = 1; i <= 500; i++) {
		if (arr[i]) {
			int maxim = 0;
			for (int j = i - 1; j >= 1; j--) {
				if (arr[j] && arr[i] > arr[j])maxim = max(maxim, dp[j]);
			}
			dp[i] = maxim + 1;
			result = max(result, dp[i]);
		}
	}
	cout << n - result;
}