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

int n;
vector<int> v[9];

bool Judge(int s) {
	for (int i = 2; i <= sqrt(s); i++) {
		if (!(s % i)) return false;
	}
	return true;
}

void MakeV(int nowN) {
	for (int i = 0; i < v[nowN - 1].size(); i++) {
		for (int j = 1; j <= 9; j++) {
			if (Judge(v[nowN - 1][i] * 10 + j)) {
				v[nowN].push_back(v[nowN - 1][i] * 10 + j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	v[1] = { 2,3,5,7 };
	int nowN = 1;

	while (nowN != n) {
		nowN++;
		MakeV(nowN);
	}

	for (int i = 0; i < v[nowN].size(); i++) {
		cout << v[nowN][i] << '\n';
	}
}