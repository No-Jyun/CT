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

int n, k;
int chk[2][21];
int energy[2][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> energy[0][i] >> energy[1][i];
	}
	cin >> k;

	fill(chk[0], chk[2], 999999999);
	chk[0][1] = 0;
	chk[0][2] = energy[0][1];
	chk[0][3] = energy[1][1];
	chk[1][4] = k;
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= 3; j++) {
			int tmp = i + j;
			if (tmp <= n) {
				if (j == 3) chk[1][tmp] = min(chk[1][tmp], chk[0][i] + k);
				else {
					chk[0][tmp] = min(chk[0][tmp], chk[0][i] + energy[j - 1][i]);
					chk[1][tmp] = min(chk[1][tmp], chk[1][i] + energy[j - 1][i]);
				}
			}
		}
	}

	cout << min(chk[0][n], chk[1][n]);
}