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
int arr[1000001];
int sumArr[1000001];
int result[1000001];
priority_queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sumArr[arr[i]]++;
	}
	
	for (int i = n; i >= 1; i--) {
		int nowN = arr[i];
		int nowS = sumArr[arr[i]];

		while(!q.empty()) {
			if (q.top().second <= nowS)q.pop();
			else break;
		}

		if (q.empty()) {
			result[i] = -1;
		}
		else {
			result[i] = arr[-q.top().first];
		}
		q.push({ -i,nowS });
	}

	for (int i = 1; i <= n; i++) cout << result[i] << ' ';
}