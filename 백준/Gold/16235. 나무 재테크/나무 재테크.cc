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

int n, m, k;
vector<int> tree[11][11];
vector<int> aliveT[11][11];
int bunsick[11][11];
int yangbun[11][11];
pair<int, int> A[11][11];
int mI[8] = { -1,-1,0,1,1,1,0,-1 };
int mJ[8] = { 0,1,1,1,0,-1,-1,-1 };

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

void Spring() {
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int i = 0; i < tree[x][y].size(); i++) {
				int old = tree[x][y][i];

				if (yangbun[x][y] >= old) {
					aliveT[x][y].push_back(old + 1);
					yangbun[x][y] -= old;

					if ((old + 1) % 5 == 0) {
						bunsick[x][y]++;
					}
				}
				else {
					A[x][y].second += old / 2;
				}
			}
			tree[x][y].clear();
		}
	}
}

void Fall() {
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			if (bunsick[x][y] == 0)continue;

			for (int d = 0; d < 8; d++) {
				int tmpX = x + mI[d];
				int tmpY = y + mJ[d];

				if (Range(tmpX, tmpY)) {
					for (int t = 0; t < bunsick[x][y]; t++)
						tree[tmpX][tmpY].push_back(1);
				}
			}
			bunsick[x][y] = 0;
		}
	}
}

void Winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			yangbun[i][j] += A[i][j].first + A[i][j].second;
			A[i][j].second = 0;

			for (int index = 0; index < aliveT[i][j].size(); index++) {
				tree[i][j].push_back(aliveT[i][j][index]);
			}
			aliveT[i][j].clear();
		}
	}
}

int TC() {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			c += tree[i][j].size();
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j].first;
			yangbun[i][j] = 5;
		}
	}
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][b].push_back(c);
	}

	int t = 0;
	while (t++ < k) {
		Spring();
		Fall();
		Winter();
	}

	cout << TC();
}