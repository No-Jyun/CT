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

int r, c, result;
int miro[1001][1001];
int chk[1001][1001];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
queue<pair<int, int>> jihun, fire;

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= r && b <= c;
}

bool BFS() {
	while (!jihun.empty()) {
		queue<pair<int, int>> nextQ;
		while (!jihun.empty()) {
			int nowI = jihun.front().first;
			int nowJ = jihun.front().second;
			jihun.pop();

			if (miro[nowI][nowJ] != 1)continue;

			for (int d = 0; d < 4; d++) {
				int tmpI = nowI + mI[d];
				int tmpJ = nowJ + mJ[d];

				if (Range(tmpI, tmpJ)) {
					if (chk[tmpI][tmpJ] == -1 && !miro[tmpI][tmpJ]) {
						chk[tmpI][tmpJ] = chk[nowI][nowJ] + 1;
						miro[tmpI][tmpJ] = 1;
						nextQ.push({ tmpI,tmpJ });
					}
				}
				else {
					result = chk[nowI][nowJ] + 1;
					return true;
				}
			}
		}
		jihun = nextQ;

		queue<pair<int, int>> nextF;
		while (!fire.empty()) {
			int nowI = fire.front().first;
			int nowJ = fire.front().second;
			fire.pop();

			for (int d = 0; d < 4; d++) {
				int tmpI = nowI + mI[d];
				int tmpJ = nowJ + mJ[d];

				if (Range(tmpI, tmpJ) && chk[tmpI][tmpJ] != - 99) {
					if (miro[tmpI][tmpJ] != 2 && miro[tmpI][tmpJ] != 3) {
						miro[tmpI][tmpJ] = 2;
						chk[tmpI][tmpJ] = -99;
						nextF.push({ tmpI,tmpJ });
					}
				}
			}
		}
		fire = nextF;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(chk[0], chk[1001], -1);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char x;
			cin >> x;
			switch (x)
			{
			case '#':
				miro[i][j] = 3;
				break;
			case 'J':
				miro[i][j] = 1;
				chk[i][j] = 0;
				jihun.push({ i,j });
				break;
			case 'F':
				miro[i][j] = 2;
				chk[i][j] = -99;
				fire.push({ i,j });
				break;
			default:
				break;
			}
		}
	}

	if (BFS()) cout << result;
	else cout << "IMPOSSIBLE";
}