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

int n, m;
bool hannam[1001];
int way[1001][1001];
bool chk[1001];
int result;

void BFS() {
	priority_queue<pair<int, pair<int, int>>> q;
	for (int i = 1; i <= n; i++) {
		if (way[1][i] != INTMAX)q.push({ -way[1][i],{1,i} });
	}
	chk[1] = 1;

	while (!q.empty()) {
		int nowC = -q.top().first;
		int fromI = q.top().second.first;
		int toI = q.top().second.second;
		q.pop();

		if (!chk[toI]) {
			chk[toI] = 1;
			result += nowC;

			for (int i = 1; i <= n; i++) {
				if (way[toI][i] != INTMAX)q.push({ -way[toI][i],{toI,i} });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			cout << -1;
			return;
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'M')hannam[i] = 1;
	}

	fill(way[0], way[n + 1], INTMAX);

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (hannam[a] != hannam[b]) {
			way[a][b] = min(way[a][b], c);
			way[b][a] = min(way[b][a], c);
		}
	}
	BFS();
}