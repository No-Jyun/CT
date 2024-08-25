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

int n, m;
int edges[101][101];
int cost[101][101];

void Daikstra(int index) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (edges[index][i]) {
			cost[index][i] = edges[index][i];
		}
		else {
			cost[index][i] = 999999999;
		}
		q.push(i);
	}

	while (!q.empty()) {
		int nowI = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (i != index && edges[nowI][i]) {
				if (cost[index][i] > cost[index][nowI] + edges[nowI][i]) {
					cost[index][i] = cost[index][nowI] + edges[nowI][i];
					q.push(i);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (edges[a][b]) {
			edges[a][b] = min(edges[a][b], c);
		}
		else edges[a][b] = c;
	}

	for (int i = 1; i <= n; i++)Daikstra(i);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] != 999999999) cout << cost[i][j] << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
}