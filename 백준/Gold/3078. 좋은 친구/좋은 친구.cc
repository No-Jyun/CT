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

ULL n, k, result;
queue<int> q[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		q[s.length()].push(i);
	}

	for (int i = 2; i <= 20; i++) {
		queue<int> head;
		if (!q[i].empty()) {
			head.push(q[i].front());
			q[i].pop();

			while (!q[i].empty()) {
				if (q[i].front() - head.front() > k) {
					head.pop();

					if (head.empty()) {
						head.push(q[i].front());
						q[i].pop();
					}
				}
				else {
					result += head.size();
					head.push(q[i].front());
					q[i].pop();
				}
			}
		}
	}
	cout << result;
}