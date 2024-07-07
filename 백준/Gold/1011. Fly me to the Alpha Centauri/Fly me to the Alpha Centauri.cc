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

int stP, finP;
long long arr[46350];

void Judge(int distance) {
	if (distance == 1) {
		cout << 1 << '\n';
		return;
	}

	for (int i = 2; i < 46350; i++) {
		if (distance > arr[i - 1] - (i - 1) && distance <= arr[i - 1]) {
			cout << (i - 1) * 2 << '\n';
			return;
		}
		else if (distance > arr[i - 1] && distance <= arr[i] - i) {
			cout << (i - 1) * 2 + 1 << '\n';
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < 46350; i++) {
		arr[i] = arr[i - 1] + i * 2;
	}

	int t;
	cin >> t;
	while (t--) {
		cin >> stP >> finP;
		Judge(finP - stP);
	}
}