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

int info[601][601];
bool chk[601][601];
int n, m;
int result;
pair<int, int> stP;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void BFS() {
	queue<pair<int, int>> q;
	q.push(stP);
	chk[stP.first][stP.second] = 1;

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		int d = 0;
		q.pop();

		while (d < 4) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ] && info[tmpI][tmpJ] != 1) {
				chk[tmpI][tmpJ] = 1;
				q.push({ tmpI,tmpJ });
				if (info[tmpI][tmpJ] == 2)result++;
			}
			d++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char s;
			cin >> s;

			if (s == 'I')stP = { i,j };
			if (s == 'P')info[i][j] = 2;
			if (s == 'X')info[i][j] = 1;
		}
	}

	BFS();
	
	result ? cout << result : cout << "TT";
}