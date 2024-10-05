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
int arr[51];
int a, b;

void Ans() {
	if (n == 1) {
		cout << 'A';
		return;
	}
	if (n == 2) {
		if (arr[1] == arr[2]) cout << arr[1];
		else cout << 'A';
		return;
	}

	if (arr[1] == arr[2]) {
		if (arr[2] == arr[3]) {
			for (int i = 4; i <= n; i++) {
				if (arr[i - 1] != arr[i]) {
					cout << 'B';
					return;
				}
			}
			cout << arr[n];
		}
		else cout << 'B';
		return;
	}

	if ((arr[3] - arr[2]) % (arr[2] - arr[1])) {
		cout << 'B';
		return;
	}

	a = (arr[3] - arr[2]) / (arr[2] - arr[1]);
	b = arr[2] - (arr[1] * a);

	for (int i = 2; i <= n; i++) {
		if (arr[i - 1] * a + b != arr[i]) {
			cout << 'B';
			return;
		}
	}

	cout << arr[n] * a + b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	Ans();
}