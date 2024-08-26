#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <tuple>
#include <math.h>
using namespace std;

int n, s;
int arr[100001];
int sum[100001];
int minL = 999999999;
bool oneFlag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];

		if (arr[i] >= s)oneFlag = true;
	}

	if (sum[n] < s) {
		cout << 0;
		return 0;
	}

	if (oneFlag) {
		cout << 1;
		return 0;
	}

	int left = 1, right = 1;
	while (right <= n && left <= right) {
		int nowSum = sum[right] - sum[left - 1];

		if (nowSum >= s) {
			minL = min(minL, right - left + 1);
			left++;
		}
		else {
			right++;
		}
	}

	cout << minL;
}