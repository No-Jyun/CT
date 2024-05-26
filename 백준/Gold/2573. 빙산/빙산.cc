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
#include <tuple>
using namespace std;

int n, m;
int ice[301][301];
bool chk[301][301];
int year;

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

int Counting(int, int);
void Melt();
void BFS(int, int);
bool Check();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ice[i][j];
		}
	}

	while (1) {
		Melt();

		year++;
		if (Check())break;
		fill(chk[1], chk[n + 1], 0);
	}
}

void Melt() {
	queue<tuple<int, int, int>> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ice[i][j]) {
				q.push({ i,j,Counting(i, j) });
			}
		}
	}

	while (!q.empty()) {
		ice[get<0>(q.front())][get<1>(q.front())] -= get<2>(q.front());
		q.pop();
	}
}

int Counting(int a, int b) {
	int d = 0;
	int c = 0;

	while (d < 4) {
		int aroundI = a + mI[d];
		int aroundJ = b + mJ[d];

		if (!ice[aroundI][aroundJ])c++;

		d++;
	}

	if (c > ice[a][b])c = ice[a][b];

	return c;
}

bool Check() {
	int bfsC = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!chk[i][j] && ice[i][j]) {
				chk[i][j] = 1;
				BFS(i, j);
				bfsC++;
			}

			if (bfsC >= 2)break;
		}
	}

	switch (bfsC)
	{
	case 0:
		cout << 0;
		return true;
	case 1:
		return false;
	default:
		cout << year;
		return true;
	}
}

void BFS(int stI, int stJ) {
	queue<pair<int, int>> q;
	q.push({ stI,stJ });
	
	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		int d = 0;
		q.pop();

		while (d < 4) {
			int gotoI = nowI + mI[d];
			int gotoJ = nowJ + mJ[d];

			if (ice[gotoI][gotoJ] && !chk[gotoI][gotoJ]) {
				chk[gotoI][gotoJ] = 1;
				q.push({ gotoI,gotoJ });
			}

			d++;
		}
	}
}