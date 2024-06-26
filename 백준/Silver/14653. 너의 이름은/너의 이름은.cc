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

int n, k, q;
pair<int, char> message[10001];
int person[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k >> q;

	for (int i = 1; i <= k; i++) {
		cin >> message[i].first >> message[i].second;
	}

	if (!message[q].first) {
		cout << -1;
	}
	else {
		person[1] = 1;
		bool isChange = false;
		for (int i = q; i >= 1; i--) {
			if (message[i].first != message[q].first) {
				isChange = true;
				q = i + 1;
				break;
			}
		}
		if (!isChange)q = 1;

		for (int i = q; i <= k; i++) {
			person[message[i].second - 'A' + 1] = 1;
		}

		for (int i = 1; i <= n; i++) {
			if (!person[i]) {
				char tmp = i + 'A' - 1;
				cout << tmp << ' ';
			}
		}
	}
}