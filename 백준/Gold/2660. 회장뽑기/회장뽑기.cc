#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n;
vector<int> v[51];
int chk[51];
vector<int> result[51];
int minN = 100;

void BFS(int index) {
	queue<int> q;
	q.push(index);
	chk[index] = 1;

	int tmp = 0;
	while (!q.empty()) {
		int nowI = q.front();
		q.pop();

		tmp = max(tmp, chk[nowI]);
		for (int i = 0; i < v[nowI].size(); i++) {
			if (!chk[v[nowI][i]]) {
				chk[v[nowI][i]] = chk[nowI] + 1;
				q.push(v[nowI][i]);
			}
		}
	}
	minN = min(minN, tmp - 1);
	result[tmp - 1].push_back(index);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == b && b == -1)break;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		BFS(i);
		fill(chk, chk + n + 1, 0);
	}

	sort(result[minN].begin(), result[minN].end());
	cout << minN << ' ' << result[minN].size() << '\n';
	for (int i = 0; i < result[minN].size(); i++) {
		cout << result[minN][i] << ' ';
	}
}