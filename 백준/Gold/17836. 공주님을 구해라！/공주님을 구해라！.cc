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

int n, m, t;
int sung[101][101];
int chk[101][101];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
pair<int, int> gum;
int result = 999999999;

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= m;
}

void BFS(int a, int b, bool canIg, int org) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	chk[a][b] = org;

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		int d = 0;
		q.pop();

		while (d < 4) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ]) {
				if (canIg) {
					chk[tmpI][tmpJ] = chk[nowI][nowJ] + 1;
					q.push({ tmpI,tmpJ });
				}
				else {
					if (!sung[tmpI][tmpJ]) {
						chk[tmpI][tmpJ] = chk[nowI][nowJ] + 1;
						q.push({ tmpI,tmpJ });
					}
				}
			}
			d++;
		}
	}
	if (chk[n][m]) {
		result = min(result, chk[n][m] - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> sung[i][j];			
			if (sung[i][j] == 2) {
				sung[i][j] = 0;
				gum = { i,j };
			}
		}
	}
	BFS(1, 1, false, 1);
	if (chk[gum.first][gum.second]) {
		int exT = chk[gum.first][gum.second];
		fill(chk[0], chk[101], 0);
		BFS(gum.first, gum.second, true, exT);
	}

	if (result <= t)cout << result;
	else cout << "Fail";
}