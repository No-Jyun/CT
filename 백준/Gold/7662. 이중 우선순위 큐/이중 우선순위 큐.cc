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

map<int, int> q;
int t, k, n;
char ins;

void PopN(int num) {
	if (q.empty())return;

	auto it = q.begin();
	if (num == 1) it = --q.end();

	if (q[it->first] == 1)q.erase(it);
	else q[it->first]--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> k;
		q.clear();

		while (k--) {
			cin >> ins >> n;

			if (ins == 'I') {
				auto it = q.insert({ n,1 });
				if (!it.second)q[n]++;
			}
			else PopN(n);
		}

		if (q.empty())cout << "EMPTY";
		else {
			cout << (--q.end())->first << ' ' << q.begin()->first;
		}
		cout << '\n';
	}
}