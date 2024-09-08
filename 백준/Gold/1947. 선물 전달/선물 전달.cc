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

int n;
ULL d[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	d[0] = 1;
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
		d[i] %= 1000000000;
	}
	cout << d[n];
}