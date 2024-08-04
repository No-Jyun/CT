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
int arr[100001];
int result = 2100000000;
int maxL;
int maxR;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	int low = 1;
	int high = n;
	while (low < high) {
		int sum = arr[low] + arr[high];

		if (result > abs(sum)) {
			result = abs(sum);
			maxL = arr[low];
			maxR = arr[high];
		}

		if (sum == 0)break;
		if (sum > 0)high--;
		if (sum < 0)low++;
	}
	cout << maxL << ' ' << maxR;
}