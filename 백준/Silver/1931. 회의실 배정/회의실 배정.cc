#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int n;
	cin >> n;
	vector<pair<long long, long long>> v;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());

	int maxN = 1;
	long long tEnd = v[0].second, tBegin = v[0].first;

	for (int i = 1; i < n; i++) {
		if (tEnd > v[i].second) {
			tEnd = v[i].second;
			tBegin = v[i].first;
		}
		else {
			if (v[i].first >= tEnd) {
				tEnd = v[i].second;
				tBegin = v[i].first;
				maxN++;
			}
		}
	}


	cout << maxN;
}