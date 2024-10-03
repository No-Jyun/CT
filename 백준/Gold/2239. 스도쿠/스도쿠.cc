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

int sudoku[10][10];
int stX, stY;
bool trig = false;

pair<int, int> Range(int a, int b) {
	if (a <= 3 && b <= 3)return { 1,1 };
	if (a <= 3 && b <= 6)return { 1,4 };
	if (a <= 3 && b <= 9)return { 1,7 };
	if (a <= 6 && b <= 3)return { 4,1 };
	if (a <= 6 && b <= 6)return { 4,4 };
	if (a <= 6 && b <= 9)return { 4,7 };
	if (a <= 9 && b <= 3)return { 7,1 };
	if (a <= 9 && b <= 6)return { 7,4 };
	if (a <= 9 && b <= 9)return { 7,7 };
}

void Print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++)cout << sudoku[i][j];
		cout << '\n';
	}
}

void Go(int nowI, int nowJ) {
	if (trig) return;

	if (nowI > 9) {
		Print();
		trig = true;
		return;
	}

	if (nowJ > 9)return Go(nowI + 1, 1);
	if (sudoku[nowI][nowJ])return Go(nowI, nowJ + 1);

	bool chk[10] = { 0, };
	for (int i = 1; i <= 9; i++) {
		chk[sudoku[i][nowJ]] = 1;
		chk[sudoku[nowI][i]] = 1;
	}

	pair<int, int> t = Range(nowI, nowJ);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			chk[sudoku[t.first + i][t.second + j]] = 1;
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (!chk[i]) {
			sudoku[nowI][nowJ] = i;
			Go(nowI, nowJ + 1);
			sudoku[nowI][nowJ] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 9; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= 9; j++) {
			sudoku[i][j] = s[j - 1] - '0';
			if (!sudoku[i][j] && !stX && !stY) {
				stX = i; stY = j;
			}
		}
	}

	Go(stX, stY);
}