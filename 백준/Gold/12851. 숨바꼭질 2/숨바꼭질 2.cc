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

int arr[400000], arrt[400000];
int n, k;

bool Range(int a) {
	return a >= 0 && a <= 100000;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	queue<int> q;
	arr[n] = 1;
	arrt[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int nowN = q.front();
		q.pop();

		int tmpN = nowN + 1;
		if (Range(tmpN)) {
			if (!arr[tmpN]) {
				arr[tmpN] = arr[nowN];
				arrt[tmpN] = arrt[nowN] + 1;
				q.push(tmpN);
			}
			else if (arrt[tmpN] == arrt[nowN] + 1)arr[tmpN] += arr[nowN];
		}

		tmpN = nowN - 1;
		if (Range(tmpN)) {
			if (!arr[tmpN]) {
				arr[tmpN] = arr[nowN];
				arrt[tmpN] = arrt[nowN] + 1;
				q.push(tmpN);
			}
			else if (arrt[tmpN] == arrt[nowN] + 1)arr[tmpN] += arr[nowN];
		}

		tmpN = nowN * 2;
		if (Range(tmpN)) {
			if (!arr[tmpN]) {
				arr[tmpN] = arr[nowN];
				arrt[tmpN] = arrt[nowN] + 1;
				q.push(tmpN);
			}
			else if (arrt[tmpN] == arrt[nowN] + 1)arr[tmpN] += arr[nowN];
		}
	}

	cout << arrt[k] << '\n' << arr[k];
}