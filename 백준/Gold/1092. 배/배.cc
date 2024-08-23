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

int n, m;
int crane[51];
int box[10001];
int chk[10001];
queue<int> q;
int maxT;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> crane[i];
	cin >> m;
	for (int i = 1; i <= m; i++)cin >> box[i];
	sort(crane, crane + n + 1);
	sort(box, box + m + 1);

	if (crane[n] < box[m]) {
		cout << -1;
		return 0;
	}

	int nIndex = n;
	for (int i = m; i >= 1; i--) {
		if (box[i] <= crane[nIndex]) {
			chk[i] = 1;
			q.push(i);
			nIndex--;
		}
		if (!nIndex) break;
	}

	while (!q.empty()) {
		int nowB = q.front();
		q.pop();

		maxT = max(maxT, chk[nowB]);
		for (int i = nowB - 1; i >= 1; i--) {
			if (!chk[i]) {
				chk[i] = chk[nowB] + 1;
				q.push(i);
				break;
			}
		}
	}
	cout << maxT;
}