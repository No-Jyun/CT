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

int l, r, c;
int building[31][31][31];
int chk[31][31][31];
tuple<int, int, int> stP, endP;

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
int mZ[2] = { -1,1 };

bool Range(int a, int b, int z) {
	return a >= 1 && b >= 1 && z >= 1 && a <= l && b <= r && z <= c;
}

bool BFS() {
	queue<tuple<int, int, int>> q;
	q.push(stP);
	chk[get<0>(stP)][get<1>(stP)][get<2>(stP)] = 0;

	while (!q.empty()) {
		int nowI = get<0>(q.front());
		int nowJ = get<1>(q.front());
		int nowK = get<2>(q.front());
		int d = 0;

		if (q.front() == endP)return true;
		q.pop();

		while (d < 4) {
			int tmpJ = nowJ + mI[d];
			int tmpK = nowK + mJ[d];

			if (Range(nowI, tmpJ, tmpK) && chk[nowI][tmpJ][tmpK] == -1 && building[nowI][tmpJ][tmpK]) {
				chk[nowI][tmpJ][tmpK] = chk[nowI][nowJ][nowK] + 1;
				q.push(make_tuple(nowI, tmpJ, tmpK));
			}
			d++;
		}

		d = 0;
		while (d < 2) {
			int tmpI = nowI + mZ[d];

			if (Range(tmpI, nowJ, nowK) && chk[tmpI][nowJ][nowK] == -1 && building[tmpI][nowJ][nowK]) {
				chk[tmpI][nowJ][nowK] = chk[nowI][nowJ][nowK] + 1;
				q.push(make_tuple(tmpI, nowJ, nowK));
			}

			d++;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		fill(&chk[0][0][0], &chk[30][30][31], -1);
		fill(&building[0][0][0], &building[30][30][31], 0);

		cin >> l >> r >> c;

		if (!l && !r && !c)break;

		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				string s;
				cin >> s;
				for (int k = 1; k <= c; k++) {
					if (s[k - 1] != '#') {
						building[i][j][k] = 1;
						if (s[k - 1] == 'S')stP = make_tuple(i, j, k);
						if (s[k - 1] == 'E')endP = make_tuple(i, j, k);
					}
				}
			}
		}

		if (BFS()) {
			cout << "Escaped in " << chk[get<0>(endP)][get<1>(endP)][get<2>(endP)] << " minute(s)." << '\n';
		}
		else cout << "Trapped!" << '\n';
	}
}