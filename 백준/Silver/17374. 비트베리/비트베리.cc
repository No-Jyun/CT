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

int p, q, a, b, c, d;
int maxim;

void Do(int big, int small, int ra, int rb) {
	int low = 0, high = big / ra;
	while (low <= high) {
		int mid = (low + high) / 2;
		maxim = max(maxim, min(big - mid * ra, small + mid * rb));

		if (big - mid * ra == small + mid * rb)break;
		else if (big - mid * ra <= small + mid * rb) high = mid - 1;
		else low = mid + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> p >> q >> a >> b >> c >> d;
		maxim = 0;

		int coin = 0;
		int berry = q / c;
		coin += berry * d;

		if (p < coin)Do(coin, p, b, a);
		else if (p > coin) Do(p, coin, a, b);
		
		maxim = max(maxim, min(p, coin));

		cout << maxim << '\n';
	}
}