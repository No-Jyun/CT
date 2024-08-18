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

int n, k;
vector<int> v;
bool chk[10001];
priority_queue <pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	if (v.size() <= k) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < v.size(); i++) {
		q.push({ v[i] - v[i - 1],i });
	}
	chk[0] = 1;
	int kk = 1;
	while (kk++ < k) {
		chk[q.top().second] = 1;
		q.pop();
	}

	int sum = 0;
	int ex = 0;
	for (int i = 1; i < v.size(); i++) {
		if (chk[i]) {
			sum += v[i - 1] - v[ex];
			ex = i;
		}
		else if (i == v.size() - 1) {
			sum += v[i] - v[ex];
		}
	}
	cout << sum;
}