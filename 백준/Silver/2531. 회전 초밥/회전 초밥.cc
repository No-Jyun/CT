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

int n, d, k, c;
int maxim;

void Start(int* arr, int index, vector<bool> chk) {
	for (int j = 0; j < k; j++) {
		int nowN = index + j;
		if (nowN > n) {
			nowN -= n;
		}
		chk[arr[nowN]] = 1;
	}
	int tmp = count(chk.begin(), chk.end(), true);
	maxim = max(maxim, tmp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> d >> k >> c;

	vector<bool> chk(d + 1);
	chk[c] = 1;

	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		Start(arr, i, chk);
		if (maxim == k + 1)break;
	}
	cout << maxim;
}