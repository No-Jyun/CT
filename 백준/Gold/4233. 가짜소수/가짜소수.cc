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

ULL p, a;
bool chk[31624];
vector<int> prime;

ULL Modular(ULL power) {
	if (power == 1)return a;

	ULL tmp = Modular(power / 2);
	tmp *= tmp;
	tmp %= p;
	if (power % 2) return (tmp * a) % p;
	else return tmp % p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 31623; i++) {
		if (!chk[i]) {
			prime.push_back(i);
			for (int j = 2; j * i <= 31623; j++)chk[j * i] = 1;
		}
	}

	while (1) {
		cin >> p >> a;
		if (!p && !a)break;

		bool isPrime = true;
		for (int i = 0; prime[i] * prime[i] <= p; i++) {
			if (p % prime[i] == 0) { isPrime = false; break; }
		}

		if (!isPrime) {
			ULL modular = Modular(p);
			if (modular == a)cout << "yes" << '\n';
			else cout << "no" << '\n';
		}
		else cout << "no" << '\n';
	}
}