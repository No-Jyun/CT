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

int n, m, h;
int ladder[32][11];
bool result = false;
int resultN = -1;
vector<pair<int, int>> canLadder;

bool Cal(int index) {
	int now = index;
	int s = 1;
	while (s <= m) {
		if (ladder[s][now])now++;
		else if (ladder[s][now - 1])now--;
		s++;
	}
	return now == index;
}

bool Chk(int a, int b) {
	return !ladder[a][b] && !ladder[a][b - 1] && !ladder[a][b + 1];
}

void Sel(int nowI, int nowC, int maxI) {
	if (result)return;
	if (nowC == maxI) {
		for (int i = 1; i <= n; i++) {
			if (!Cal(i))return;
		}
		result = true;
		return;
	}

	for (int i = nowI + 1; i < canLadder.size(); i++) {
		int ti = canLadder[i].first;
		int tj = canLadder[i].second;

		if (Chk(ti, tj)) {
			ladder[ti][tj] = 1;
			Sel(i, nowC + 1, maxI);
			ladder[ti][tj] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> h >> m;
	for (int i = 1; i <= h; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < n; j++) {
			if (Chk(i, j)) canLadder.push_back({ i,j });
		}
	}

	for (int i = 0; i <= 3; i++) {
		Sel(-1, 0, i);
		if (result) {
			resultN = i;
			break;
		}
	}

	cout << resultN;
}