#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n;
int arr[1001][1001];
int num[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	if (n == 2) {
		cout << arr[1][2] / 2 << ' ' << arr[1][2] / 2;
		return 0;
	}

	int sum = 0;
	for (int i = 1; i <= n; i++)sum += arr[1][i];

	for (int i = n; i >= 2; i -= 2) {
		sum -= arr[i][i - 1];
	}

	int divN = 0;
	(n - 1) % 2 ? divN = n - 2 : divN = n - 1;
	
	num[1] = sum / divN;
	for (int i = 2; i <= n; i++)num[i] = arr[1][i] - num[1];
	for (int i = 1; i <= n; i++)cout << num[i] << ' ';
}