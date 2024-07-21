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

int n;
int arr[1001];
int incr[1001];
int decr[1001];
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		int maxim = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) maxim = max(maxim, incr[j] + 1);
		}
		incr[i] = maxim;
	}

	for (int i = 1; i <= n; i++) {
		int tmp = 0;

		for (int j = i; j <= n; j++) {
			int minim = 1;
			for (int k = i; k < j; k++) {
				if (arr[j] < arr[k])minim = max(minim, decr[k] + 1);
			}
			decr[j] = minim;
			tmp = max(tmp, decr[j]);
		}

		result = max(result, incr[i] + tmp - 1);
	}

	cout << result;
}