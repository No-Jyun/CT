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
#define MAX 52
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m, k, x;
	cin >> n >> m >> k >> x;

	vector<vector<int>> v(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	vector<int> result;
	int* chk = new int[n + 1];
	fill(chk, chk + n + 1, 0);
	queue<int> q;
	q.push(x);
	q.push(0);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		int cityCount = q.front(); q.pop();

		if (!chk[now]) {
			chk[now] = 1;
			if (cityCount == k)result.push_back(now);
			if (cityCount > k)break;

			for (int i = 0; i < v[now].size(); i++) {
				q.push(v[now][i]);	q.push(cityCount + 1);
			}
		}
	}

	if (result.empty()) { cout << -1; }
	else {
		sort(result.begin(), result.end());

		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
}