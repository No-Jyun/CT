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

int m, n, tomato;
int maxD;
queue<pair<int, int>> q;

int dp[1001][1001];
bool chk[1001][1001];

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void DFS() {
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		int d = 0;
		int nowD = dp[i][j];
		maxD = max(maxD, nowD);

		while (d < 4) {
			int ti = i + mI[d];
			int tj = j + mJ[d];

			if (Range(ti, tj) && !chk[ti][tj] && dp[ti][tj] != -1) {
				tomato++;
				chk[ti][tj] = 1;
				dp[ti][tj] = nowD + 1;
				q.push({ ti,tj });
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
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				dp[i][j] = a;
				chk[i][j] = a;
				tomato++;
				q.push({ i,j });
			}
			else if (a == -1) {
				dp[i][j] = -1;
				rottenTomato++;
			}
		}
	}

	DFS();

	if (tomato == n * m - rottenTomato) {
		cout << maxD - 1;
	}
	else cout << -1;
}