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

int n, a;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		
		if (arr.empty())arr.push_back(a);
		else {
			int lastN = arr[arr.size() - 1];

			if (a > lastN)arr.push_back(a);
			else {
				auto it = lower_bound(arr.begin(), arr.end(), a);
				arr[it - arr.begin()] = a;
			}
		}
	}

	cout << n - arr.size();
}