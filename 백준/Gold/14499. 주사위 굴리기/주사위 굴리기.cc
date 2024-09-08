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

int n, m, a, b, k, d;
int zido[20][20];
int mI[5] = { 0,0,0,-1,1 };
int mJ[5] = { 0,1,-1,0,0 };

struct Dice {
	int head = 0;
	int l[5] = { 0, };
	int r[4] = { 0, };

	Dice(){}

	void MoveD(int dir) {
		switch (dir)
		{
		case 1:
			r[0] = l[4];
			l[4] = r[3];
			r[3] = r[2]; r[2] = r[1]; r[1] = r[0];
			l[2] = r[2];
			break;
		case 2:
			r[0] = l[4];
			l[4] = r[1];
			r[1] = r[2]; r[2] = r[3]; r[3] = r[0];
			l[2] = r[2];
			break;
		case 3:
			l[0] = l[1];
			l[1] = l[2]; l[2] = l[3];
			l[3] = l[4]; l[4] = l[0];
			r[2] = l[2];
			break;
		default:
			l[0] = l[4];
			l[4] = l[3]; l[3] = l[2];
			l[2] = l[1]; l[1] = l[0];
			r[2] = l[2];
			break;
		}
		head = r[2];
	}
};

bool Range(int a, int b) {
	return a >= 0 && b >= 0 && a < n && b < m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> a >> b >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)cin >> zido[i][j];
	}

	Dice dice;
	dice.l[4] = zido[a][b];
	zido[a][b] = 0;

	for (int i = 1; i <= k; i++) {
		cin >> d;

		int tmpI = a + mI[d];
		int tmpJ = b + mJ[d];

		if (Range(tmpI, tmpJ)) {
			dice.MoveD(d);

			if (zido[tmpI][tmpJ]) {
				dice.l[4] = zido[tmpI][tmpJ];
				zido[tmpI][tmpJ] = 0;
			}
			else zido[tmpI][tmpJ] = dice.l[4];

			a = tmpI;
			b = tmpJ;

			cout << dice.head << '\n';
		}
	}
}