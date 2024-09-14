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

int r, c, k;
int arr[101][101];
int tmp[101];
int colI = 3, rowI = 3;

void R() {
	int exI = colI;

	for (int i = 1; i <= rowI; i++) {
		fill(tmp, tmp + 101, 0);

		for (int j = 1; j <= exI; j++)tmp[arr[i][j]]++;
		vector<pair<int, int>> v;
		for (int j = 1; j <= 100; j++) {
			if (tmp[j]) v.push_back({ tmp[j],j });
		}
		sort(v.begin(), v.end());

		int index = 1;
		for (int j = 0; j < v.size() && index < 100; j++) {
			arr[i][index++] = v[j].second;
			arr[i][index++] = v[j].first;
		}
		colI = max(colI, index - 1);

		while (index <= colI)arr[i][index++] = 0;
	}
}

void C() {
	int exI = rowI;

	for (int i = 1; i <= colI; i++) {
		fill(tmp, tmp + 101, 0);

		for (int j = 1; j <= exI; j++)tmp[arr[j][i]]++;
		vector<pair<int, int>> v;
		for (int j = 1; j <= 100; j++) {
			if (tmp[j]) v.push_back({ tmp[j],j });
		}
		sort(v.begin(), v.end());

		int index = 1;
		for (int j = 0; j < v.size() && index < 100; j++) {
			arr[index++][i] = v[j].second;
			arr[index++][i] = v[j].first;
		}
		rowI = max(rowI, index - 1);

		while (index <= rowI)arr[index++][i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++)cin >> arr[i][j];
	}
	int t = 0;

	while (arr[r][c] != k) {
		t++;
		if (t == 101)break;

		if (rowI >= colI)R();
		else C();
	}

	if (t == 101)cout << -1;
	else cout << t;
}