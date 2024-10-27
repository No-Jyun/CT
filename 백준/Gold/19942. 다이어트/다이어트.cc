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

int n, mp, mf, md, mv;
int protein[16], fat[16], drug[16], vitamin[16], cost[16];
int pick[16];
bool chk[16];
priority_queue<vector<int>> q;

void Cal(int c) {
	vector<int> v(5, 0), tmp(16, 0);
	for (int i = 1; i <= c; i++) {
		int index = pick[i];
		v[0] += cost[index];
		v[1] += protein[index];
		v[2] += fat[index];
		v[3] += drug[index];
		v[4] += vitamin[index];
		tmp[i] = -index;
	}
	if (v[1] >= mp && v[2] >= mf && v[3] >= md && v[4] >= mv) {
		tmp[0] = -v[0];
		q.push(tmp);
	}
}

void Choose(int c, int index, int pindex) {
	if (c < pindex) {
		Cal(c);
		return;
	}

	for (int i = index + 1; i <= n; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			pick[pindex] = i;
			Choose(c, i, pindex + 1);
			chk[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> mp >> mf >> md >> mv;
	for (int i = 1; i <= n; i++) {
		cin >> protein[i] >> fat[i] >> drug[i] >> vitamin[i] >> cost[i];
	}

	for (int i = 1; i <= n; i++) {
		Choose(i, 0, 1);
	}

	if (q.empty())cout << -1 << '\n';
	else {
		vector<int> t = q.top();
		cout << -t[0] << '\n';
		for (int i = 1; i < t.size() && t[i]; i++)cout << -t[i] << ' ';
	}
}