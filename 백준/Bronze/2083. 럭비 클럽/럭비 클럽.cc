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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string s;
		int a, b;

		cin >> s >> a >> b;
		if (s == "#")break;

		if (a > 17 || b >= 80)cout << s << ' ' << "Senior" << '\n';
		else cout << s << ' ' << "Junior" << '\n';
	}
}