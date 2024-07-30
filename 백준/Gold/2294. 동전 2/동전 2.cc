#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n, k;
int value[101];
int money[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
		if (value[i] <= 10000)q.push({ value[i],1 });
	}
	fill(money, money + 10001, 999999999);

	while (!q.empty()) {
		int nowM = q.front().first;
		int nowC = q.front().second;
		q.pop();

		if (money[nowM] > nowC) {
			money[nowM] = nowC;

			for (int i = 1; i <= n; i++) {
				int tmpM = nowM + value[i];

				if (tmpM <= k)q.push({ tmpM,nowC + 1 });
			}
		}
	}
	if (money[k] != 999999999) cout << money[k];
	else cout << -1;
}