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
int cave[126][126];
int chk[126][126];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

int BFS() {
	priority_queue<vector<int>> q;
	q.push({ -cave[1][1],1,1 });
	chk[1][1] = cave[1][1];

	while (!q.empty()) {
		int nowI = q.top()[1];
		int nowJ = q.top()[2];
		int nowC = chk[nowI][nowJ];
		q.pop();

//		if (q.top()[0] != nowC)continue;

		if (nowI == n && nowJ == n)return nowC;

		for (int i = 0; i < 4; i++) {
			int tmpI = nowI + mI[i];
			int tmpJ = nowJ + mJ[i];

			if (Range(tmpI, tmpJ)) {
				int tC = nowC + cave[tmpI][tmpJ];
				if (chk[tmpI][tmpJ] > tC) {
					chk[tmpI][tmpJ] = tC;
					q.push({ -tC,tmpI,tmpJ });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (1) {
		fill(chk[0], chk[126], INTMAX);

		cin >> n;
		if (!n)break;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)cin >> cave[i][j];
		}

		cout << "Problem " << t++ << ": " << BFS() << '\n';
	}
}