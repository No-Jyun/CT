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

vector<int> v[100001];
pair<int, int> arr[100001];
int dp[100001];
int n;
ULL result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first;
		v[arr[i].first].push_back(i);
		arr[i].second = v[arr[i].first].size() - 1;
	}

	for (int i = 1; i <= n; i++) {
		int b = arr[i].second;

		if (b) {
			b = v[arr[i].first][b - 1];
		}

		dp[i] = max(dp[i - 1], b);
		result += i - dp[i];
	}

	cout << result;
}