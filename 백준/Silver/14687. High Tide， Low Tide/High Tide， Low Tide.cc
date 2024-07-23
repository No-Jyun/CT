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
int arr[101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	if (n == 1) {
		cout << arr[1];
		return 0;
	}

	sort(arr, arr + n + 1);
	int index = n / 2;
	if (n % 2)index++;
	int manIndex = index + 1;
	while (manIndex <= n) {
		cout << arr[index--] << ' ' << arr[manIndex++] << ' ';
	}
	if (index)cout << arr[index];
}