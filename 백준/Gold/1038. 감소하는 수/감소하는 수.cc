#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <tuple>
#include <math.h>
using namespace std;

int n;
int index = 9;
queue<string> q;

void Go() {
	while (!q.empty()) {
		string nowN = q.front();
		q.pop();
		int lastN = nowN[nowN.size() - 1] - '0';

		for (int i = 0; i <= 9 && lastN > i; i++) {
			index++;
			q.push(nowN + to_string(i));

			if (index == n) {
				cout << nowN + to_string(i);
				return;
			}
		}
	}
	cout << -1;
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n <= 9) { cout << n; }
	else {
		for (int i = 1; i <= 9; i++)q.push(to_string(i));

		Go();
	}
}