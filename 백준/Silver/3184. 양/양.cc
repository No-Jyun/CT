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
using namespace std;

int r, c;
char madang[251][251];
bool chk[251][251];
vector<pair<int, int>> spot;
int sheep, wolf;

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int i, int j) {
	return i >= 1 && i <= r && j >= 1 && j <= c;
}

void BFS(pair<int, int> startP) {
	queue<pair<int, int>> q;
	q.push(startP);

	int wolfs = 0, sheeps = 0;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		int d = 0;
		q.pop();

		if (!chk[i][j]) {
			if (madang[i][j] == 'o')sheeps++;
			if (madang[i][j] == 'v')wolfs++;

			chk[i][j] = 1;

			while (d < 4) {
				int tmpi = i + mI[d];
				int tmpj = j + mJ[d];

				if (Range(tmpi, tmpj) && madang[tmpi][tmpj] != '#' && !chk[tmpi][tmpj]) {
					q.push({ tmpi,tmpj });
				}

				d++;
			}
		}
	}
	if (sheeps > wolfs) { sheep += sheeps; }
	else wolf += wolfs;
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
			madang[i][j] = a;
			if (a != '#')spot.push_back({ i,j });
		}
	}
	for (int i = 0; i < spot.size(); i++) {
		BFS(spot[i]);
	}
	cout << sheep << ' ' << wolf;
}