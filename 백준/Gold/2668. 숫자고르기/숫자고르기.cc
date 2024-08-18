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
int arr[101];
bool chk[101];
int maxN;

void DFS(int index) {
	stack<int> stk;
	stk.push(arr[index]);

	while (!stk.empty()) {
		if (stk.top() == index) {
			while (!stk.empty()) {
				chk[stk.top()] = 1;
				maxN++;
				stk.pop();
			}
			return;
		}

		if (chk[stk.top()])return;
		if (stk.size() >= n)return;

		stk.push(arr[stk.top()]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		
		if (i == arr[i]) {
			maxN++;
			chk[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!chk[i])DFS(i);
	}
	cout << maxN << '\n';
	for (int i = 1; i <= n; i++)
		if (chk[i])cout << i << '\n';
}