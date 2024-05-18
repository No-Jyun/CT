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
int dp[51][51];
bool chk[51][51];
vector<pair<int, int>> shark;

int mI[8] = { -1,-1,0,1,1,1,0,-1 };
int mJ[8] = { 0,1,1,1,0,-1,-1,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void BFS() {
	for (int i = 0; i < shark.size(); i++) {
		queue<int> q;
		q.push(shark[i].first);
		q.push(shark[i].second);
		chk[shark[i].first][shark[i].second] = 1;

		while (!q.empty()) {
			int nowI = q.front(); q.pop();
			int nowJ = q.front(); q.pop();
			int nowV = dp[nowI][nowJ];
			int d = 0;

			while (d < 8) {
				int tmpI = nowI + mI[d];
				int tmpJ = nowJ + mJ[d];

				if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ] && (dp[tmpI][tmpJ] > nowV + 1)) {
					chk[tmpI][tmpJ] = 1;
					dp[tmpI][tmpJ] = nowV + 1;
					q.push(tmpI);
					q.push(tmpJ);
				}
				d++;
			}
		}
		fill(chk[0], chk[51], 0);
		//fill(chk[0],chk[0] + 51*51,0)
		//fill_n(chk[0],51*51,0)
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a;
			cin >> a;
			if (a) {
				shark.push_back({ i,j });
				dp[i][j] = 0;
			}
			else dp[i][j] = 1000;
		}
	}

	BFS();
	
	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			result = max(result, dp[i][j]);
		}
	}	// BFS 를 여러번하므로 BFS중에 가장 작은거 크기 구하는데는 무리가 있을듯?
	cout << result;
}