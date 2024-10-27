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

int r, c;
int arr[51][51];
bool chk[51][51];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
queue<pair<int, int>> water;
queue<pair<int, int>> q;

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= r && b <= c;
}

void MoveWater() {
	queue<pair<int, int>> tmp;
	while (!water.empty()) {
		int nowI = water.front().first;
		int nowJ = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int tmpI = nowI + mI[i];
			int tmpJ = nowJ + mJ[i];

			if (Range(tmpI, tmpJ) && !arr[tmpI][tmpJ]) {
				arr[tmpI][tmpJ] = 1;
				tmp.push({ tmpI,tmpJ });
			}
		}
	}
	water = tmp;
}

bool MoveHogger() {
	queue<pair<int, int>> tmp;
	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		q.pop();

		if (arr[nowI][nowJ] == 100)return true;

		for (int i = 0; i < 4; i++) {
			int tmpI = nowI + mI[i];
			int tmpJ = nowJ + mJ[i];

			if (Range(tmpI, tmpJ) && arr[tmpI][tmpJ] != 1 && !chk[tmpI][tmpJ]) {
				chk[tmpI][tmpJ] = 1;
				tmp.push({ tmpI,tmpJ });
			}
		}
	}
	q = tmp;
	return false;
}

bool BFS() {
	int  t = 0;

	while (t < 2501) {
		MoveWater();
		if (MoveHogger()) {
			cout << t;
			return true;
		}
		t++;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char c;
			cin >> c;
			if (c == '*') {
				arr[i][j] = 1;
				water.push({ i,j });
			}
			if (c == 'D')arr[i][j] = 100;
			if (c == 'S') {
				chk[i][j] = 1;
				q.push({ i,j });
			}
			if (c == 'X')arr[i][j] = 1;
		}
	}

	if (!BFS())cout << "KAKTUS";
}