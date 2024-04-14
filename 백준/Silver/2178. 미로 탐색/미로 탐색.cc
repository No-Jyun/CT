#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
using namespace std;

bool chk[105][105];

struct move {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int n, m;
	cin >> n >> m;

	vector<string> v(n + 2);
	string k;
	for (int i = 0; i < 105; i++) { k.push_back('0'); }
	v[0] = k; v[n + 1] = k;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		s = "0" + s + "0";
		v[i] = s;
	}

	struct move d[4];
	d[0].x = 1;		d[0].y = 0;
	d[1].x = 0;		d[1].y = 1;
	d[2].x = -1;	d[2].y = 0;
	d[3].x = 0;		d[3].y = -1;

	queue<int> stk;
	stk.push(1); stk.push(1); stk.push(1);
	chk[1][1] = 1;

	int minR = 100000;
	while (!stk.empty()) {
		int i = stk.front(); stk.pop();
		int j = stk.front(); stk.pop();
		int result = stk.front(); stk.pop();
		int di = 0;

		while (di < 4) {
			int xi = i + d[di].x;
			int yj = j + d[di].y;

			if (xi == m && yj == n) { minR = min(result + 1, minR); break; }

			if (v[yj][xi] == '1' && !chk[yj][xi]) {
				chk[yj][xi] = 1;
				stk.push(xi); 
				stk.push(yj);
				stk.push(result + 1);
			}
			di++;
		}
	}
	cout << minR;
}