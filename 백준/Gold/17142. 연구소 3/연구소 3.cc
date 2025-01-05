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

int n, m, result = -1;
int lab[51][51];
int chk[51][51];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
pair<int, int> virus[11];
int virusChk[11];
int indexV = 1;

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

void ChkV() {
	int maxT = 0;
	bool trig = false;

	for (int i = 1; i <= n && !trig; i++) {
		for (int j = 1; j <= n && !trig; j++) {
			if (lab[i][j] == 0 && chk[i][j] != INTMAX)maxT = max(maxT, chk[i][j]);
			if (lab[i][j] == 0 && chk[i][j] == INTMAX)trig = true;
		}
	}

	if (!trig) {
		if (result == -1)result = maxT;
		else result = min(result, maxT);
	}
}

void BFS() {
	queue <pair<int, int>> q;
	fill(chk[0], chk[51], INTMAX);
	for (int i = 1; i < indexV; i++) {
		if (virusChk[i]) {
			chk[virus[i].first][virus[i].second] = 0;
			q.push(virus[i]);
		}
	}

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		int nowC = chk[nowI][nowJ];
		q.pop();

		for (int d = 0; d < 4; d++) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && chk[tmpI][tmpJ] == INTMAX && lab[tmpI][tmpJ] != 1) {
				q.push({ tmpI,tmpJ });
				chk[tmpI][tmpJ] = nowC + 1;
			}
		}
	}
}

void Sel(int index, int nowM) {
	if (nowM == m) {
		BFS();
		ChkV();
		return;
	}

	for (int i = index + 1; i < indexV; i++) {
		if (!virusChk[i]) {
			virusChk[i] = 1;
			Sel(i, nowM + 1);
			virusChk[i] = 0;
		}
	}
}

bool Special() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (lab[i][j] == 0)return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2)virus[indexV++] = { i,j };
		}
	}
	
	if (Special()) cout << 0;
	else {
		Sel(0, 0);
		cout << result;
	}
}