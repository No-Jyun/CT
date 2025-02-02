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
#define LL long long
#define INTMAX 2147483647
using namespace std;

int w, h, result, k;
int miro[201][201];
int chk[32][201][201];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
int malI[8] = { -2,-1,1,2,2,1,-1,-2 };
int malJ[8] = { 1,2,2,1,-1,-2,-2,-1 };
queue<pair<int, int>> q[32];

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= h && b <= w;
}

void BFS() {
	for (int i = 0; i <= k; i++) {
		while (!q[i].empty()) {
			int nowI = q[i].front().first;
			int nowJ = q[i].front().second;
			q[i].pop();

			for (int d = 0; d < 4; d++) {
				int tmpI = nowI + mI[d];
				int tmpJ = nowJ + mJ[d];

				if (Range(tmpI, tmpJ) && !miro[tmpI][tmpJ] &&
					chk[i][tmpI][tmpJ] > chk[i][nowI][nowJ] + 1) {
					chk[i][tmpI][tmpJ] = chk[i][nowI][nowJ] + 1;
					q[i].push({ tmpI,tmpJ });
				}
			}
			for (int d = 0; d < 8; d++) {
				int tmpI = nowI + malI[d];
				int tmpJ = nowJ + malJ[d];

				if (Range(tmpI, tmpJ) && !miro[tmpI][tmpJ] &&
					chk[i + 1][tmpI][tmpJ] > chk[i][nowI][nowJ] + 1) {
					chk[i + 1][tmpI][tmpJ] = chk[i][nowI][nowJ] + 1;
					q[i + 1].push({ tmpI,tmpJ });
				}
			}
		}
		result = min(result, chk[i][h][w]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> w >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> miro[i][j];
		}
	}
	for (int i = 0; i <= k + 1; i++)
		fill(chk[i][0], chk[i][201], INTMAX);

	result = INTMAX;
	q[0].push({ 1,1 });
	chk[0][1][1] = 0;
	BFS();

	result == INTMAX ? cout << -1 : cout << result;
}