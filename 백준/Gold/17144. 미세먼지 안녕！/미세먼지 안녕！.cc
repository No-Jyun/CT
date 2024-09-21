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

int r, c, t, ans;
int arr[51][51];
int chk[51][51];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
pair<int, int> air[2];

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= r && b <= c;
}

void Spread() {
	copy(arr[0], arr[51], chk[0]);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] > 0) {
				int spc = 0;
				int d = 0;
				while (d < 4) {
					int tmpI = i + mI[d];
					int tmpJ = j + mJ[d];

					if (Range(tmpI, tmpJ) && arr[tmpI][tmpJ] != -1) {
						chk[tmpI][tmpJ] += arr[i][j] / 5;
						spc++;
					}

					d++;
				}
				chk[i][j] -= (arr[i][j] / 5) * spc;
			}
		}
	}
	copy(chk[0], chk[51], arr[0]);
}

void Absorb1() {
	queue<int> q;
	q.push(0);
	int i = air[0].first, j = air[0].second + 1;
	while (j <= c) {
		q.push(arr[i][j]);
		arr[i][j++] = q.front();
		q.pop();
	}
	j--;
	i--;
	while (i >= 1) {
		q.push(arr[i][j]);
		arr[i--][j] = q.front();
		q.pop();
	}
	i++;
	j--;
	while (j >= 1) {
		q.push(arr[i][j]);
		arr[i][j--] = q.front();
		q.pop();
	}
	j++;
	i++;
	while (i < air[0].first) {
		q.push(arr[i][j]);
		arr[i++][j] = q.front();
		q.pop();
	}
}

void Absorb2() {
	queue<int> q;
	q.push(0);
	int i = air[1].first, j = air[1].second + 1;
	while (j <= c) {
		q.push(arr[i][j]);
		arr[i][j++] = q.front();
		q.pop();
	}
	j--;
	i++;
	while (i <= r) {
		q.push(arr[i][j]);
		arr[i++][j] = q.front();
		q.pop();
	}
	i--;
	j--;
	while (j >= 1) {
		q.push(arr[i][j]);
		arr[i][j--] = q.front();
		q.pop();
	}
	j++;
	i--;
	while (i > air[1].first) {
		q.push(arr[i][j]);
		arr[i--][j] = q.front();
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == -1)air[1] = { i,j };
		}
	}
	air[0] = { air[1].first - 1,1 };

	int timestamp = 0;
	while (timestamp != t) {
		timestamp++;
		Spread();
		Absorb1();
		Absorb2();
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] > 0)ans += arr[i][j];
		}
	}
	cout << ans;
}