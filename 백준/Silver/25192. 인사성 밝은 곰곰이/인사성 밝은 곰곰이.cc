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

	int n;
	cin >> n;

	long long emoji = 0;
	map<string, bool> m;
	while (n--) {
		string s;
		cin >> s;

		if (s == "ENTER") {
			m.clear();
		}

		else {
			auto it = m.find(s);

			if (it == m.end()) {
				m.insert({ s,true });
				emoji++;
			}
		}
	}
	cout << emoji;
}