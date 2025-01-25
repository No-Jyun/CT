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

int n, l, result;
int road[101][101];
bool chk[101][101];

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

bool Garo(int nowI) {
	int nowJ = 1;
	int num = road[nowI][nowJ];

	while (nowJ <= n) {
		if (num == road[nowI][nowJ])nowJ++;
		else {
			if (abs(num - road[nowI][nowJ]) > 1)return false;

			if (num > road[nowI][nowJ]) {
				int sameNum = road[nowI][nowJ];
				bool isFlat = true;
				for (int i = 0; i < l && isFlat; i++) {
					if (Range(nowI, nowJ + i)&& !chk[nowI][nowJ + i] && sameNum == road[nowI][nowJ + i])continue;
					else isFlat = false;
				}
				if (!isFlat)return false;

				for (int i = 0; i < l; i++)chk[nowI][nowJ + i] = 1;
				nowJ += l;
				num = road[nowI][nowJ - 1];
			}
			else {
				int sameNum = road[nowI][nowJ - 1];
				bool isFlat = true;
				for (int i = 1; i <= l && isFlat; i++) {
					if (Range(nowI, nowJ - i) && !chk[nowI][nowJ - i] && sameNum == road[nowI][nowJ - i])continue;
					else isFlat = false;
				}
				if (!isFlat)return false;

				for (int i = 1; i <= l; i++)chk[nowI][nowJ - i] = 1;
				num = road[nowI][nowJ];
			}
		}
	}
	return true;
}

bool Sero(int nowJ) {
	int nowI = 1;
	int num = road[nowI][nowJ];

	while (nowI <= n) {
		if (num == road[nowI][nowJ])nowI++;
		else {
			if (abs(num - road[nowI][nowJ]) > 1)return false;

			if (num > road[nowI][nowJ]) {
				int sameNum = road[nowI][nowJ];
				bool isFlat = true;
				for (int i = 0; i < l && isFlat; i++) {
					if (Range(nowI + i, nowJ) && !chk[nowI + i][nowJ] && sameNum == road[nowI + i][nowJ])continue;
					else isFlat = false;
				}
				if (!isFlat)return false;

				for (int i = 0; i < l; i++)chk[nowI + i][nowJ] = 1;
				nowI += l;
				num = road[nowI - 1][nowJ];
			}
			else {
				int sameNum = road[nowI - 1][nowJ];
				bool isFlat = true;
				for (int i = 1; i <= l && isFlat; i++) {
					if (Range(nowI - i, nowJ) && !chk[nowI - i][nowJ] && sameNum == road[nowI - i][nowJ])continue;
					else isFlat = false;
				}
				if (!isFlat)return false;

				for (int i = 1; i <= l; i++)chk[nowI - i][nowJ] = 1;
				num = road[nowI][nowJ];
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)cin >> road[i][j];
	}
	
	for (int i = 1; i <= n; i++) {
		if (Garo(i)) {
			result++;
		}
	}
	fill(chk[0], chk[n + 1], 0);
	for (int i = 1; i <= n; i++) {
		if (Sero(i)) {
			result++;
		}
	}

	cout << result;
}