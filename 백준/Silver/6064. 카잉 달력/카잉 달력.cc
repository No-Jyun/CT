#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int m, n, x, y;
long long lcm;
int num[40001];

void LCM() {
	fill(num, num + 40001, 0);

	lcm = m;
	int tmp = m;
	for (int i = 2; i <= sqrt(m); i++) {
		if (tmp / i == 0) {
			num[i]++;
			tmp /= i--;
		}
	}
	if (tmp != 1)num[tmp]++;

	tmp = n;
	for (int i = 2; i <= sqrt(n); i++) {
		if (tmp / i == 0 && num[i]) {
			num[i]--;
			tmp /= i--;
		}
		else if (tmp / i == 0 && !num[i]) {
			tmp /= i--;
			lcm *= i;
		}
	}
	if (tmp != 1) {
		if (!num[tmp])lcm *= tmp;
	}
}

void FindY() {
	if (m > n) {
		long long year = x;

		while (year <= lcm) {
			if ((year - y) % n == 0) {
				cout << year << '\n';
				return;
			}
			year += m;
		}
	}
	else {
		long long year = y;

		while (year <= lcm) {
			if ((year - x) % m == 0) {
				cout << year << '\n';
				return;
			}
			year += n;
		}
	}
	cout << -1 << '\n';
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> m >> n >> x >> y;

		LCM();
		FindY();
	}
}