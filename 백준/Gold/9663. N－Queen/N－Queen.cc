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

int n, result;
int chessboard[16][16];

int row[16], column[16];

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= n;
}

bool Chk(int a, int b) {
	if (row[a] || column[b] )return false;

	for (int i = 1; i <= a; i++) {
		if (Range(a - i, b - i) && chessboard[a - i][b - i])return false;
		if (Range(a - i, b + i) && chessboard[a - i][b + i])return false;
	}
	return true;
}

void Queen(int p, int queenN) {
	if (!queenN) { result++; return; }
	if (p == n)return;

	int nowI = p + 1;

	for (int i = 1; i <= n; i++) {
		if (Chk(nowI, i)) {
			chessboard[nowI][i] = 1;
			row[nowI] = 1;
			column[i] = 1;

			Queen(nowI, queenN - 1);
			chessboard[nowI][i] = 0;
			row[nowI] = 0;
			column[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	Queen(0, n);
	cout << result;
}