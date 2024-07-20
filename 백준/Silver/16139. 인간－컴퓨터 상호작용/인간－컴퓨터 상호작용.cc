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
int num[27][200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	
	int t;
	cin >> t;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; j <= 26; j++) {
			if (j == s[i] - 'a' + 1) {
				num[j][i + 1] = num[j][i] + 1;
			}
			else num[j][i + 1] = num[j][i];
		}
	}

	while (t--) {
		char target;
		int l, r;
		cin >> target >> l >> r;

		int answer = num[target - 'a' + 1][r + 1] - num[target - 'a' + 1][l];

		cout << answer << '\n';
	}
}