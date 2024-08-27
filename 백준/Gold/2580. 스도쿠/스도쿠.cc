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

int sudoku[10][10];
int sudokurule[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9}
};
pair<int, int> offset[10] = {
	{0,0}, { 1,1 },{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}
};
vector<pair<int, int>> blank;
bool isWin;
bool chk[10];

void Print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++)cout << sudoku[i][j] << ' ';
		cout << '\n';
	}
}

void FillInBlank(int blankIndex) {
	if (blankIndex == blank.size()) {
		Print();
		isWin = true;
		return;
	}

	fill(chk, chk + 10, 0);
	vector<int> canNum;
	int nowI = blank[blankIndex].first;
	int nowJ = blank[blankIndex].second;

	for (int i = 1; i <= 9; i++) {
		chk[sudoku[i][nowJ]] = 1;
		chk[sudoku[nowI][i]] = 1;
	}

	int ruleI = offset[sudokurule[nowI][nowJ]].first;
	int ruleJ = offset[sudokurule[nowI][nowJ]].second;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)chk[sudoku[ruleI + i][ruleJ + j]] = 1;
	}

	for (int i = 1; i <= 9; i++) {
		if (!chk[i]) 
			canNum.push_back(i);
	}

	for (int i = 0; i < canNum.size(); i++) {
		sudoku[nowI][nowJ] = canNum[i];
		FillInBlank(blankIndex + 1);

		if (isWin)return;
	}
    sudoku[nowI][nowJ] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> sudoku[i][j];
			if (!sudoku[i][j])blank.push_back({ i,j });
		}
	}

	FillInBlank(0);
}