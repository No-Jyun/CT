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

int gear[5][4][4];
bool chk[5];
int mI[8] = { 1,1,2,3,3,3,2,1 };
int mJ[8] = { 2,3,3,3,2,1,1,1 };
pair<int, int> leftG = { 2,1 };
pair<int, int> rightG = { 2,3 };
int result;

void Rot(int n, int dir) {
	if (!chk[n]) {
		chk[n] = 1;
		int originL = gear[n][leftG.first][leftG.second];
		int originR = gear[n][rightG.first][rightG.second];

		if (dir == 1) {
			int tmp = gear[n][1][1];
			for (int i = 0; i < 8; i++) {
				int xx = gear[n][mI[i]][mJ[i]];
				gear[n][mI[i]][mJ[i]] = tmp;
				tmp = xx;
			}
		}
		else {
			int tmp = gear[n][1][2];
			for (int i = 7; i >= 0; i--) {
				int xx = gear[n][mI[i]][mJ[i]];
				gear[n][mI[i]][mJ[i]] = tmp;
				tmp = xx;
			}
		}

		int nextG = n - 1;
		if (nextG >= 1 && nextG <= 4 && originL != gear[nextG][rightG.first][rightG.second]) {
			Rot(nextG, dir * (-1));
		}

		nextG = n + 1;
		if (nextG >= 1 && nextG <= 4 && originR != gear[nextG][leftG.first][leftG.second]) {			
			Rot(nextG, dir * (-1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 4; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < 8; j++) {
			gear[i][mI[j]][mJ[j]] = s[j] - '0';
		}
	}
	int k;
	cin >> k;
	while (k--) {
		int num, dir;
		cin >> num >> dir;
		Rot(num, dir);
		fill(chk, chk + 5, false);
	}

	for (int i = 1; i <= 4; i++) {
		result += gear[i][1][2] * pow(2, i - 1);
	}
	cout << result;
}