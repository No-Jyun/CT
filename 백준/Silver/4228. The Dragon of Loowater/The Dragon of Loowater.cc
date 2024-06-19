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

int n, m, result, tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (!n && !m)break;

		vector<int> dragon, knight;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			dragon.push_back(tmp);
		}
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			knight.push_back(tmp);
		}

		sort(dragon.begin(), dragon.end());
		sort(knight.begin(), knight.end());

		if (n > m)cout << "Loowater is doomed!" << '\n';
		else {
			int dIndex = 0, kIndex = 0;

			while (dIndex < n && kIndex < m) {
				if (dragon[dIndex] <= knight[kIndex++]) { 
					result += knight[kIndex - 1];
					dIndex++; 
				}
			}

			if (dIndex == n)cout << result << '\n';
			else cout << "Loowater is doomed!" << '\n';
		}
		result = 0;
	}
}