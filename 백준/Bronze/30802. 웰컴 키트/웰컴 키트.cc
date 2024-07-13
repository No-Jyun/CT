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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, m, l, xl, xxl, xxxl, t, p;
	cin >> n;
	cin >> s >> m >> l >> xl >> xxl >> xxxl;
	cin >> t >> p;

	int shirt = s / t + m / t + l / t + xl / t + xxl / t + xxxl / t;
	!(s % t) ? shirt : shirt++;
	!(m % t) ? shirt : shirt++;
	!(l % t) ? shirt : shirt++;
	!(xl % t) ? shirt : shirt++;
	!(xxl % t) ? shirt : shirt++;
	!(xxxl % t) ? shirt : shirt++;

	cout << shirt << '\n';
	cout << n / p << ' ' << n % p;
}