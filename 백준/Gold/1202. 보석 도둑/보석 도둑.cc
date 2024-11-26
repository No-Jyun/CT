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
map<int, int> bag;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	v.push_back({ -1,-1 });
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		bag[a]++;
	}
	sort(v.begin(), v.end());

	for (int i = n; i >= 1; i--) {
		auto it = bag.lower_bound(v[i].second);
		if (it != bag.end()) {
			result += v[i].first;
			if (it->second == 1)bag.erase(it);
			else it->second--;
		}
	}

	cout << result;
}