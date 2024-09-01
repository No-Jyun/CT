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
int arr[100001];
int minS = INTMAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	int left = 1, right = n;
	while (left < right) {
		int sum = arr[left] + arr[right];

		if (abs(sum) == 0) {
			minS = 0;
			break;
		}

		if (abs(sum) < abs(minS)) {
			minS = sum;
		}

		if (sum < 0)left++;
		else right--;
	}
	cout << minS;
}