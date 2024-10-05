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

int a, b;
bool chk[10000];

int D(int n) {
	return (2 * n) % 10000;
}

int S(int n) {
	if (n)return n - 1;
	else return 9999;
}

int L(int n) {
	n *= 10;
	if (n >= 10000) {
		n += n / 10000;
		n %= 10000;
	}
	return n;
}

int R(int n) {
	int t = n % 10;
	n /= 10;
	n += t * 1000;
	return n;
}

void BFS() {
	queue<pair<int, string>> q;
	q.push({ a,""});
	chk[a] = 1;

	while (!q.empty()) {
		int nowN = q.front().first;
		string nowS = q.front().second;
		q.pop();

		if (nowN == b) {
			cout << nowS << '\n';
			return;
		}

		int tmp = D(nowN);
		if (!chk[tmp]) {
			chk[tmp] = 1;
			q.push({ tmp,nowS + "D" });
		}
		tmp = S(nowN);
		if (!chk[tmp]) {
			chk[tmp] = 1;
			q.push({ tmp,nowS + "S" });
		}
		tmp = L(nowN);
		if (!chk[tmp]) {
			chk[tmp] = 1;
			q.push({ tmp,nowS + "L" });
		}
		tmp = R(nowN);
		if (!chk[tmp]) {
			chk[tmp] = 1;
			q.push({ tmp,nowS + "R" });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;

		BFS();
		fill(chk, chk + 10000, 0);
	}
}