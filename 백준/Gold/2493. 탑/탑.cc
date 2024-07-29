#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n;
int tower[500001];
int result[500001];
stack<int> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> tower[i];

	stk.push(n);
	for (int j = n - 1; j >= 1; j--) {
		while (!stk.empty() && tower[stk.top()] <= tower[j]) {
			result[stk.top()] = j;
			stk.pop();
		}
		stk.push(j);
	}

	while (!stk.empty()) {
		result[stk.top()] = 0;
		stk.pop();
	}

	for (int i = 1; i <= n; i++)cout << result[i] << ' ';
}