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

int puyo[13][7];
int chk[13][7];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= 12 && b <= 6;
}

bool BFS() {
	bool isBoom = false;

	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			if (!chk[i][j] && puyo[i][j]) {
				vector<pair<int, int>> v;
				v.push_back({ i,j });
				chk[i][j] = 1;
				int index = 0;

				while (index < v.size()) {
					int nowI = v[index].first;
					int nowJ = v[index].second;
					int d = 0;
					index++;

					while (d < 4) {
						int tmpI = nowI + mI[d];
						int tmpJ = nowJ + mJ[d];

						if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ] && puyo[tmpI][tmpJ] == puyo[i][j]) {
							chk[tmpI][tmpJ] = 1;
							v.push_back({ tmpI,tmpJ });
						}
						d++;
					}
				}
			
				if (index >= 4) {
					isBoom = true;
					for (int k = 0; k < index; k++) {
						puyo[v[k].first][v[k].second] = 0;
					}
				}
			}
		}
	}
	return isBoom;
}

int Chain() {
	int chainT = 0;

	while (BFS()) {
		chainT++;
		fill(chk[0], chk[13], 0);

		for (int j = 1; j <= 6; j++) {
			int emptyC = 0;

			for (int i = 12; i >= 1; i--) {
				if (!emptyC && !puyo[i][j])emptyC = i;

				if (emptyC && puyo[i][j]) {
					puyo[emptyC--][j] = puyo[i][j];
					puyo[i][j] = 0;
				}
			}
		}
	}

	return chainT;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 12; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= 6; j++) {
			if (s[j - 1] == 'R')puyo[i][j] = 1;
			if (s[j - 1] == 'Y')puyo[i][j] = 2;
			if (s[j - 1] == 'G')puyo[i][j] = 3;
			if (s[j - 1] == 'B')puyo[i][j] = 4;
			if (s[j - 1] == 'P')puyo[i][j] = 5;
		}
	}

	cout << Chain();
}