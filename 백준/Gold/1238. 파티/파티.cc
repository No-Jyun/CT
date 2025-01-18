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

int n, m, x;
int dp[1001][1001];
int result[1001];
vector<pair<int, int>> edges[1001];

void Daikstra(int index) {
	fill(dp[index], dp[index] + n + 1, INTMAX);
	dp[index][index] = 0;
	queue<int> q;
	q.push(index);

	while (!q.empty()) {
		int nowI = q.front();
		q.pop();

		for (int i = 0; i < edges[nowI].size(); i++) {
			int gotoI = edges[nowI][i].first;
			int cost = edges[nowI][i].second;

			if (dp[index][gotoI] > dp[index][nowI] + cost) {
				dp[index][gotoI] = dp[index][nowI] + cost;
				q.push(gotoI);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		Daikstra(i);
		if (i == x) {
			for (int j = 1; j <= n; j++)result[j] += dp[i][j];
		}
		else result[i] += dp[i][x];
	}

	cout << *max_element(result, result + n + 1);
}