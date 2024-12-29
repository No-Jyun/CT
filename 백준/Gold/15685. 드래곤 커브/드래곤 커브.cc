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

int n, x, y, d, g;
int dragon[101][101];
int order[2500];

pair<int, int> Dir(int d) {
	switch (d)
	{
	case 0:
		return { 1,0 };
	case 1:
		return { 0,-1 };
	case 2:
		return { -1,0 };
	default:
		return { 0,1 };
	}
}

void M(int index) {
	int dir = order[index];
	x += Dir(dir).first;
	y += Dir(dir).second;
	dragon[x][y] = 1;
}

void DragonCurve() {
	dragon[x][y] = 1;
	int i = 1;
	order[i++] = d;
	M(1);
	if (!g)return;
	order[i++] = (order[1] + 1) % 4;
	M(2);
	int t = 1;
	while (t < g) {
		for (int j = i - 1; j >= 1; j--) {
			order[i] = (order[j] + 1) % 4;
			M(i);
			i++;
		}
		t++;
	}
}

bool Chk(int i, int j) {
	if (!dragon[i][j])return false;
	if (!dragon[i + 1][j])return false;
	if (!dragon[i][j + 1])return false;
	if (!dragon[i + 1][j + 1])return false;
	return true;
}

int F() {
	int c = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (Chk(i, j))c++;
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> d >> g;
		DragonCurve();
	}
	cout << F();
}