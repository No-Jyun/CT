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

vector<int> v[10001];
int arr[10001];
int n, result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, c;
		cin >> a >> c;
		v[i] = { a,c };

		for (int j = 1; j <= c; j++) {
			int m;
			cin >> m;
			v[i].push_back(m);
		}
	}

	arr[1] = v[1][0];
	result = arr[1];

	for (int i = 2; i <= n; i++) {
		int c = v[i][1];
		int tm = 0;

		for (int j = 1; j <= c; j++)tm = max(arr[v[i][1 + j]], tm);
		arr[i] = v[i][0] + tm;

		result = max(result, arr[i]);
	}

	cout << result;
}