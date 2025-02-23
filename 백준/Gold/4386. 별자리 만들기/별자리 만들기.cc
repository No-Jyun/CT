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

int n;
pair<double, double> arr[101];
priority_queue<pair<double, int>> q;
int chk[101];
double result;

double L(int a, int b) {
	double aa = pow(arr[a].first - arr[b].first, 2);
	double bb = pow(arr[a].second - arr[b].second, 2);
	return aa + bb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
		if (i != 1)q.push({ -L(1,i),i });
	}

	chk[1] = 1;
	while (!q.empty()) {
		double len = -q.top().first;
		int to = q.top().second;
		q.pop();

		if (chk[to])continue;
		chk[to] = 1;
		result += sqrt(len);

		for (int i = 1; i <= n; i++) {
			if (!chk[i]) {
				q.push({ -L(to,i),i });
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << result;
}