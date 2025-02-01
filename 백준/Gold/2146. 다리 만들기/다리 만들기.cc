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

int n;
int minim = INTMAX;
int zido[101][101];
int chk[101][101];
vector<pair<int, int>> land;
int iI = 1;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

void ChkLand() {
	for (int x = 0; x < land.size(); x++) {
		int i = land[x].first;
		int j = land[x].second;

		if (!chk[i][j]) {
			chk[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });

			while (!q.empty()) {
				int nowI = q.front().first;
				int nowJ = q.front().second;
				zido[nowI][nowJ] = iI;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int tmpI = nowI + mI[d];
					int tmpJ = nowJ + mJ[d];

					if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ] && zido[tmpI][tmpJ]) {
						chk[tmpI][tmpJ] = 1;
						q.push({ tmpI,tmpJ });
					}
				}
			}
			iI++;
		}
	}
}

void BFS(int i, int j) {
	int mainLand = zido[i][j];
	chk[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ]) {
				if (!zido[tmpI][tmpJ]) {
					chk[tmpI][tmpJ] = chk[nowI][nowJ] + 1;
					q.push({ tmpI,tmpJ });
				}
				else {
					if (zido[tmpI][tmpJ] != mainLand) {
						minim = min(minim, chk[nowI][nowJ] - 1);
						return;
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

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> zido[i][j];
			if (zido[i][j])land.push_back({ i,j });
		}
	}

	ChkLand();

	for (int i = 0; i < land.size(); i++) {
		fill(chk[0], chk[n + 1], 0);
		BFS(land[i].first, land[i].second);
	}
	cout << minim;
}