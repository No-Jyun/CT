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

int n, a;
int arr[101];
vector<int> v;

int GCD(int aa, int bb) {
	if (aa > bb)swap(aa, bb);

	while (bb % aa != 0) {
		int t = aa;
		aa = bb % t;
		bb = t;
	}
	return aa;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n + 1);

	a = arr[2] - arr[1];
	for (int i = 3; i <= n; i++) {
		a = min(a, GCD(a, arr[i] - arr[i - 1]));
	}

	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			v.push_back(i);
			if (a / i != i) v.push_back(a / i);
		}
	}
	v.push_back(a);
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)cout << v[i] << ' ';
}