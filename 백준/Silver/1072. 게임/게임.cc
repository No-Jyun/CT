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

long long x, y;
int z;

bool Chk(long long a) {
	int nowZ = ((y + a) * 100) / (x + a);

	return nowZ > z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;

	z = (y * 100) / x;

	if (x == y || z == 99) { cout << -1; return 0; }

	long long left = 1, right = x;
	while (left <= right) {
		long long mid = (left + right) / 2;

		if (Chk(mid))right = mid - 1;
		else left = mid + 1;
	}

	if (Chk(left)) { cout << left; }
	else cout << -1;
}