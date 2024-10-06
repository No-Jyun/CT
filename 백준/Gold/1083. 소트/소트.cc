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

int n, s;
int arr[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> s;

	int index = 1;
	while (s > 0 && index <= n) {
		int maxN = 0, maxIndex = 0;
		for (int i = 1; i <= s && index + i <= n; i++) {
			if (arr[index + i] > maxN) {
				maxN = arr[index + i];
				maxIndex = index + i;
			}
		}

		if (maxN > arr[index]) {
			for (int i = maxIndex; i > index; i--) {
				arr[i] = arr[i - 1];
			}
			arr[index] = maxN;
			s -= maxIndex - index;
			index++;
		}
		else index++;
	}

	for (int i = 1; i <= n; i++)cout << arr[i] << ' ';
}