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
#define LL long long
#define INTMAX 2147483647
using namespace std;

int n, m;
int stP, enP;
vector<LL> result;
LL chk[1001];
vector<pair<int, int>> edges[1001];

void BFS() {
	priority_queue<vector<LL>> q;
	chk[stP] = 0;
	q.push({ 0,stP });

	while (!q.empty()) {
		vector<LL> tmp = q.top();
		int nowI = tmp[tmp.size() - 1];
		LL nowC = -tmp[0];
		q.pop();

		if (nowC != chk[nowI])continue;

		for (int i = 0; i < edges[nowI].size(); i++) {
			int tmpI = edges[nowI][i].first;
			LL tmpC = nowC + edges[nowI][i].second;

			if (chk[tmpI] > tmpC) {
				chk[tmpI] = tmpC;
				vector<LL> forPush = tmp;
				forPush[0] = -tmpC;
				forPush.push_back(tmpI);

				if (tmpI == enP) {
					result = forPush;
				}
				else q.push(forPush);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}
	cin >> stP >> enP;

	result.push_back(9999999999999);
	fill(chk, chk + n + 1, 9999999999999);
	BFS();
	cout << -result[0] << '\n';
	cout << result.size() - 1 << '\n';
	for (int i = 1; i < result.size(); i++)cout << result[i] << ' ';
}