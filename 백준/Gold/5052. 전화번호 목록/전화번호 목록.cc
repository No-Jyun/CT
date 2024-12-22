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

int n;
string arr[10001];
map<string, int> m;

bool C() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= arr[i].size(); j++) {
			string t = arr[i].substr(0, j);
			
			if (m[t])return false;
			if (j == arr[i].size())m[t]++;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> arr[i];
		sort(arr, arr + n + 1);

		if (C())cout << "YES" << '\n';
		else cout << "NO" << '\n';
		m.clear();
	}
}