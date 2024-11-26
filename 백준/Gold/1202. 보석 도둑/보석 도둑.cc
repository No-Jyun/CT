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

int n, k;
ULL result;
priority_queue<pair<int,int>> juw1;
priority_queue<int> bag, juw2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		juw1.push({ -a,-b });
	}
	
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		bag.push(-a);
	}

	while (!bag.empty()) {
		int topB = -bag.top();
		bag.pop();

		while (!juw1.empty() && -juw1.top().first <= topB) {
			juw2.push(-juw1.top().second);
			juw1.pop();
		}

		if (!juw2.empty()) {
			result += juw2.top();
			juw2.pop();
		}
	}

	cout << result;
}