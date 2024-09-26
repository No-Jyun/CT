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

ULL comb[2001][2001];
int n, result;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	comb[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		comb[i][0] = 1;
		comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			comb[i][j] %= 1000000007;
		}
	}

	int o = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '>')o++;
		else {
			for (int j = 0; j < o && i + j < n; j++) {
				if (s[i + j] == '<') {
					int ap = i - j - 1;
					int dyui = n - (i + j) - 1;
					result += comb[ap + dyui][ap];
					result %= 1000000007;
				}
				else break;
			}
			o = 0;
		}
	}
	cout << result;
}