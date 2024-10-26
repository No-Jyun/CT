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

int n;
int arr[501][501];
int chk[501][501];
int result = 1;
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
priority_queue<pair<int, pair<int, int>>> sortedQ;

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

void BFS(int i, int j) {
	int d = 0;
	while (d < 4) {
		int tmpI = i + mI[d];
		int tmpJ = j + mJ[d];

		if (Range(tmpI, tmpJ) && arr[tmpI][tmpJ] > arr[i][j]) {
			chk[i][j] = max(chk[i][j], chk[tmpI][tmpJ] + 1);
		}
		d++;
	}
	if (!chk[i][j])chk[i][j] = 1;
	result = max(result, chk[i][j]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			sortedQ.push({ arr[i][j],{i,j} });
		}
	}

	while (!sortedQ.empty()) {
		BFS(sortedQ.top().second.first, sortedQ.top().second.second);
		sortedQ.pop();
	}

	cout << result;
}