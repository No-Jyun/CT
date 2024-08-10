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
int modular = 1000000000;
int maxN = 0;
int arr[1000001];
vector<int> v;
int indexTimes = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr[1] = 1;
	arr[2] = 2;
	int addSum = 2;
	v.push_back(2);
	int times = 0;
	for (int i = 4; i <= n; i += 2) {
		arr[i] = arr[i - 2] + addSum;
		arr[i] %= modular;

		if (times == 1) {
			addSum += v[maxN];
			addSum %= modular;
			v.push_back(addSum);

			if (indexTimes == 1) {
				maxN++;
				indexTimes = 0;
			}
			else indexTimes++;

			times = 0;
		}
		else times++;
	}

	if (n != 1 && n % 2)n--;
	cout << arr[n];
}