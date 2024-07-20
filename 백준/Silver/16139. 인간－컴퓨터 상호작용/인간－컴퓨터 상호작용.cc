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

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	
	int t;
	cin >> t;
	while (t--) {
		char target;
		int l, r;
		cin >> target >> l >> r;

		int answer = count(s.begin() + l, s.begin() + r + 1, target);

		cout << answer << '\n';
	}
}