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
#define MAX 3999999979
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	if (n == 0) { cout << 0; return 0; }

	int cutN = floor(n * 0.15 + 0.5);
	int sum = 0;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		sum += a;
	}
	sort(v.begin(), v.end());

	int startI = 0, endI = n - 1;
	for (int i = 0; i < cutN; i++) {
		sum -= (v[startI + i] + v[endI - i]);
	}
	cout << (int)floor((double)sum / (n - 2 * cutN) + 0.5);
}