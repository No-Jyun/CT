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

int m, n, path;
int arr[501][501];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
int chk[501][501];

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void BFS() {
	chk[1][1] = 1;
	priority_queue<vector<int>> q;
	q.push({ arr[1][1],1,1 });

	while (!q.empty()) {
		int nowI = q.top()[1];
		int nowJ = q.top()[2];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tmpI = nowI + mI[i];
			int tmpJ = nowJ + mJ[i];

			if (Range(tmpI, tmpJ) && arr[nowI][nowJ] > arr[tmpI][tmpJ]) {
				if (!chk[tmpI][tmpJ]) {
					chk[tmpI][tmpJ] = chk[nowI][nowJ];
					q.push({ arr[tmpI][tmpJ],tmpI,tmpJ });
				}
				else {
					chk[tmpI][tmpJ] += chk[nowI][nowJ];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)cin >> arr[i][j];
	}

	BFS();
	cout << chk[n][m];
}