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

int n, result;
vector<pair<int, int>> edges[10001];
int chk[10001];

void BFS(int index) {
	fill(chk, chk + n + 1, -1);
	chk[index] = 0;
	queue<int> q;
	q.push(index);
	
	while (!q.empty()) {
		int nowI = q.front();
		q.pop();

		result = max(result, chk[nowI]);

		for (int i = 0; i < edges[nowI].size(); i++) {
			if (chk[edges[nowI][i].first] == -1) {
				chk[edges[nowI][i].first] = chk[nowI] + edges[nowI][i].second;
				q.push(edges[nowI][i].first);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) {
		BFS(i);		
	}
	cout << result;
}