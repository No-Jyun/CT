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
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d, k;
	cin >> d >> k;

	int fib[31];
	fib[1] = 1, fib[2] = 1;
	for (int i = 3; i <= 30; i++) { fib[i] = fib[i - 1] + fib[i - 2]; }

	int coefA = fib[d - 2];
	int coefB = fib[d - 1];

	int a = 0;
	for (int i = 1;; i++) {
		if ((k - (coefA * i)) % coefB == 0) { a = i; break; }
	}
	cout << a << '\n' << (k - (coefA * a)) / coefB;
}