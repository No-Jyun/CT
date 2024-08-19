#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <tuple>
#include <math.h>
using namespace std;

int n;
vector<pair<int, int>> v;
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int left = v[0].first, right = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first > right) {
			sum += right - left;

			left = v[i].first;
			right = v[i].second;
		}
		else if (v[i].first == right)right = v[i].second;
		else {
			if (v[i].second > right)right = v[i].second;
		}
	}
	sum += right - left;
	cout << sum;
}