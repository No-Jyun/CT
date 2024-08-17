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

int chess[9][9];
pair<int, int> x, y;

bool Range(int a, int b) {
	return a >= 1 && a <= 8 && b >= 1 && b <= 8;
}

void Trans(int a, int b, int c) {
	int i = 8 - (b - '0') + 1;
	int j = a - 'A' + 1;

	if (c)y = { i,j };
	else x = { i,j };
}

void Offset(int &a, int &b, int distance, int d) {
	switch (d)
	{
	case 1:
		a -= distance;
		b += distance;
		return;
	case 2:
		a += distance;
		b -= distance;
		return;
	case 3:
		a -= distance;
		b -= distance;
		return;
	default:
		a += distance;
		b += distance;
		return;
	}
}

void BFS() {
	queue<vector<int>> q;
	q.push({ x.second,x.first });
	chess[x.first][x.second] = 0;

	while (!q.empty()) {
		vector<int> nowP = q.front();
		q.pop();

		int nowI = nowP[nowP.size() - 1];
		int nowJ = nowP[nowP.size() - 2];

		if (nowI == y.first && nowJ == y.second) {
			cout << chess[y.first][y.second] << ' ';
			for (int i = 0; i < nowP.size(); i++) {
				if (i % 2 == 0)cout << (char)(nowP[i] - 1 + 'A') << ' ';
				else cout << 8 - nowP[i] + 1 << ' ';
			}
			cout << '\n';
			return;
		}

		for (int i = 1; i < 8; i++) {
			for (int j = 0; j < 4; j++) {
				int tmpI = nowI, tmpJ = nowJ;
				Offset(tmpI, tmpJ, i, j);

				if (Range(tmpI, tmpJ) && chess[tmpI][tmpJ] == -1) {
					chess[tmpI][tmpJ] = chess[nowI][nowJ] + 1;
					vector<int> tt = nowP;
					tt.push_back(tmpJ);
					tt.push_back(tmpI);
					q.push(tt);
				}
			}
		}
	}
	cout << "Impossible" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		fill(chess[0], chess[9], -1);

		for (int i = 0; i < 2; i++) {
			char a, b;
			cin >> a >> b;
			Trans(a, b, i);
		}
		BFS();
	}
}