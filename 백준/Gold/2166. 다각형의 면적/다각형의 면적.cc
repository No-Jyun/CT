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
long long x[10001];
long long y[10001];
long long result;

long long Sum(int i1, int i2, int i3) {
	long long tmp1 = x[i1] * y[i2] + x[i2] * y[i3] + x[i3] * y[i1];
	long long tmp2 = x[i1] * y[i3] + x[i2] * y[i1] + x[i3] * y[i2];
	return tmp1 - tmp2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}


	for (int i = 3; i <= n; i++) {
		result += (Sum(1, i - 1, i));
	}
	result = abs(result);

	if (result % 2) {
		cout << result / 2 << '.' << '5';
	}
	else cout << result / 2 << '.' << '0';
}