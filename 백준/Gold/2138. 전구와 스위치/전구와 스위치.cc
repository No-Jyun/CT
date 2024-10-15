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

int n, minT = INTMAX;
int arr[100001], result[100001];

bool Range(int a) {
	return a >= 1 && a <= n;
}

void Adjust(int i) {
	for (int j = -1; j <= 1; j++) {
		if (Range(i + j)) {
			arr[i + j] = (arr[i + j] + 1) % 2;
		}
	}
}

bool Chk() {
	for (int i = 1; i <= n; i++) {
		if (arr[i] != result[i])return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= n; i++) {
		if (s1[i - 1] != s2[i - 1])result[i] = 1;
		else result[i] = 0;
	}

	int c = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i - 1] != result[i - 1]) {
			Adjust(i);
			c++;
		}

		if (i == n) {
			if (Chk()) {
				minT = min(minT, c);
			}
		}
	}

	c = 1;
	fill(arr, arr + n + 1, 0);
	Adjust(1);
	
	for (int i = 2; i <= n; i++) {
		if (arr[i - 1] != result[i - 1]) {
			Adjust(i);
			c++;
		}

		if (i == n) {
			if (Chk()) {
				minT = min(minT, c);
			}
		}
	}	

	if (minT == INTMAX)cout << -1;
	else cout << minT;
}