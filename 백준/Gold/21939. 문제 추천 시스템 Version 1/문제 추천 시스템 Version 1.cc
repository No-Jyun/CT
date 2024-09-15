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

int n, p, l, m;
string s;
map<int, int> qListP;
map<pair<int, int>, int> qListL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p >> l;
		qListP.insert({ p,l });
		qListL.insert({ { l,p } ,p });
	}
	cin >> m;

	auto tmp = qListP.begin();
	auto k = qListL.begin();

	while (m--) {
		cin >> s >> p;

		switch (s[0])
		{
		case 'r':
			k = qListL.begin();
			if (p == 1)k = --qListL.end();
			cout << k->second << '\n';

			break;
		case 'a':
			cin >> l;
			qListP.insert({ p,l });
			qListL.insert({ { l,p },p });

			break;
		default:
			tmp = qListP.find(p);
			while (tmp != qListP.end()) {
				qListL.erase({ tmp->second,p });
				qListP.erase(tmp);
				tmp = qListP.find(p);
			}

			break;
		}
	}
}