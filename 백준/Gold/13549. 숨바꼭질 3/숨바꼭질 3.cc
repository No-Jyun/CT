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
using namespace std;

int stP, endP;
int t[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> stP >> endP;
	
	fill(t, t + 100001, 999999);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 1,stP });
	t[stP] = 1;

	while (!q.empty()) {
		int nowP = q.top().second;
		q.pop();

		if (nowP) {
			for (int i = nowP; i <= 100000; i *= 2) {
				if (t[i] > t[nowP]) {
					t[i] = t[nowP];
					q.push({ t[i],i });
				}
			}
		}

		if (nowP + 1 <= 100000 && t[nowP + 1] > t[nowP] + 1) {
			t[nowP + 1] = t[nowP] + 1;
			q.push({ t[nowP + 1],nowP + 1 });
		}

		if (nowP - 1 >= 0 && t[nowP - 1] > t[nowP] + 1) {
			t[nowP - 1] = t[nowP] + 1;
			q.push({ t[nowP - 1],nowP - 1 });
		}
	}
	cout << t[endP] - 1;
}