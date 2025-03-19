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
#define LL long long
#define INTMAX 2147483647
using namespace std;

int n;
vector<LL> arr;
vector<LL> minim(4);

void Cal(int index) {
	int l = index + 1;
	int r = n - 1;
	LL base = arr[index] + arr[l] + arr[r];

	vector<LL> tmpMin = { base, index, l, r };

	while (l < r) {
		if (abs(base) < abs(minim[0]))
			minim = tmpMin;

		if (base == 0) {
			return;
		}
		else if (base > 0) {
			base -= arr[r--];
			base += arr[r];
			tmpMin[3] = r;
		}
		else {
			base -= arr[l++];
			base += arr[l];
			tmpMin[2] = l;
		}
		tmpMin[0] = base;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		LL a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	minim[0] = 10000000000;

	for (int i = 0; i < n - 2; i++) {
		Cal(i);
	}

	for (int i = 1; i <= 3; i++)
		cout << arr[minim[i]] << ' ';
}