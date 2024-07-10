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

bool wall[1001][1001];
bool isWallChk[1001][1001];
int chk[1001][1001];
int n, m;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void BFS(int i, int j) {
	queue<vector<int>> q;
	q.push({ i,j,chk[i][j] });
	bool isWall = wall[i][j] || isWallChk[i][j];

	while (!q.empty()) {
		int nowI = q.front()[0];
		int nowJ = q.front()[1];
		int distance = q.front()[2];
		int d = 0;
		q.pop();

		while (d < 4) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && distance + 1 < chk[tmpI][tmpJ]) {
				if (isWall) {
					if (!wall[tmpI][tmpJ]) {
						isWallChk[tmpI][tmpJ] = isWall;
						chk[tmpI][tmpJ] = distance + 1;
						q.push({ tmpI,tmpJ,distance + 1 });
					}
				}
				else {
					isWallChk[tmpI][tmpJ] = isWall;
					chk[tmpI][tmpJ] = distance + 1;
					if (!wall[tmpI][tmpJ])q.push({ tmpI,tmpJ,distance + 1 });
				}
			}
			d++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			wall[i][j + 1] = s[j] - '0';
		}
	}

	fill(chk[0], chk[n + 1], 999999999);
	chk[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			BFS(i, j);
		}
	}

	if (chk[n][m] != 999999999)cout << chk[n][m];
	else cout << -1;
}