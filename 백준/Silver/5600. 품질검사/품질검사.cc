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

int a, b, c;
int chk[301];
vector<int> v[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(chk, chk + 301, 2);
	cin >> a >> b >> c;

	int m;
	cin >> m;
	for (int x = 0; x < m; x++) {
		int i, j, k, r;
		cin >> i >> j >> k >> r;
		v[x] = { r,i,j,k };
	}

	sort(&v[0], &v[m]);

	for (int x = m - 1; x >= 0; x--) {
		if (v[x][0] == 1) {
			for (int i = 1; i <= 3; i++)chk[v[x][i]] = 1;
		}
		else {
			if (chk[v[x][1]] == 1 && chk[v[x][2]] == 1)chk[v[x][3]] = 0;
			else if (chk[v[x][1]] == 1 && chk[v[x][3]] == 1)chk[v[x][2]] = 0;
			else if (chk[v[x][3]] == 1 && chk[v[x][2]] == 1)chk[v[x][1]] = 0;
		}
	}

	for (int i = 1; i <= a + b + c; i++) {
		cout << chk[i] << '\n';
	}
}