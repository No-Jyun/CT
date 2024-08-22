#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <tuple>
#include <math.h>
using namespace std;

int w, h;
int building[1001][1001];
int fire[1001][1001];
int chk[1001][1001];
pair<int, int> stP;
queue<pair<int, int>> fireQ;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= h && b >= 1 && b <= w;
}

bool FindWay() {
	queue<pair<int, int>> q;
	q.push(stP);
	chk[stP.first][stP.second] = 1;

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		int d = 0;
		q.pop();

		while (d < 4) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (!Range(tmpI, tmpJ)) {
				cout << chk[nowI][nowJ] << '\n';
				return true;
			}
			else {
				if (building[tmpI][tmpJ] && !chk[tmpI][tmpJ] && fire[tmpI][tmpJ] > chk[nowI][nowJ] + 1) {
					chk[tmpI][tmpJ] = chk[nowI][nowJ] + 1;
					q.push({ tmpI,tmpJ });
				}
			}
			d++;
		}
	}
	return false;
}

void BFS() {
	while (!fireQ.empty()) {
		int nowI = fireQ.front().first;
		int nowJ = fireQ.front().second;
		int d = 0;
		fireQ.pop();

		while (d < 4) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && building[tmpI][tmpJ] && fire[tmpI][tmpJ] > fire[nowI][nowJ] + 1) {
				fire[tmpI][tmpJ] = fire[nowI][nowJ] + 1;
				fireQ.push({ tmpI,tmpJ });
			}
			d++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		fill(fire[0], fire[1001], 999999999);
		fill(chk[0], chk[1001], 0);
		fill(building[0], building[1001], 0);

		cin >> w >> h;
		string s;
		for (int i = 1; i <= h; i++) {
			cin >> s;
			for (int j = 1; j <= w; j++) {
				if (s[j - 1] == '*') {
					fireQ.push({ i,j });
					fire[i][j] = 1;
				}
				else if (s[j - 1] == '@') {
					stP = { i,j };
				}

				if (s[j - 1] != '#') {
					building[i][j] = 1;
				}
			}
		}

		BFS();

		if (!FindWay())cout << "IMPOSSIBLE" << '\n';
	}
}