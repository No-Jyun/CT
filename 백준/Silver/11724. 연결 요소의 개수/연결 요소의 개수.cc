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

bool chk[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int result = 0;
	
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			result++;
			chk[i] = 1;
			queue<int> q;
			q.push(i);

			while (!q.empty()) {
				int index = q.front();
				q.pop();

				for (int j = 0; j < v[index].size(); j++) {
					if (!chk[v[index][j]]) {
						chk[v[index][j]] = 1;
						q.push(v[index][j]);
					}
				}
			}
		}
	}
	cout << result;
}