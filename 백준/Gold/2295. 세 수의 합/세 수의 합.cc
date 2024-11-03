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
vector<int> arr;

bool Cal(int index) {
	int base = arr[index];

	for (int left = 1; arr[left] <= base / 3; left++) {
		int tmp1 = base - arr[left];
		for (int right = index - 1; right >= left; right--) {
			if (arr[right] >= tmp1)continue;
			
			if (binary_search(arr.begin(), arr.end(), tmp1 - arr[right]))return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	arr.push_back(0);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int i = n; i >= 1; i--) {
		if (Cal(i)) {
			cout << arr[i];
			break;
		}
	}
}