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
using namespace std;

bool chk[10001] = { 0 };
int cnt = 0;
bool brk = false;

void start(queue<int>& q, stack<int>& stk, int& n) {
	if (stk.size() == n) {
		if (cnt == 1) { 
			brk = true;
			
			stack<int> tmp;
			while (!stk.empty()) { tmp.push(stk.top()); stk.pop(); }
			while (!tmp.empty()) { cout << tmp.top() << ' '; tmp.pop(); }

			return;
		}
		else { cnt++; }
	}

	if (q.empty()) {
		for (int i = n; i >= 1; i--) {
			if (!chk[i]) {
				chk[i] = true;
				stk.push(i);
				start(q, stk, n);
				if (brk)return;
				chk[i] = false;
				stk.pop();
			}
		}
	}
	else {
		for (int i = q.front(); i >= 1; i--) {
			if (!q.empty()) { q.pop(); }

			if (!chk[i]) {
				chk[i] = true;
				stk.push(i);
				start(q, stk, n);
				if (brk)return;
				chk[i] = false;
				stk.pop();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n;
	cin >> n;
	queue<int> q;
	stack<int> res;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	for (int i = q.front(); i >= 1; i--) {
		if (!q.empty()) { q.pop(); }

		chk[i] = true;
		res.push(i);
		start(q, res, n);
		if (brk)break;
		chk[i] = false;
		res.pop();
	}
	if (!brk) { cout << -1; }
}