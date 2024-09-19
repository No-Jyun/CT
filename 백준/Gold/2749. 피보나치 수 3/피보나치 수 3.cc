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
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;

	int* arr = new int[1500005];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	if (n <= 2) { cout << arr[n]; return 0; }

	long long k = 3;
	while (k <= 1500000) {
		arr[k] = (arr[k - 1] + arr[k - 2]) % 1000000;

		k++;
	}

	cout << arr[n % 1500000];
}