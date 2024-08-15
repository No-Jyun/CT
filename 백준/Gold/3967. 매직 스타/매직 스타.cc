#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <tuple>
#include <math.h>
using namespace std;

int arr[6][10];
int chk[13];
pair<int, int> offset[12] = {
	{1,5},{2,2},{2,4},{2,6},{2,8},{3,3},{3,7},{4,2},{4,4},{4,6},{4,8},{5,5}
};
bool flag;

int chkArr[6][4] = {
	{0,2,5,7},{1,2,3,4},{0,3,6,10},{1,5,8,11},{4,6,9,11},{7,8,9,10}
};// 점 좌측   가로 1    점 우측   아래 좌측   아래 우측   가로 2

bool Checking(int index) {
	int sum = 0;
	int chkIndex = 0;

	switch (index)
	{
	case 4:		// 처음 가로
		chkIndex = 1;
		for (int i = 0; i < 4; i++) {
			sum += arr[offset[chkArr[chkIndex][i]].first][offset[chkArr[chkIndex][i]].second];
		}
		if (sum == 26)return true;
		else return false;

	case 7:		// 중->좌측 아래 대각선
		chkIndex = 0;
		for (int i = 0; i < 4; i++) {
			sum += arr[offset[chkArr[chkIndex][i]].first][offset[chkArr[chkIndex][i]].second];
		}
		if (sum == 26)return true;
		else return false;

	case 10:	// 두번째 가로, 중->우측 아래 대각선
		chkIndex = 2;
		for (int i = 0; i < 4; i++) {
			sum += arr[offset[chkArr[chkIndex][i]].first][offset[chkArr[chkIndex][i]].second];
		}
		if (sum != 26)return false;

		sum = 0;
		chkIndex = 5;
		for (int i = 0; i < 4; i++) {
			sum += arr[offset[chkArr[chkIndex][i]].first][offset[chkArr[chkIndex][i]].second];
		}
		if (sum != 26)return false;

		return true;

	case 11:	// 마지막 점으로 모이는 대각선 2개
		chkIndex = 3;
		for (int i = 0; i < 4; i++) {
			sum += arr[offset[chkArr[chkIndex][i]].first][offset[chkArr[chkIndex][i]].second];
		}
		if (sum != 26)return false;

		sum = 0;
		chkIndex = 4;
		for (int i = 0; i < 4; i++) {
			sum += arr[offset[chkArr[chkIndex][i]].first][offset[chkArr[chkIndex][i]].second];
		}
		if (sum != 26)return false;

		return true;

	case 12:
		for (int i = 0; i < 6; i++) {
			sum = 0;
			for (int j = 0; j < 4; j++) {
				sum += arr[offset[chkArr[i][j]].first][offset[chkArr[i][j]].second];
			}
			if (sum != 26)return false;
		}
		return true;

	default:
		return true;
	}
}

void DFS(int index) {
	if (index == 12) {
		if (Checking(index)) {
			for (int i = 1; i <= 5; i++) {
				for (int j = 1; j <= 9; j++) {
					if (!arr[i][j]) cout << '.';
					else cout << (char)(arr[i][j] + 'A' - 1);
				}
				cout << '\n';
			}
			flag = true;
		}
		return;
	}

	int nowI = offset[index].first;
	int nowJ = offset[index].second;

	if (!arr[nowI][nowJ]) {
		for (int i = 1; i <= 12; i++) {
			if (!chk[i]) {
				arr[nowI][nowJ] = i;

				if (Checking(index)) {
					chk[i] = 1;
					DFS(index + 1);
					chk[i] = 0;
				}
				arr[nowI][nowJ] = 0;
			}

			if (flag)return;
		}
	}
	else DFS(index + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 5; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= 9; j++) {
			if (s[j - 1] != '.' && s[j - 1] != 'x') {
				arr[i][j] = s[j - 1] - 'A' + 1;
				chk[s[j - 1] - 'A' + 1] = 1;
			}
		}
	}

	DFS(0);
}