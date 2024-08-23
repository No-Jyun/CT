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
vector<int> v[101];
int chk[101];
int minA, minB, minResult = 2000000000;

void BFS(int i, int j) {
	chk[i] = 0;	chk[j] = 0;
	queue<int> q;
	q.push(i);	q.push(j);
	int sum = 0;

	while (!q.empty()) {
		int nowP = q.front();
		q.pop();

		for (int k = 0; k < v[nowP].size(); k++) {
			if (chk[v[nowP][k]] == -1) {
				chk[v[nowP][k]] = chk[nowP] + 1;
				sum += chk[nowP] + 1;
				q.push(v[nowP][k]);
			}
		}
	}

	if (sum < minResult) {
		minResult = sum;
		minA = i;
		minB = j;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			fill(chk, chk + 101, -1);
			BFS(i, j);
		}
	}
	cout << minA << ' ' << minB << ' ' << minResult * 2;
}