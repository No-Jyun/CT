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

int n, sum;
bool ari[4000001];
vector<int> prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (!ari[i]) {
			prime.push_back(i);
			if(i <= sqrt(n))
				for (int j = 2; i * j <= n; j++)ari[i * j] = true;
		}
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	int i = prime.size() - 1;
	int j = i;
	int nowSum = prime[i];
	while (j >= 0 && i >= 0) {
		if (nowSum == n) sum++;

		if (nowSum >= n) {
			nowSum -= prime[i];
			i--;
		}
		else {
			j--;
			if (j < 0)break;
			nowSum += prime[j];
		}
	}
	cout << sum;
}