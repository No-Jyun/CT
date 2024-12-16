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

int miro[101][101];
int chk[101][101];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
int n, m;

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= m;
}

void BFS() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	chk[1][1] = 0;

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		int nowC = chk[nowI][nowJ];
		q.pop();

		for (int d = 0; d < 4; d++) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ)) {
				if (miro[tmpI][tmpJ]) {
					if (chk[tmpI][tmpJ] > nowC + 1) {
						chk[tmpI][tmpJ] = nowC + 1;
						q.push({ tmpI,tmpJ });
					}
				}
				else {
					if (chk[tmpI][tmpJ] > nowC) {
						chk[tmpI][tmpJ] = nowC;
						q.push({ tmpI,tmpJ });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)miro[i][j] = s[j - 1] - '0';
	}
	fill(chk[0], chk[101], INTMAX);

	BFS();

	cout << chk[n][m];
}