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

int n;
pair<int, int> conv[101];
bool convChk[101];
int stI, stJ;
int finishI, finishJ;

bool Chk(pair<int, int> from, pair<int, int> to) {
	int distanceI = abs(to.first - from.first);
	int distanceJ = abs(to.second - from.second);

	return distanceI + distanceJ <= 1000;
}

void BFS() {
	queue <pair<int, int>> q;
	q.push({ stI,stJ });
	bool canwin = false;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		if (Chk(now, { finishI,finishJ })) {
			canwin = true;
			break;
		}

		for (int i = 1; i <= n; i++) {
			if (!convChk[i] && Chk(now,conv[i])) {
				q.push({ conv[i] });
				convChk[i] = true;
			}
		}
	}
	cout << (canwin ? "happy" : "sad") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> stI >> stJ;
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			conv[i] = { a,b };
		}
		cin >> finishI >> finishJ;

		BFS();
		fill(convChk, convChk + 101, false);
	}
}