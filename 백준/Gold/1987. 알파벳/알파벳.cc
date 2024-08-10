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

int r, c;
int arr[21][21];
int chk[21][21];
bool alpahChk[26];
int result;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && a <= r && b >= 1 && b <= c;
}

void DFS(int nowI, int nowJ) {
	int d = 0;
	result = max(result, chk[nowI][nowJ]);

	while (d < 4) {
		int tmpI = nowI + mI[d];
		int tmpJ = nowJ + mJ[d];

		if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ] && !alpahChk[arr[tmpI][tmpJ]]) {
			alpahChk[arr[tmpI][tmpJ]] = 1;
			chk[tmpI][tmpJ] = chk[nowI][nowJ] + 1;
			DFS(tmpI, tmpJ);
			alpahChk[arr[tmpI][tmpJ]] = 0;
			chk[tmpI][tmpJ] = 0;
		}
		d++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= c; j++) {
			arr[i][j] = s[j - 1] - 'A';
		}
	}

	chk[1][1] = 1;
	alpahChk[arr[1][1]] = 1;
	DFS(1, 1);
	cout << result;
}