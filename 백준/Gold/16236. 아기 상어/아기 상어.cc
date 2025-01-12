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

int n, m, result;
int space[21][21];
int chk[21][21];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
int baby = 2;
int nowE;
pair<int, int> stP;
priority_queue<vector<int>> eatable;

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

void BFS() {
	fill(chk[0], chk[21], -1);
	queue<pair<int, int>> q;
	q.push({ stP });
	chk[stP.first][stP.second] = 0;

	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && chk[tmpI][tmpJ] == -1 && space[tmpI][tmpJ] <= baby) {
				chk[tmpI][tmpJ] = chk[nowI][nowJ] + 1;
				q.push({ tmpI,tmpJ });
				if (space[tmpI][tmpJ] && space[tmpI][tmpJ] < baby)
					eatable.push({ -chk[tmpI][tmpJ],-tmpI,-tmpJ });
			}
		}
	}

}

void Eat() {
	int nowDis = -eatable.top()[0];
	int nowI = -eatable.top()[1];
	int nowJ = -eatable.top()[2];

	priority_queue<vector<int>> t;
	eatable = t;

	space[nowI][nowJ] = 0;
	result += nowDis;
	stP = { nowI, nowJ };
	nowE++;
	if (nowE == baby) {
		nowE = 0;
		baby++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				stP = { i,j };
				space[i][j] = 0;
			}
		}
	}

	do {
		BFS();
		if (eatable.empty())break;
		else Eat();
	} while (1);

	cout << result;
}