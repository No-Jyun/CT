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

int n, m;
ULL sum[1000001];
ULL modular[1001];
ULL result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		sum[i] = a + sum[i - 1];
		modular[sum[i] % m]++;
	}

	for (int i = 0; i < m; i++) {
		if (i == 0) result += modular[i];

		if (modular[i] >= 2) {
			result += (modular[i] * (modular[i] - 1)) / 2;
		}
	}
	cout << result;
}