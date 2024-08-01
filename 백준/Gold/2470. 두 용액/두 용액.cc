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
vector<int> v;
int maxD = 0;
int maxU = 0;
int result = 2100000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	v.push_back(-2000000000);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	int left = 1;
	int right = n;
	while (left < right) {
		int sum = v[left] + v[right];
		
		if (abs(sum) < result) {
			result = abs(sum);
			maxD = left;
			maxU = right;
		}

		if (sum == 0)break;
		if (sum > 0)right--;
		if (sum < 0)left++;
	}
	cout << v[maxD] << ' ' << v[maxU];
}