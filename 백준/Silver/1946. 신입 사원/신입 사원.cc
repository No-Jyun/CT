#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v;
		
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}

		sort(v.begin(), v.end());

		int result = 1;
		int maxim = v[0].second;

		for (int i = 1; i < n; i++) {
			if (maxim > v[i].second) {
				maxim = v[i].second;
				result++;
			}

			if (maxim == 1)break;
		}
		cout << result << '\n';
	}
}