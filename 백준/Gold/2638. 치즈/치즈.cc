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

int n, m;
int monun[101][101];
int chk[101][101];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= m;
}

void DelChz() {
	queue<pair<int, int>> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (monun[i][j]) {
				int t = 0;
				for (int d = 0; d < 4; d++) {
					int tmpI = i + mI[d];
					int tmpJ = j + mJ[d];

					if (Range(tmpI, tmpJ) && !monun[tmpI][tmpJ] && chk[tmpI][tmpJ])t++;
				}
				if (t >= 2)q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		monun[q.front().first][q.front().second] = 0;
		q.pop();
	}
}

void ChkAir() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	chk[1][1] = 1;

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ] && !monun[tmpI][tmpJ]) {
				chk[tmpI][tmpJ] = 1;
				q.push({ tmpI,tmpJ });
			}
		}
	}
}

bool Chk() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (monun[i][j])return true;
	}
	return false;
}

int S() {
	int c = 0;
	while (Chk()) {
		fill(chk[0], chk[101], 0);
		ChkAir();
		DelChz();
		c++;
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)cin >> monun[i][j];
	}

	cout << S();
}