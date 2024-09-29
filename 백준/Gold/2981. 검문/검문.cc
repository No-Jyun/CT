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

int n, a, b;
int arr[101];

bool Chk(int tm) {
	int ba = arr[1] % tm;
	for (int i = 1; i <= n; i++) {
		if (ba != arr[i] % tm)return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	sort(arr, arr + n + 1);

	if (n == 2) {
		int t = arr[2] - arr[1];
		for (int i = 2; i <= t; i++) {
			if (t % i == 0) cout << i << ' ';
		}
	}
	else {
		a = INTMAX;
		b = 0;
		for (int i = 2; i <= n; i++) {
			a = min(a, arr[i] - arr[i - 1]);
			b = max(b, arr[i] - arr[i - 1]);
		}

		while (b % a != 0) {
			int t = a;
			int tt = b % a;
			b = max(t, tt);
			a = min(t, tt);
		}

		for (int i = 2; i <= a; i++) {
			if (Chk(i))cout << i << ' ';
		}
	}
}