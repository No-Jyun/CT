#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n, m, stP, endP;
vector<pair<int, int>> path[1001];
int dp[1001];
bool chk[1001];

int main() {
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		path[a].push_back({ b,c });
	}
	cin >> stP >> endP;

	fill(dp, dp + 1001, -1);
	dp[stP] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ 0,stP });

	while (!q.empty()) {
		int nowP = q.top().second;
		q.pop();
		
		if(!chk[nowP]){
			chk[nowP] = 1;

			for (auto it : path[nowP]) {
				if (dp[it.first] == -1 || dp[it.first] > dp[nowP] + it.second) {
					dp[it.first] = dp[nowP] + it.second;
					q.push({ dp[it.first],it.first });
				}
			}
		}
	}
	cout << dp[endP];
}