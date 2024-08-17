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

int n, h, t;
int tI;
priority_queue<int> q;

bool TryH() {
	while (tI < t) {
		int nowH = q.top();

		if (nowH < h)return true;

		if (nowH >= h) {
			if (nowH != 1)nowH /= 2;
			tI++;
		}

		q.pop();
		q.push(nowH);
	}

	if (q.top() < h)return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> h >> t;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	if (TryH()) {
		cout << "YES" << '\n' << tI;
	}
	else {
		cout << "NO" << '\n' << q.top();
	}
}