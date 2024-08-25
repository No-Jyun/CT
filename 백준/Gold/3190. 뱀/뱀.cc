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

int n, k, l;
int board[101][101];
pair<int, char> dirOrder[101];
vector<pair<int, int>> course;
int dirIndex = 1;
int nowDir = 1;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

void isChangeDir(int nowT) {
	if (nowT == dirOrder[dirIndex].first) {
		if (dirOrder[dirIndex].second == 'L') {
			nowDir--;
			if (nowDir == -1)nowDir = 3;
		}

		else {
			nowDir++;
			nowDir %= 4;
		}

		dirIndex++;
	}
}

int MoveBam() {
	int t = 1;
	int tailIndex = 0;
	course.push_back({ 1,1 });
	int headI = 1;	int headJ = 1;

	while (t) {
		int tmpI = headI + mI[nowDir];
		int tmpJ = headJ + mJ[nowDir];

		if (!Range(tmpI, tmpJ)) break;

		if (board[tmpI][tmpJ] == 2)break;

		if (board[tmpI][tmpJ] == 1) {
			board[tmpI][tmpJ] = 2;
			course.push_back({ tmpI,tmpJ });
		}
		else {
			board[tmpI][tmpJ] = 2;
			course.push_back({ tmpI,tmpJ });
			board[course[tailIndex].first][course[tailIndex].second] = 0;
			tailIndex++;
		}
		headI = tmpI;
		headJ = tmpJ;

		isChangeDir(t);

		t++;
	}

	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}
	cin >> l;
	for (int i = 1; i <= l; i++) {
		cin >> dirOrder[i].first >> dirOrder[i].second;
	}
	board[1][1] = 2;

	cout << MoveBam();
}