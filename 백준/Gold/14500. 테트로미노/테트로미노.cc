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

int n, m;
int paper[501][501];
bool chk[501][501];
pair<int, int> arr[3];
int maxim;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void DFS(int i, int j, int depth, int sum) {
	if (depth <= 3) {
		int d = 0;

		while (d < 4) {
			int tmpI = i + mI[d];
			int tmpJ = j + mJ[d];

			if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ]) {
				chk[tmpI][tmpJ] = true;
				if (depth != 3) arr[depth] = { tmpI,tmpJ };
				DFS(tmpI, tmpJ, depth + 1, sum + paper[tmpI][tmpJ]);
				chk[tmpI][tmpJ] = false;
			}
			d++;
		}

		if (depth == 3) {		//빠큐모양 처리
			int d = 0;

			while (d < 4) {
				int tmpI = arr[1].first + mI[d];
				int tmpJ = arr[1].second + mJ[d];

				if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ]) {
					chk[tmpI][tmpJ] = true;
					DFS(tmpI, tmpJ, depth + 1, sum + paper[tmpI][tmpJ]);
					chk[tmpI][tmpJ] = false;
				}
				d++;
			}
		}
	}
	else {
		maxim = max(maxim, sum);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)cin >> paper[i][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			chk[i][j] = true;
			arr[0] = { i,j };
			DFS(i, j, 1, paper[i][j]);
			chk[i][j] = false;
		}
	}
	cout << maxim;
}