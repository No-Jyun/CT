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

int n, m, t;
int chk[101][101];
int arr[101][101];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

queue<pair<int, int>> BFS(int nowT) {
	queue<pair<int, int>>tmpQ;
	if (!nowT) {
		while (!q.empty()) {
			int nowI = q.front().first;
			int nowJ = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int tmpI = nowI + mI[i];
				int tmpJ = nowJ + mJ[i];

				if (Range(tmpI, tmpJ) && chk[tmpI][tmpJ] == -1) {
					if (arr[tmpI][tmpJ]) {
						chk[tmpI][tmpJ] = 1;
						tmpQ.push({ tmpI,tmpJ });
					}
					else {
						chk[tmpI][tmpJ] = 0;
						q.push({ tmpI,tmpJ });
					}
				}
			}
		}
		return tmpQ;
	}

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		arr[nowI][nowJ] = 0;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tmpI = nowI + mI[i];
			int tmpJ = nowJ + mJ[i];

			if (Range(tmpI, tmpJ) && chk[tmpI][tmpJ] == -1) {
				if (arr[tmpI][tmpJ]) {
					chk[tmpI][tmpJ] = nowT + 1;
					tmpQ.push({ tmpI,tmpJ });
				}
				else {
					chk[tmpI][tmpJ] = 0;
					q.push({ tmpI,tmpJ });
				}
			}
		}
	}
	return tmpQ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)cin >> arr[i][j];
	}
	fill(chk[0], chk[101], -1);

	q.push({ 1,1 });
	chk[1][1] = 0;
	while (!q.empty()) {
		q = BFS(t);
		t++;
	}

	cout << t - 1 << '\n';
	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chk[i][j] == t - 1)result++;
		}
	}
	cout << result;
}