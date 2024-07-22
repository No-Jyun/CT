#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n, m;
int chk[101];
int snake[101];
int ladder[101];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a] = b;
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		snake[a] = b;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,1 });

	while (!q.empty()) {
		int now = q.top().second;
		int t = q.top().first;
		q.pop();

		if (now == 100) {
			cout << t;
			break;
		}

		if(!chk[now]){
			chk[now] = t;

			for (int i = 1; i <= 6; i++) {
				int goHere = now + i;

				if (goHere <= 100 && !chk[goHere]) {
					if (snake[goHere]) {
						q.push({ t + 1, snake[goHere] });
					}

					if (ladder[goHere]) {
						q.push({ t + 1, ladder[goHere] });
					}

					if (!snake[goHere] && !ladder[goHere])q.push({ t + 1,goHere });
				}
			}
		}
	}
}