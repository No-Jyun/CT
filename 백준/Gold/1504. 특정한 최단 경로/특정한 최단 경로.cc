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
#define INTMAX 2100000000
using namespace std;

int n, e;
int chk[801];
vector<pair<int, int>> edges[801];
int pass1, pass2;
int result = INTMAX;

void Wayto(int p1, int p2) {
	int sum = 0;

	fill(chk, chk + 801, INTMAX);
	priority_queue<pair<int, int>> q;
	q.push({ 0,1 });
	chk[1] = 0;

	while (!q.empty()) {
		int nowN = q.top().second;
		q.pop();

		for (int i = 0; i < edges[nowN].size(); i++) {
			int gotoN = edges[nowN][i].first;
			int cost = edges[nowN][i].second;

			if (gotoN != p2) {
				if (chk[gotoN] > chk[nowN] + cost) {
					chk[gotoN] = chk[nowN] + cost;
					q.push({ -chk[gotoN],gotoN });
				}
			}
		}
	}
	if (chk[p1] == INTMAX)return;
	sum = chk[p1];

	fill(chk, chk + 801, INTMAX);
	q.push({ -sum,p1 });
	chk[p1] = sum;

	while (!q.empty()) {
		int nowN = q.top().second;
		q.pop();

		for (int i = 0; i < edges[nowN].size(); i++) {
			int gotoN = edges[nowN][i].first;
			int cost = edges[nowN][i].second;

			if (chk[gotoN] > chk[nowN] + cost) {
				chk[gotoN] = chk[nowN] + cost;
				q.push({ -chk[gotoN],gotoN });
			}
		}
	}
	if (chk[p2] == INTMAX)return;
	sum = chk[p2];

	fill(chk, chk + 801, INTMAX);
	q.push({ -sum,p2 });
	chk[p2] = sum;

	while (!q.empty()) {
		int nowN = q.top().second;
		q.pop();

		for (int i = 0; i < edges[nowN].size(); i++) {
			int gotoN = edges[nowN][i].first;
			int cost = edges[nowN][i].second;

			if (chk[gotoN] > chk[nowN] + cost) {
				chk[gotoN] = chk[nowN] + cost;
				q.push({ -chk[gotoN],gotoN });
			}
		}
	}
	if (chk[n] == INTMAX)return;
	result = min(result, chk[n]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> e;
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}
	cin >> pass1 >> pass2;

	Wayto(pass1, pass2);
	Wayto(pass2, pass1);

	if (result == INTMAX)cout << -1;
	else cout << result;
}