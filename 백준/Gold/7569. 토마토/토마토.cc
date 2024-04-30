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

int m, n, h, tomato;
int maxD;
queue<pair<int, pair<int, int>>> q;

int dp[101][101][101];
bool chk[101][101][101];

int mK[2] = { -1,1 };
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b, int c) {
	return b >= 1 && b <= n && c >= 1 && c <= m && a >= 1 && a <= h;
}

void DFS() {
	while (!q.empty()) {
		int k = q.front().first;
		int i = q.front().second.first;
		int j = q.front().second.second;
		q.pop();
		int d = 0;
		int nowD = dp[k][i][j];
		maxD = max(maxD, nowD);

		while (d < 4) {
			int ti = i + mI[d];
			int tj = j + mJ[d];

			if (Range(k, ti, tj) && !chk[k][ti][tj] && dp[k][ti][tj] != -1) {
				tomato++;
				chk[k][ti][tj] = 1;
				dp[k][ti][tj] = nowD + 1;
				q.push({ k, { ti,tj } });
			}
			d++;
		}
		d = 0;
		
		while (d < 2) {
			int tk = k + mK[d];

			if (Range(tk, i, j) && !chk[tk][i][j] && dp[tk][i][j] != -1) {
				tomato++;
				chk[tk][i][j] = 1;
				dp[tk][i][j] = nowD + 1;
				q.push({ tk,{i,j} });
			}
			d++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int rottenTomato = 0;
	cin >> m >> n >> h;

	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int a;
				cin >> a;
				if (a == 1) {
					dp[k][i][j] = a;
					chk[k][i][j] = a;
					tomato++;
					q.push({ k,{ i,j } });
				}
				else if (a == -1) {
					dp[k][i][j] = -1;
					rottenTomato++;
				}
			}
		}
	}

	DFS();

	if (tomato == n * m * h - rottenTomato) {
		cout << maxD - 1;
	}
	else cout << -1;
}