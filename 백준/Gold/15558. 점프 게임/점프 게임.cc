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

int n, k;
int arr[2][100001];
int chk[2][100001];
bool flag;

bool Range(int a) {
	return a >= 1 && a <= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < 2; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j + 1] = s[j] - '0';
		}
	}
	int offset[3] = { 1,-1,k };

	chk[0][1] = 1;
	queue<pair<int, int>> q;
	q.push({ 0,1 });

	while (!q.empty()) {
		int line = q.front().first;
		int index = q.front().second;
		int d = 0;
		q.pop();

		if (flag)break;

		if (index >= chk[line][index]) {
			while (d < 3) {
				int nextLine = line;
				int nextIndex = index + offset[d];

				if (nextIndex > n) {
					flag = true;
					break;
				}

				if (d == 2) {
					if (line)nextLine = 0;
					else nextLine = 1;
				}

				if (Range(nextIndex) && arr[nextLine][nextIndex] && !chk[nextLine][nextIndex]) {
					chk[nextLine][nextIndex] = chk[line][index] + 1;
					q.push({ nextLine,nextIndex });
				}
				d++;
			}
		}
	}
	if (flag)cout << 1;
	else cout << 0;
}