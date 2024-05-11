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

int r, c;
int m[501][501];
bool chk[501][501];
vector<pair<int, int>> wolf;
bool dfsEnd = false;

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= r && b >= 1 && b <= c;
}

void Print() {
	cout << 1 << '\n';

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (!m[i][j])cout << '.';
			else if (m[i][j] == 1)cout << 'S';
			else if (m[i][j] == 2)cout << 'W';
			else cout << 'D';
		}
		cout << '\n';
	}
}

void DFS(pair<int, int> stP) {
	if (dfsEnd)return;

	int nowI = stP.first;
	int nowJ = stP.second;
	int d = 0;

	if (!chk[nowI][nowJ]) {
		chk[nowI][nowJ] = 1;

		while (d < 4) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ)) {
				if (m[tmpI][tmpJ] == 1 && m[nowI][nowJ] == 2) { dfsEnd = true; return; }
				
				if ((m[tmpI][tmpJ] == 1 || m[tmpI][tmpJ] == 3) && m[nowI][nowJ] != 2) m[nowI][nowJ] = 3;

				else if (!chk[tmpI][tmpJ]) DFS({ tmpI,tmpJ });
			}

			d++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char a;
			cin >> a;
			if (a == 'S') {
				m[i][j] = 1;
			}
			else if (a == 'W') {
				m[i][j] = 2;
				wolf.push_back({ i,j });
			}
		}
	}

	if (!wolf.size()) { Print(); return 0; }

	for (int i = 0; i < wolf.size(); i++) {
		DFS(wolf[i]);
	}

	if (dfsEnd)cout << 0;
	else Print();
}