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
string a, b, c;
bool chkA[205][405];
bool chkB[205][405];
bool flag;

void DFS(int iA, int iB, int iC) {
	if (iC == c.length() || flag) {
		flag = true;
		return;
	}

	if (chkA[iA][iC])return;
	if (chkB[iB][iC])return;

	chkA[iA][iC] = 1;
	chkB[iB][iC] = 1;

	if (a[iA] == c[iC])DFS(iA + 1, iB, iC + 1);
	if (b[iB] == c[iC])DFS(iA, iB + 1, iC + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;

		a.push_back('0');
		b.push_back('0');
		fill(chkA[0], chkA[205], false);
		fill(chkB[0], chkB[205], false);
		flag = false;
		DFS(0, 0, 0);

		cout << "Data set " << i << ": ";
		if (flag)cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}