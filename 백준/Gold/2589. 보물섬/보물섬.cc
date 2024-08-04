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
int zido[51][51];
int chk[51][51];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
vector<pair<int, int>> land;
int result;

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void BFS(pair<int, int> now) {
	queue<pair<int, int>> q;
	q.push(now);
	chk[now.first][now.second] = 0;

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		int d = 0;
		q.pop();

		while (d < 4) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && zido[tmpI][tmpJ] && chk[tmpI][tmpJ] == -1) {
				chk[tmpI][tmpJ] = chk[nowI][nowJ] + 1;
				q.push({ tmpI,tmpJ });
			}
			d++;
		}
		result = max(result, chk[nowI][nowJ]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;

		for (int j = 1; j <= m; j++) {
			if (s[j - 1] == 'L') {
				zido[i][j] = 1;
				land.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < land.size(); i++) {
		fill(chk[0], chk[51], -1);
		BFS(land[i]);
	}
	cout << result;
}