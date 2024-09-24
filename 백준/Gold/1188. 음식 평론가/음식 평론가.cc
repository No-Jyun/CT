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
int gcf = 1;

int Chop() {
	for (int i = 1; i <= n && i <= m; i++) {
		if (n % i == 0 && m % i == 0)gcf = i;
	}

	int tn = n / gcf;
	int tm = m / gcf;
	if (tm == 1)return 0;

	while (tn > tm) {
		tn -= tm;
	}

	if (tn == 1) return (tm - 1) * gcf;
	
	int nokorimono = tn;
	int index = 1;
	int base = tm;
	int result = 0;

	while (index <= tn) {
		if (base - nokorimono > 0) {
			base -= nokorimono;
			nokorimono = tn;
			result++;
		}
		else if (base - nokorimono == 0) {
			index++;
			base = tm;
			nokorimono = tn;
		}
		else {
			nokorimono -= base;
			index++;
			base = tm;
		}
	}
	return result * gcf;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cout << Chop();
}