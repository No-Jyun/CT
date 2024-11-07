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

int arr[4000000];
int n, k, t;

bool Range(int a) {
	return a >= 0 && a <= 100000;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	fill(arr, arr + 400000, -2);
	priority_queue<pair<int, int>> q;
	arr[n] = -1;
	q.push({ 0,n });
	while (!q.empty()) {
		int nowN = q.top().second;
		int nowT = -q.top().first;
		q.pop();

		t = nowT;
		if (nowN == k)break;

		int tmpN = nowN + 1;
		if (Range(tmpN) && arr[tmpN] == -2) {
			arr[tmpN] = nowN;
			q.push({ -nowT - 1,tmpN });
		}

		tmpN = nowN - 1;
		if (Range(tmpN) && arr[tmpN] == -2) {
			arr[tmpN] = nowN;
			q.push({ -nowT - 1,tmpN });
		}

		tmpN = nowN * 2;
		if (Range(tmpN) && arr[tmpN] == -2) {
			arr[tmpN] = nowN;
			q.push({ -nowT - 1,tmpN });
		}
	}

	stack<int> stk;
	int i = k;
	while (arr[i] != -1) {
		stk.push(i);
		i = arr[i];
	}
	stk.push(i);
	cout << t << '\n';
	while (!stk.empty()) {
		cout << stk.top() << ' ';
		stk.pop();
	}
}