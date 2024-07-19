#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

string s;
int modular = 1000000;

long long dp[5001];

int main() {
	cin >> s;

	if (s[0] == '0') {
		cout << 0;
		return 0;
	}

	dp[1] = 1;
	int nowN = (s[0] - '0') * 10 + (s[1] - '0');
	if (nowN >= 10 && nowN <= 26) dp[0] = 1;

	for (int i = 1; i < s.size(); i++) {
		bool trig1 = false;
		bool trig2 = false;

		nowN = s[i] - '0';
		if (nowN) {
			dp[i + 1] += dp[i];
			dp[i + 1] %= modular;
		}
		else trig1 = true;

		nowN = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (nowN >= 10 && nowN <= 26) {
			dp[i + 1] += dp[i - 1];
			dp[i + 1] %= modular;
		}
		else trig2 = true;

		if (trig1 && trig2) {
			cout << 0;
			return 0;
		}
	}
	cout << dp[s.size()];
}