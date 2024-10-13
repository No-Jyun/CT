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

string a, b, c;
int mlen;
int arr[101][101][101];

int ML(int ai, int bi, int ci) {
	int l = 0;
	if (ai == 0)return 0;
	for (int i = 0; i < bi; i++) {
		for (int j = 0; j < ci; j++) {
			l = max(l, arr[ai - 1][i][j]);
		}
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			for (int k = 0; k < c.length(); k++) {
				if (a[i] == b[j] && b[j] == c[k]) {
					int len = ML(i, j, k);
					arr[i][j][k] = len + 1;
				}
				else if (i != 0)arr[i][j][k] = arr[i - 1][j][k];
				mlen = max(mlen, arr[i][j][k]);
			}
		}
	}

	cout << mlen;
}