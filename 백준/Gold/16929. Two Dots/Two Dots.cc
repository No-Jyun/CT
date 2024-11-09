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

int n, m;
int arr[51][51];
int chk[51][51];
int tmp[51][51];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
bool result = false;

bool Range(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= m;
}

void DFS(int i, int j) {
	if (result)return;

	fill(tmp[0], tmp[51], 0);
	tmp[i][j] = 1;
	stack<pair<int, int>> stk;
	stk.push({ i,j });

	while (!stk.empty()) {
		int nowI = stk.top().first;
		int nowJ = stk.top().second;
		stk.pop();

		chk[nowI][nowJ] = 1;

		for (int d = 0; d < 4; d++) {
			int tmpI = nowI + mI[d];
			int tmpJ = nowJ + mJ[d];

			if (Range(tmpI, tmpJ) && arr[nowI][nowJ] == arr[tmpI][tmpJ]) {
				if (chk[tmpI][tmpJ]) {
					if (tmp[nowI][nowJ] - tmp[tmpI][tmpJ] >= 3) {
						result = true;
						return;
					}
				}
				else {
					tmp[tmpI][tmpJ] = tmp[nowI][nowJ] + 1;
					stk.push({ tmpI,tmpJ });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = s[j - 1] - 'A';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!chk[i][j])DFS(i, j);
			if (result)break;
		}
		if (result)break;
	}

	if (result)cout << "Yes";
	else cout << "No";
}