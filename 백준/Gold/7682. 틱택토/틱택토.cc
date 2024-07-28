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

char arr[4][4];
int numX, numO;
string s;

bool ChkO() {
	for (int i = 1; i <= 3; i++) {
		if (arr[i][i] == 'O') {
			bool width = true;
			bool height = true;
			bool diag = true;

			if (i == 1) {
				for (int j = 1; j <= 3; j++) {
					if (arr[i][j] != 'O')width = false;
					if (arr[j][i] != 'O')height = false;
					if (arr[j][j] != 'O')diag = false;
				}
				if (width || height || diag)return true;
			}
			if (i == 2) {
				for (int j = 1; j <= 3; j++) {
					if (arr[i][j] != 'O')width = false;
					if (arr[j][i] != 'O')height = false;
					if (arr[j][4 - j] != 'O')diag = false;
				}
				if (width || height || diag)return true;
			}
			if (i == 3) {
				for (int j = 1; j <= 3; j++) {
					if (arr[i][j] != 'O')width = false;
					if (arr[j][i] != 'O')height = false;
				}
				if (width || height)return true;
			}
		}
	}
	return false;
}

bool ChkX() {
	for (int i = 1; i <= 3; i++) {
		if (arr[i][i] == 'X') {
			bool width = true;
			bool height = true;
			bool diag = true;

			if (i == 1) {
				for (int j = 1; j <= 3; j++) {
					if (arr[i][j] != 'X')width = false;
					if (arr[j][i] != 'X')height = false;
					if (arr[j][j] != 'X')diag = false;
				}
				if (width || height || diag)return true;
			}
			if (i == 2) {
				for (int j = 1; j <= 3; j++) {
					if (arr[i][j] != 'X')width = false;
					if (arr[j][i] != 'X')height = false;
					if (arr[j][4 - j] != 'X')diag = false;
				}
				if (width || height || diag)return true;
			}
			if (i == 3) {
				for (int j = 1; j <= 3; j++) {
					if (arr[i][j] != 'X')width = false;
					if (arr[j][i] != 'X')height = false;
				}
				if (width || height)return true;
			}
		}
	}
	return false;
}

bool Check() {
	if (numX < numO)return false;
	if (numX - numO > 1)return false;
	if (numX <= 2 && numO <= 2)return false;

	bool chkX = ChkX();
	bool chkO = ChkO();
	if (numX == 3) {
		if (numO == 3) { // O 승리
			if (!chkX && chkO)return true;
		}
		else {			// X 승리
			if (chkX)return true;
		}
	}
	if (numX == 4) {
		if (numO == 4) { // O 승리
			if (!chkX && chkO)return true;
		}
		else {			// X 승리
			if (!chkO && chkX)return true;
		}
	}
	if (numX == 5) {	// X 승리 or 판 꽉참
		if (!chkO && chkX)return true;
		else if (!chkO && !chkX)return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> s;
		if (s == "end")break;

		numX = 0;
		numO = 0;
		for (int i = 0; i < 9; i++) {
			arr[(i / 3) + 1][(i % 3) + 1] = s[i];
			if (s[i] == 'X')numX++;
			if (s[i] == 'O')numO++;
		}

		if (Check())cout << "valid" << "\n";
		else cout << "invalid" << '\n';
	}
}