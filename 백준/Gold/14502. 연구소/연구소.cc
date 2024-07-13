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

int wall[9][9];
int chk[9][9];
int n, m;
vector<pair<int, int>> virus;
int result;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void BFS() {
	for (int i = 0; i < virus.size(); i++) {
		queue<pair<int, int>> q;
		q.push(virus[i]);

		while (!q.empty()) {
			int nowI = q.front().first;
			int nowJ = q.front().second;
			int d = 0;
			q.pop();

			while (d < 4) {
				int tmpI = nowI + mI[d];
				int tmpJ = nowJ + mJ[d];

				if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ]) {
					chk[tmpI][tmpJ] = 2;
					q.push({ tmpI,tmpJ });
				}

				d++;
			}
		}
	}

	int r = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)if (!chk[i][j])r++;
	}

	result = max(result, r);
}

void BuildWall(int i, int j, int wallN) {
	if (wallN <= 3) {
		bool start = false;

		for (int tmpI = 1; tmpI <= n; tmpI++) {
			for (int tmpJ = 1; tmpJ <= m; tmpJ++) {
				if (!start) {
					tmpI = i;
					tmpJ = j + 1;

					if (tmpJ > m) {
						tmpJ = 1;
						tmpI++;
					}
					if (tmpI > n)return;

					start = true;
				}

				if (!wall[tmpI][tmpJ]) {
					wall[tmpI][tmpJ] = 1;
					BuildWall(tmpI, tmpJ, wallN + 1);
					wall[tmpI][tmpJ] = 0;
				}
			}
		}
	}

	else {
		copy(wall[0], wall[9], chk[0]);
		BFS();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> wall[i][j];
			if (wall[i][j] == 2)virus.push_back({ i,j });
		}
	}

	BuildWall(1, 0, 1);
	cout << result;
}