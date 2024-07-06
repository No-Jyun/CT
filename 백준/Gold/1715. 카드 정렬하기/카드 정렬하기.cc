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

priority_queue<int, vector<int>, greater<int>> q;
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		q.push(a);
	}

	while (q.size() != 1) {
		int t1 = q.top(); q.pop();
		int t2 = q.top(); q.pop();

		result += (t1 + t2);
		q.push(t1 + t2);
	}

	cout << result;
}