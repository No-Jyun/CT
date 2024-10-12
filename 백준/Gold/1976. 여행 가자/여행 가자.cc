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
bool way[201][201];
bool chk[201];
bool canGo[201][201];
int plan[1001];

void BFS(int index) {
	queue<int> q;
	q.push(index);
	chk[index] = 1;

	while (!q.empty()) {
		int nowI = q.front();
		q.pop();

		canGo[index][nowI] = 1;

		for (int i = 1; i <= n; i++) {
			if (way[nowI][i] && !chk[i]) {
				chk[i] = 1;
				q.push(i);
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
		for (int j = 1; j <= n; j++)cin >> way[i][j];
	}
	for (int i = 1; i <= m; i++)cin >> plan[i];

	for (int i = 1; i <= n; i++) {
		BFS(i);
		fill(chk, chk + n + 1, 0);
	}

	for (int i = 2; i <= m; i++) {
		if (!canGo[plan[i - 1]][plan[i]]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}