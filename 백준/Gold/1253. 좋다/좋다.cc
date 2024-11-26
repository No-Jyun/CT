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

int arr[2001];
int n, result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n; i++) {
		int l = 1, r = n;

		if (i == 1)l++;
		if (i == n)r--;

		while (l < r) {
			int k = arr[l] + arr[r];
			if (k == arr[i]) {
				result++;
				break;
			}
			if (k > arr[i]) {
				do {
					r--;
				} while (r == i);
			}
			else {
				do {
					l++;
				} while (l == i);
			}
		}
	}

	cout << result;
}