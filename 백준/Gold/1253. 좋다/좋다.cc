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

map<int, int> m;
int arr[2001];
int n, result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		m[arr[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int k = arr[i] + arr[j];

			bool isCal = false;
			if (k == arr[i] && k == arr[j]) {
				if (m[k] > 2) isCal = true;
			}
			else if (k == arr[i] || k == arr[j]) {
				if (m[k] > 1) isCal = true;
			}
			else if (m[k]) isCal = true;

			if (isCal) {
				result += m[k];
				m[k] = 0;
			}
		}
	}

	cout << result;
}