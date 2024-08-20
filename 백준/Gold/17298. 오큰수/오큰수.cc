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
int arr[1000001];
int nge[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; 
	for (int i = 1; i <= n; i++)cin >> arr[i];

	stack<int> stk;
	for (int i = 1; i <= n; i++) {
		if (!stk.empty()){
			while (!stk.empty()) {
				int nowN = arr[stk.top()];
				if (arr[i] > nowN) {
					nge[stk.top()] = arr[i];
					stk.pop();
				}
				else break;
			}
		}
		stk.push(i);
	}

	while (!stk.empty()) {
		nge[stk.top()] = -1;
		stk.pop();
	}

	for (int i = 1; i <= n; i++)cout << nge[i] << ' ';
}