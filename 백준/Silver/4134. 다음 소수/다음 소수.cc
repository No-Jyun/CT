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

bool chk[70001];
vector<int> prime;

bool Check(int index, long long p) {
	long long tmp = prime[index];
	tmp *= tmp;
	return tmp <= p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 70000; i++) {
		if (!chk[i]) {
			prime.push_back(i);
			for (int j = 2; j * i <= 70000; j++)chk[j * i] = 1;
		}
	}

	int n;
	cin >> n;

	while (n--) {
		long long p;
		cin >> p;
		
		for (;; p++) {
			if (p <= 1) {
				cout << 2 << '\n';
				break;
			}

			bool isPrime = true;
			for (int i = 0; Check(i, p); i++) {
				if (p % prime[i] == 0) { isPrime = false; break; }
			}

			if (isPrime) {
				cout << p << '\n';
				break;
			}
		}
	}
}