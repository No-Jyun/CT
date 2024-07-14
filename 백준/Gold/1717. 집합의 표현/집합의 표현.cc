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

int n, m;
int arr[1000001];

int FindP(int n) {
	if (arr[n] == n)return n;
	return arr[n] = FindP(arr[n]);
}

void Union(int a, int b) {
	a = FindP(a);
	b = FindP(b);

	if (a != b) {
		if (a < b)arr[b] = a;
		else arr[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) arr[i] = i;

	while (m--) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c) {
			if (FindP(a) == FindP(b))cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else Union(a, b);
	}
}