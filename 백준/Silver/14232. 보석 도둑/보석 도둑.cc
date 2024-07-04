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

long long k;
vector<long long> resultN;
int result;

void FindPrime(long long n) {
	long long tmp = 1;
	for (long long i = sqrt(n) + 1; i >= 1; i--) {
		if (n % i == 0) { tmp = i; break; }
	}

	if (tmp == 1 || n == 2) {
		result++;
		resultN.push_back(n);
		return;
	}
	else {
		FindPrime(tmp);
		FindPrime(n / tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;

	FindPrime(k);

	sort(resultN.begin(), resultN.end());
	cout << result << '\n';
	for (auto it : resultN)cout << it << ' ';
}