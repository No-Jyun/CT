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
#define LL long long
#define INTMAX 2147483647
using namespace std;

int sum, diff;
int a = -1, b = -1;

int main() {
	cin >> sum >> diff;
	
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (i + j == sum && abs(i - j) == diff) {
				a = i;
				b = j;
			}
		}
	}
	
	if (a == -1) {
		cout << -1;
	}
	else {
		cout << max(a, b) << ' ' << min(a, b);
	}
}