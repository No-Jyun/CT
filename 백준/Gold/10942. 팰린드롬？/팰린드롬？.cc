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

int arr[2001];
int dp[2001][2001];
int n, m, s, e;

bool P(int a, int b) {
	while (a <= b) {
		if (arr[a] != arr[b])return false;
		a++; b--;
	}
	return true;
}

void Chk(int index) {
	for (int i = n; i >= index; i--) {
		if (arr[index] == arr[i] && !dp[index][i]) {
			if (P(index, i)) {
				for (int j = 0; index + j <= i - j; j++)
					dp[index + j][i - j] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	for (int i = 1; i <= n; i++)Chk(i);

	cin >> m;
	while (m--) {
		cin >> s >> e;

		if (dp[s][e])cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}