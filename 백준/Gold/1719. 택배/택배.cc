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
vector<pair<int, int>> edges[201];
int way[201][201];
int chk[201];

void BFS(int stI) {
	priority_queue<vector<int>> q;
	q.push({ 0,stI });
	chk[stI] = 0;

	while (!q.empty()) {
		vector<int> tmp = q.top();
		q.pop();
		int nowI = tmp[tmp.size() - 1];
		int nowC = -tmp[0];

		for (int i = 0; i < edges[nowI].size(); i++) {
			vector<int> tmpV = tmp;
			int tmpC = nowC + edges[nowI][i].second;
			int tmpI = edges[nowI][i].first;

			if (chk[tmpI] == -1) {
				tmpV[0] = -tmpC;
				tmpV.push_back(tmpI);
				chk[tmpI] = tmpC;
				way[stI][tmpI] = tmpV[2];
				q.push(tmpV);
			}
			else if (chk[tmpI] > tmpC) {
				tmpV[0] = -tmpC;
				tmpV.push_back(tmpI);
				chk[tmpI] = tmpC;
				way[stI][tmpI] = tmpV[2];
				q.push(tmpV);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) {
		fill(chk, chk + n + 1, -1);
		BFS(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)cout << '-' << ' ';
			else cout << way[i][j] << ' ';
		}
		cout << '\n';
	}
}