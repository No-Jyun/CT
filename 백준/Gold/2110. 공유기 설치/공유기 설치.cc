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

int n, c;
vector<int> v;

bool Chk(int dis) {
	int t = 1;
	int ex = 0;

	for (int i = 1; i < n; i++) {
		int nowD = v[i] - v[ex];

		if (nowD >= dis) {
			t++;
			ex = i;
		}

		if (t == c)return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int left = 1, right = v[n - 1] - v[0];

	while (left <= right) {
		int d = (left + right) / 2;
		
		if (Chk(d)) left = d + 1;
		else right = d - 1;
	}
	cout << right;
}