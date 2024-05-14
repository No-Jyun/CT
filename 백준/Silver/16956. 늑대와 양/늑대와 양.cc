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
vector<pair<int, int>> wolf, sheep;

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

bool ChkSheep() {
	for (int i = 0; i < sheep.size(); i++) {
		int nowI = sheep[i].first;
		int nowJ = sheep[i].second;
		int d = 0;

		while (d < 4) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && m[tmpI][tmpJ] == 2)return true;
            else if(Range(tmpI, tmpJ) && m[tmpI][tmpJ] == 0)m[tmpI][tmpJ] = 3;
			d++;
		}
	}
    return false;
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
				sheep.push_back({ i,j });
			}
			else if (a == 'W') {
				m[i][j] = 2;
				wolf.push_back({ i,j });
			}
		}
	}

	if (!wolf.size()) { Print(); return 0; }

	if (ChkSheep()) { cout << 0; return 0; }
	Print();
}