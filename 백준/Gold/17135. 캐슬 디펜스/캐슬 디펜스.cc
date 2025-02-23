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
#define LL long long
#define INTMAX 2147483647
using namespace std;

int n, m, d;
int castle[16][16];
int castleSimul[16][16];
int bow[4];
pair<int, int> bowT[4];
int result;

bool CSE() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (castleSimul[i][j])return false;
		}
	}
	return true;
}

void Cal() {
	copy(castle[0], castle[16], castleSimul[0]);
	for (int i = 1; i <= 3; i++)bowT[i] = { -1,-1 };
	int enemy = 0;

	while (!CSE()) {
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= m; j++) {
				if (castleSimul[i][j]) {
					for (int x = 1; x <= 3; x++) {
						int len = abs(n + 1 - i) + abs(bow[x] - j);

						if (len <= d) {
							if (bowT[x].first == -1) {
								bowT[x] = { i,j };
							}
							else {
								int exlen = abs(n + 1 - bowT[x].first) + abs(bow[x] - bowT[x].second);
								if (len < exlen) {
									bowT[x] = { i,j };
								}
								else if (len == exlen && j < bowT[x].second) {
									bowT[x] = { i,j };
								}
							}
						}
					}
				}
			}
		}

		for (int i = 1; i <= 3; i++) {
			if (bowT[i].first == -1)continue;
			
			int toI = bowT[i].first;
			int toJ = bowT[i].second;
			if (castleSimul[toI][toJ]) {
				enemy++;
				castleSimul[toI][toJ] = 0;
			}
			bowT[i] = { -1,-1 };
		}

		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= m; j++) {
				if (i == 1)castleSimul[i][j] = 0;
				else {
					castleSimul[i][j] = castleSimul[i - 1][j];
				}
			}
		}
	}

	result = max(result, enemy);
}

void D(int index, int bN) {
	if (bN == 4) {
		Cal();
		return;
	}

	for (int i = index + 1; i <= m; i++) {
		bow[bN] = i;
		D(i, bN + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)cin >> castle[i][j];
	}

	D(0, 1);
	cout << result;
}