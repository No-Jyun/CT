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

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int n, k;
	cin >> n >> k;
	if (n == k) { cout << 0; return 0; }

	queue<int> q;
	q.push(n);
	while (!arr[k]) {
		int nowP = q.front(); q.pop();
		int nowT = arr[nowP];

		if (nowP + 1 <= 100000 && !arr[nowP + 1]) { q.push(nowP + 1); arr[nowP + 1] = nowT + 1; }
		if (nowP * 2 <= 100000 && !arr[nowP * 2]) { q.push(nowP * 2); arr[nowP * 2] = nowT + 1; }
		if (nowP - 1 >= 0  && !arr[nowP - 1]) { q.push(nowP - 1); arr[nowP - 1] = nowT + 1; }
	}
	cout << arr[k];
}