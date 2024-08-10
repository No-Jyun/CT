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
using namespace std;

int n;
int modular = 1000000000;
int maxN;
int arr[1000001][20];
int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 20; i++) {
		int n2 = pow(2, i);
		if (n2 <= n) {
			maxN = i;
			arr[n2][i] = 1;
		}
	}

	for (int i = 1; i < n; i++) {
		int addSum = 0;
		for (int j = 0; j <= maxN; j++) {
			addSum += arr[i][j];
			addSum %= modular;

			int plusMoney = i + pow(2, j);
			if (plusMoney <= n) {
				arr[plusMoney][j] += addSum;
				arr[plusMoney][j] %= modular;
			}
		}
	}

	for (int j = 0; j <= maxN; j++) {
		result += arr[n][j];
		result %= modular;
	}
	cout << result;
}