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

vector<vector<int>> v;
int n, k;

int DP(int tn, int tk) {
	if (v[tn][tk])return v[tn][tk];
	
	v[tn][tk] = (DP(tn - 1, tk) + DP(tn - 1, tk - 1)) % 10007;

	return v[tn][tk];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		vector<int> tmp(i + 1);
		tmp[0] = 1;
		tmp[i] = 1;

		v.push_back(tmp);
	}

	cout << DP(n, k);
}